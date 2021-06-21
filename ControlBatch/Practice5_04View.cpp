
// Practice5_04View.cpp : CPractice5_04View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Practice5_04.h"
#endif

#include "Practice5_04Doc.h"
#include "Practice5_04View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPractice5_04View

IMPLEMENT_DYNCREATE(CPractice5_04View, CView)

BEGIN_MESSAGE_MAP(CPractice5_04View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPractice5_04View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CPractice5_04View ����/�Ҹ�

CPractice5_04View::CPractice5_04View()
	: m_strResultDisplay(_T(""))
	, m_nNumber(0)
	, m_edNumber(0)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CPractice5_04View::~CPractice5_04View()
{
}

BOOL CPractice5_04View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CPractice5_04View �׸���

void CPractice5_04View::OnDraw(CDC* pDC)
{
	CPractice5_04Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	pDC->TextOut(10, 10, m_strResultDisplay);
}


// CPractice5_04View �μ�


void CPractice5_04View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPractice5_04View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CPractice5_04View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CPractice5_04View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CPractice5_04View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPractice5_04View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPractice5_04View ����

#ifdef _DEBUG
void CPractice5_04View::AssertValid() const
{
	CView::AssertValid();
}

void CPractice5_04View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPractice5_04Doc* CPractice5_04View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice5_04Doc)));
	return (CPractice5_04Doc*)m_pDocument;
}
#endif //_DEBUG


// CPractice5_04View �޽��� ó����
