
// Exercise10_1View.h : CExercise10_1View Ŭ������ �������̽�
//

#pragma once


class CExercise10_1View : public CTreeView
{
protected: // serialization������ ��������ϴ�.
	CExercise10_1View();
	DECLARE_DYNCREATE(CExercise10_1View)

// Ư���Դϴ�.
public:
	CExercise10_1Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CExercise10_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
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

#ifndef _DEBUG  // Exercise10_1View.cpp�� ����� ����
inline CExercise10_1Doc* CExercise10_1View::GetDocument() const
   { return reinterpret_cast<CExercise10_1Doc*>(m_pDocument); }
#endif

