
// Practice5_04View.h : CPractice5_04View Ŭ������ �������̽�
//

#pragma once


class CPractice5_04View : public CView
{
protected: // serialization������ ��������ϴ�.
	CPractice5_04View();
	DECLARE_DYNCREATE(CPractice5_04View)

// Ư���Դϴ�.
public:
	CPractice5_04Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CPractice5_04View();
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
	CString m_strResultDisplay;
	int m_nNumber;
	int m_edNumber;
};

#ifndef _DEBUG  // Practice5_04View.cpp�� ����� ����
inline CPractice5_04Doc* CPractice5_04View::GetDocument() const
   { return reinterpret_cast<CPractice5_04Doc*>(m_pDocument); }
#endif

