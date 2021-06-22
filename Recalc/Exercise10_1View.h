
// Exercise10_1View.h : CExercise10_1View 클래스의 인터페이스
//

#pragma once


class CExercise10_1View : public CTreeView
{
protected: // serialization에서만 만들어집니다.
	CExercise10_1View();
	DECLARE_DYNCREATE(CExercise10_1View)

// 특성입니다.
public:
	CExercise10_1Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CExercise10_1View();
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
	HTREEITEM m_hRoot;
	HTREEITEM m_hSelectedNode;
//	HTREEITEM m_treeControl;
//	afx_msg void OnButton1();
	afx_msg void OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult);
};

#ifndef _DEBUG  // Exercise10_1View.cpp의 디버그 버전
inline CExercise10_1Doc* CExercise10_1View::GetDocument() const
   { return reinterpret_cast<CExercise10_1Doc*>(m_pDocument); }
#endif

