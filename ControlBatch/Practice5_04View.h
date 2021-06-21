
// Practice5_04View.h : CPractice5_04View 클래스의 인터페이스
//

#pragma once


class CPractice5_04View : public CView
{
protected: // serialization에서만 만들어집니다.
	CPractice5_04View();
	DECLARE_DYNCREATE(CPractice5_04View)

// 특성입니다.
public:
	CPractice5_04Doc* GetDocument() const;

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
	virtual ~CPractice5_04View();
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
	CString m_strResultDisplay;
	int m_nNumber;
	int m_edNumber;
};

#ifndef _DEBUG  // Practice5_04View.cpp의 디버그 버전
inline CPractice5_04Doc* CPractice5_04View::GetDocument() const
   { return reinterpret_cast<CPractice5_04Doc*>(m_pDocument); }
#endif

