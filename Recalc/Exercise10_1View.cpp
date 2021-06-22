
// Exercise10_1View.cpp : CExercise10_1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Exercise10_1.h"
#endif

#include "Exercise10_1Doc.h"
#include "Exercise10_1View.h"
#include "LeftViewDlg.h"
#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExercise10_1View

IMPLEMENT_DYNCREATE(CExercise10_1View, CTreeView)

BEGIN_MESSAGE_MAP(CExercise10_1View, CTreeView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
//	ON_COMMAND(IDC_BUTTON1, &CExercise10_1View::OnButton1)
ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CExercise10_1View::OnTvnSelchanged)
END_MESSAGE_MAP()

// CExercise10_1View ����/�Ҹ�

CExercise10_1View::CExercise10_1View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CExercise10_1View::~CExercise10_1View()
{
}

BOOL CExercise10_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CTreeView::PreCreateWindow(cs);
}

void CExercise10_1View::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	CTreeCtrl& TreeCtrl = GetTreeCtrl();
	TV_INSERTSTRUCT tvStruct;
	tvStruct.hParent = 0;
	tvStruct.hInsertAfter = TVI_LAST;
	tvStruct.item.mask = TVIF_TEXT;
	tvStruct.item.pszText = _T("��Ʈ ���");

	m_hRoot = TreeCtrl.InsertItem(&tvStruct);
	TreeCtrl.ModifyStyle(0, TVS_LINESATROOT | TVS_HASBUTTONS | TVS_HASLINES | TVS_SHOWSELALWAYS);
	m_hSelectedNode = m_hRoot;

	CLeftViewDlg * pDlg = (CLeftViewDlg*) this ->GetNextWindow(GW_HWNDPREV);
	pDlg->m_strSelectedNode = TreeCtrl.GetItemText(m_hSelectedNode);
	((CButton*)pDlg->GetDlgItem(IDC_CHECK1))->SetCheck(TRUE);

	pDlg->UpdateData(FALSE);
	
}

void CExercise10_1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CExercise10_1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CExercise10_1View ����

#ifdef _DEBUG
void CExercise10_1View::AssertValid() const
{
	CTreeView::AssertValid();
}

void CExercise10_1View::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CExercise10_1Doc* CExercise10_1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExercise10_1Doc)));
	return (CExercise10_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CExercise10_1View �޽��� ó����


//void CExercise10_1View::OnButton1()
//{
//	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
//	CExercise10_1View *pView = (CExercise10_1View*) this->GetNextWindow();
//	TV_INSERTSTRUCT tvStruct;
//	UpdateData(TRUE);
//
//	if(!m_strNodeText.IsE)
//}


void CExercise10_1View::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
	m_hSelectedNode = pNMTreeView->itemNew.hItem;

	CLeftViewDlg *pDlg = (CLeftViewDlg*)this->GetNextWindow(GW_HWNDPREV);
	pDlg->m_strSelectedNode = GetTreeCtrl().GetItemText(m_hSelectedNode);

	pDlg->UpdateData(FALSE);
}
