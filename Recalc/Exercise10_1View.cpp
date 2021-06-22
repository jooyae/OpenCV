
// Exercise10_1View.cpp : CExercise10_1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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

// CExercise10_1View 생성/소멸

CExercise10_1View::CExercise10_1View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CExercise10_1View::~CExercise10_1View()
{
}

BOOL CExercise10_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

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
	tvStruct.item.pszText = _T("루트 노드");

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


// CExercise10_1View 진단

#ifdef _DEBUG
void CExercise10_1View::AssertValid() const
{
	CTreeView::AssertValid();
}

void CExercise10_1View::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CExercise10_1Doc* CExercise10_1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExercise10_1Doc)));
	return (CExercise10_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CExercise10_1View 메시지 처리기


//void CExercise10_1View::OnButton1()
//{
//	// TODO: 여기에 명령 처리기 코드를 추가합니다.
//	CExercise10_1View *pView = (CExercise10_1View*) this->GetNextWindow();
//	TV_INSERTSTRUCT tvStruct;
//	UpdateData(TRUE);
//
//	if(!m_strNodeText.IsE)
//}


void CExercise10_1View::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
	m_hSelectedNode = pNMTreeView->itemNew.hItem;

	CLeftViewDlg *pDlg = (CLeftViewDlg*)this->GetNextWindow(GW_HWNDPREV);
	pDlg->m_strSelectedNode = GetTreeCtrl().GetItemText(m_hSelectedNode);

	pDlg->UpdateData(FALSE);
}
