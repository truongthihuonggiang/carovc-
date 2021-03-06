
// caromoiView.h : interface of the CcaromoiView class
//

#pragma once
#include "Oco.h"
#include "Button.h"
class CcaromoiView : public CView
{
protected: // create from serialization only
	CcaromoiView() noexcept;
	DECLARE_DYNCREATE(CcaromoiView)

// Attributes
public:
	Button btn;
	int control;
	int player;
	Oco a[10][10];
	CPoint cu;
	CcaromoiDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CcaromoiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	int kiemtrathang(int x,int y);
	int kiemtraditiep();
	CPoint buocditieptheo(int I, int J);
	int uocluongthang(int mi, int mj, int I, int J);
	int uocluongcan(int mi, int mj, int I, int J);
	int tong4duong(int I, int J, int loaico);
};

#ifndef _DEBUG  // debug version in caromoiView.cpp
inline CcaromoiDoc* CcaromoiView::GetDocument() const
   { return reinterpret_cast<CcaromoiDoc*>(m_pDocument); }
#endif

