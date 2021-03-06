
// caromoiView.cpp : implementation of the CcaromoiView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "caromoi.h"
#endif

#include "caromoiDoc.h"
#include "caromoiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CcaromoiView

IMPLEMENT_DYNCREATE(CcaromoiView, CView)

BEGIN_MESSAGE_MAP(CcaromoiView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CcaromoiView construction/destruction

CcaromoiView::CcaromoiView() noexcept
{
	// TODO: add construction code here
	btn.text = "may di";
	btn.thietlap(600, 100, 700, 180);
	control = 1;
	player = 0;
	int i = 0, j = 0;
	for (i = 0; i< 10; i++)
		for (j = 0; j < 10; j++)
		{
			a[i][j].thietlap(100 + i * 50 , 100 + j * 50, 150 + i * 50 , 150 + j * 50);
			a[i][j].giatri = 0;
		}

}

CcaromoiView::~CcaromoiView()
{
}

BOOL CcaromoiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CcaromoiView drawing

void CcaromoiView::OnDraw(CDC* /*pDC*/)
{
	CcaromoiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC pdc(this);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			a[i][j].draw(&pdc);
	btn.draw(&pdc);
	// TODO: add draw code for native data here
}

void CcaromoiView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CcaromoiView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CcaromoiView diagnostics

#ifdef _DEBUG
void CcaromoiView::AssertValid() const
{
	CView::AssertValid();
}

void CcaromoiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CcaromoiDoc* CcaromoiView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CcaromoiDoc)));
	return (CcaromoiDoc*)m_pDocument;
}
#endif //_DEBUG


// CcaromoiView message handlers



void CcaromoiView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC pdc(this);
	if(control == 1)
	{
		if (btn.tronghinh(point) == 1)
		{
			CPoint tiep = buocditieptheo(cu.x,cu.y);
			if (tiep.x >= 0)
			{
				a[tiep.x][tiep.y].giatri = player + 1;
				a[tiep.x][tiep.y].drawchu(&pdc); // ve hinh ngay sau khi bấm
				if (kiemtrathang(tiep.x,tiep.y) == 1)//nếu thắng thì dừng và thông báo thắng
				{
					control = 0;
					AfxMessageBox(L"Thắng", MB_OK | MB_ICONHAND);
				}
				if (kiemtraditiep() == 0)
				{
					control = 0;
					AfxMessageBox(L"Hòa", MB_OK | MB_ICONSTOP);
				}
				cu.x = tiep.x;
				cu.y = tiep.y;
				player++;
				player = player % 2;
			}
			


			
		}
		else
		{
			for (int i = 0 ; i< 10; i++)
				for (int j = 0; j < 10; j++)
					if (a[i][j].tronghinh(point) == 1 && a[i][j].giatri == 0) //kiem tra trong hinh va gia tri = 0 tuc chua bam
					{
						a[i][j].giatri = player + 1;
						a[i][j].drawchu(&pdc); // ve hinh ngay sau khi bấm
						if (kiemtrathang(i,j) == 1)//nếu thắng thì dừng và thông báo thắng
						{
							control = 0;
							AfxMessageBox(L"Thắng", MB_OK | MB_ICONHAND);
						}
						if(kiemtraditiep() == 0)
						{
							control = 0;
							AfxMessageBox(L"Hòa", MB_OK | MB_ICONSTOP);
						}
						cu.x = i;
						cu.y = j;
						player++;
						player = player % 2;
					
					}
		}
	}
	CView::OnLButtonUp(nFlags, point);
}

int CcaromoiView::kiemtrathang(int I,int J)
{
	// TODO: Add your implementation code here.
	int i = I, j = J, dem1, dem2, dem3 , dem4;
	dem1= dem2= dem3 = dem4 = 0;
	//dem theo chieu ngang
	i = I;
	j = J;
	while (j >= 0 && a[i][j].giatri == player + 1)
	{
		dem1++;
		j--;
	}
	i = I;
	j = J+1;
	while (j < 10 && a[i][j].giatri == player + 1)
	{
		dem1++;
		j++;
	}
	//dem theo chieu doc
	i = I;
	j = J;
	while (i >= 0 && a[i][j].giatri == player + 1)
	{
		dem2++;
		i--;

	}
	i = I + 1;
	j = J;
	while (i < 10 && a[i][j].giatri == player + 1)
	{
		dem2++;
		i++;

	}
	i = I ;
	j = J;
	//duongcheo 1
	while (i >= 0 && j >= 0 && a[i][j].giatri == player + 1)
	{
		if (a[i][j].giatri == player + 1)
			dem3++;
		i--; 
		j--;
	}
	i = I + 1; 
	j = J + 1;
	while (i < 10 && j < 10 && a[i][j].giatri == player + 1)
	{
		if (a[i][j].giatri == player + 1)
			dem3++;
		i++; 
		j++;
	}
	i = I ; 
	j = J ;
	while (i >=0 && j < 10 && a[i][j].giatri == player + 1)
	{
		if (a[i][j].giatri == player + 1)
			dem4++;
		i--; 
		j++;
	}
	i = I + 1;
	j = J - 1; 
	while (i < 10 && j >=0 && a[i][j].giatri == player + 1)
	{
		if (a[i][j].giatri == player + 1)
			dem4++;
		i++; 
		j--;
	}
	if(dem1>=5||dem2>=5||dem3>=5||dem4>=5)
		return 1;
	else 
		return 0;
}
int CcaromoiView::kiemtraditiep()
{
	// TODO: Add your implementation code here.
	int kq = 1;
	int dem = 0;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (a[i][j].giatri != 0)
				dem++;
	if (dem == 100)// nếu tất cả các ô có giá trị đều khác 0 thì ko đi tiếp
		kq = 0;
	return kq;
	
}


CPoint CcaromoiView::buocditieptheo(int I, int J)
{
	// TODO: Add your implementation code here.
	CPoint kq;
	int lg[10][10];
	int i = 0; int j = 0;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
		{
			if (a[i][j].giatri != 0)
				lg[i][j] = -10000;
			else
				if (player == 0)
				{
					lg[i][j] = 3 * uocluongthang(i, j, I, J) + uocluongcan(i, j,I, J);
				}
				else
				{
					lg[i][j] = uocluongthang(i, j, I, J) + 3*uocluongcan(i, j, I, J);
				}
		}

	//tim gia tri max
	int im = 0, jm = 0, max = 0;
	max = lg[0][0];
	for (i = 0; i< 10; i++)
		for (j = 0; j < 10; j++)
		{
			if (max < lg[i][j])
			{
				max = lg[i][j];
				im = i;
				jm = j;
			}
		}
	if(max > - 10000)
		return CPoint(im,jm);
	else
		return CPoint(-1, -1);
}


int CcaromoiView::uocluongthang(int mi, int mj, int I, int J)
{
	// TODO: Add your implementation code here.
	int kq = 0;
	kq = tong4duong(mi,mj,player + 1) - abs(I -mi) - abs(J - mj);

	return kq;
}



int CcaromoiView::uocluongcan(int mi, int mj, int I, int J)
{
	// TODO: Add your implementation code here.
	int kq = 0;
	kq = tong4duong(mi,mj,(player + 1)%2 + 1) - abs(I - mi) - abs(J - mj);

	return kq;
}


int CcaromoiView::tong4duong(int I, int J,int loaico)
{
	// TODO: Add your implementation code here.
	int i = I, j = J, dem1, dem2, dem3, dem4;
	dem1 = dem2 = dem3 = dem4 = 0;
	int h1 = 0, h2 = 0, h3 = 0, h4 = 0;
	//dem theo chieu ngang
	i = I;
	j = J;
	while (j >= 0 && (a[i][j].giatri == loaico|| a[i][j].giatri == 0))
	{
		if(a[i][j].giatri == loaico)
			dem1++;
		
		h1++;
		j--;
	}
	i = I;
	j = J + 1;
	while (j < 10 && (a[i][j].giatri == loaico || a[i][j].giatri == 0))
	{
		if (a[i][j].giatri == loaico)
			dem1++;

		h1++;;
		j++;
	}
	//dem theo chieu doc
	i = I;
	j = J;
	while (i >= 0 && (a[i][j].giatri == loaico || a[i][j].giatri == 0))
	{
		if (a[i][j].giatri == loaico)
			dem2++;

		h2++;
		i--;

	}
	i = I + 1;
	j = J;
	while (i < 10 && (a[i][j].giatri == loaico || a[i][j].giatri == 0))
	{
		if (a[i][j].giatri == loaico)
			dem2++;

		h2++;
		i++;

	}
	i = I;
	j = J;
	//duongcheo 1
	while (i >= 0 && j >= 0 && (a[i][j].giatri == loaico || a[i][j].giatri == 0))
	{
		if (a[i][j].giatri == loaico)
			dem3++;

		h3++;
		i--;
		j--;
	}
	i = I + 1;
	j = J + 1;
	while (i < 10 && j < 10 && (a[i][j].giatri == loaico || a[i][j].giatri == 0))
	{
		if (a[i][j].giatri == loaico)
			dem3++;

		h3++;
		i++;
		j++;
	}
	i = I;
	j = J;
	while (i >= 0 && j < 10 && (a[i][j].giatri == loaico || a[i][j].giatri == 0))
	{
		if (a[i][j].giatri == loaico)
			dem4++;

		h4++;
		i--;
		j++;
	}
	i = I + 1;
	j = J - 1;
	while (i < 10 && j >= 0 && (a[i][j].giatri == loaico || a[i][j].giatri == 0))
	{
		if (a[i][j].giatri == loaico)
			dem4++;

		h4++;
		i++;
		j--;
	}
	if (dem1 >= 3 && h1 > 4)
		dem1 = dem1 * 100;
	if (dem2 >= 3 && h2 > 4)
		dem2 = dem2 * 100;
	if (dem3 >= 3 && h3 > 4)
		dem3 = dem3 * 100;
	if (dem4 >= 3 && h4 > 4)
		dem4 = dem4 * 100;

	if (dem1 >= 4 && h1 <=6)
		dem1 = dem1 * 10000;
	if (dem2 >= 4 && h2 <= 6)
		dem2 = dem2 * 10000;
	if (dem3 >= 4 && h3 <= 6)
		dem3 = dem3 * 10000;
	if (dem4 >= 4 && h4 <= 6)
		dem4 = dem4 * 10000;

	return dem1 + dem2 + dem3 + dem4;
}
