
// Practice13_1View.h : CPractice13_1View 클래스의 인터페이스
//

#pragma once
#include "atltypes.h"

#define NONE_MODE		0
#define DRAW_MODE		1
#define MOVE_MODE       2

class CPractice13_1View : public CView
{
protected: // serialization에서만 만들어집니다.
	CPractice13_1View();
	DECLARE_DYNCREATE(CPractice13_1View)

// 특성입니다.
public:
	CPractice13_1Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CPractice13_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	int m_nMode;
	bool m_bStart;
	CPoint m_ptOrigin;
	CPoint m_ptPrev;
	COLORREF m_colorPoint;
	COLORREF m_colorPolygon;
	COLORREF m_colorCurve;
	bool m_bVisiblePolygon;
	bool m_bVisibleCurve;
	int m_nCtrlPointNum;
	CPoint m_ptControl[50];
	CPoint m_ptCurve[50];
	void DrawControlPolygon(CDC* pDC, bool bDrawLine);
	CPoint ComputeCurvePoint(int nDegree, CPoint AryCtrlPoint[], float fDelta);
	void CreateCurvePoint(int nDegree, int nPointNum, CPoint ptControl[], CPoint ptCurve[]);
	void DrawBezierCurve(CDC* pDC, bool bLine);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDrawBezier();
	afx_msg void OnViewPolygon();
	afx_msg void OnUpdateViewPolygon(CCmdUI *pCmdUI);
	afx_msg void OnViewCurve();
	afx_msg void OnUpdateViewCurve(CCmdUI *pCmdUI);
	int m_nResolution;
	afx_msg void OnCurveRes8();
	afx_msg void OnCurveRes16();
	afx_msg void OnCurveRes32();
	bool m_bSelectedPoint;
	int m_nSelectedPointIndex;
	afx_msg void OnSelectPoint();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Practice13_1View.cpp의 디버그 버전
inline CPractice13_1Doc* CPractice13_1View::GetDocument() const
   { return reinterpret_cast<CPractice13_1Doc*>(m_pDocument); }
#endif

