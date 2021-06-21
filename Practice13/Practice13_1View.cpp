
// Practice13_1View.cpp : CPractice13_1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Practice13_1.h"
#endif

#include "Practice13_1Doc.h"
#include "Practice13_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPractice13_1View

IMPLEMENT_DYNCREATE(CPractice13_1View, CView)

BEGIN_MESSAGE_MAP(CPractice13_1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPractice13_1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_DRAW_BEZIER, &CPractice13_1View::OnDrawBezier)
	ON_COMMAND(ID_VIEW_POLYGON, &CPractice13_1View::OnViewPolygon)
	ON_UPDATE_COMMAND_UI(ID_VIEW_POLYGON, &CPractice13_1View::OnUpdateViewPolygon)
	ON_COMMAND(ID_VIEW_CURVE, &CPractice13_1View::OnViewCurve)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CURVE, &CPractice13_1View::OnUpdateViewCurve)
	ON_COMMAND(ID_CURVE_RES_8, &CPractice13_1View::OnCurveRes8)
	ON_COMMAND(ID_CURVE_RES_16, &CPractice13_1View::OnCurveRes16)
	ON_COMMAND(ID_CURVE_RES_32, &CPractice13_1View::OnCurveRes32)
	ON_COMMAND(ID_SELECT_POINT, &CPractice13_1View::OnSelectPoint)
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CPractice13_1View 생성/소멸

CPractice13_1View::CPractice13_1View()
	: m_nMode(0)
	, m_bStart(false)
	, m_ptOrigin(0)
	, m_ptPrev(0)
	, m_bVisiblePolygon(false)
	, m_bVisibleCurve(false)
	, m_nCtrlPointNum(0)
	, m_nResolution(0)
	, m_bSelectedPoint(false)
	, m_nSelectedPointIndex(0)
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_nCtrlPointNum = 0;
	m_colorPolygon = RGB(200, 200, 200); 	// 컨트롤 폴리곤의 색상 - 밝은 회색
	m_colorCurve = RGB(255, 0, 0);			// 베이지 곡선의 색상 설정 - 빨강색 
	m_colorPoint = RGB(0, 0, 255);			// 컨트롤 포인트의 색상 - 파란색
	m_bStart = FALSE;
	m_nMode = NONE_MODE; 					// 프로그램 모드를 초기 상태로 설정 

	m_bVisiblePolygon = TRUE;				// 컨트롤 폴리곤이 보이도록 설정
	m_bVisibleCurve = TRUE;					// 베지어 곡선이 보이도록 설정

	for (int i = 0; i < 50; i++)			// 컨트롤 포인트의 좌표 배열 초기화
		m_ptControl[i] = 0;
	m_nResolution = 16;
	m_bSelectedPoint = FALSE;
}

CPractice13_1View::~CPractice13_1View()
{
}

BOOL CPractice13_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CPractice13_1View 그리기

void CPractice13_1View::OnDraw(CDC* pDC)
{
	CPractice13_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	DrawControlPolygon(pDC, m_bVisiblePolygon);
	DrawBezierCurve(pDC, m_bVisibleCurve);
}


// CPractice13_1View 인쇄


void CPractice13_1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPractice13_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CPractice13_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPractice13_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CPractice13_1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPractice13_1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	// theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPractice13_1View 진단

#ifdef _DEBUG
void CPractice13_1View::AssertValid() const
{
	CView::AssertValid();
}

void CPractice13_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPractice13_1Doc* CPractice13_1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice13_1Doc)));
	return (CPractice13_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CPractice13_1View 메시지 처리기


void CPractice13_1View::DrawControlPolygon(CDC* pDC, bool bDrawLine)
{
	CRect rectPoint;
	CPen CtrlPointPen, PolygonPen, *OldPen;

	CtrlPointPen.CreatePen(PS_SOLID, 3, m_colorPoint);
	PolygonPen.CreatePen(PS_SOLID, 1, m_colorPolygon);
	OldPen = pDC->SelectObject(&CtrlPointPen);

	if (bDrawLine)
	{
		for (int i = 0; i < m_nCtrlPointNum; i++)
		{
			rectPoint = CRect(m_ptControl[i].x - 4, m_ptControl[i].y - 4,
				m_ptControl[i].x + 4, m_ptControl[i].y + 4);
			pDC->SelectObject(&CtrlPointPen);
			pDC->Ellipse(&rectPoint);
		}
		pDC->SelectObject(&PolygonPen);
		pDC->Polyline(m_ptControl, m_nCtrlPointNum);
	}
	pDC->SelectObject(OldPen);
	DeleteObject(CtrlPointPen);
	DeleteObject(PolygonPen);
}


CPoint CPractice13_1View::ComputeCurvePoint(int nDegree, CPoint AryCtrlPoint[], float fDelta)
{
	CPoint fAryCtrlPoint[30];

	float fDelta_T;
	fDelta_T = 1.0f - fDelta;

	for (int i = 0; i <= nDegree; i++)
		fAryCtrlPoint[i] = AryCtrlPoint[i];

	for (int r = 1; r <= nDegree; r++)
		for (int i = 0; i <= nDegree - r; i++)
		{
			fAryCtrlPoint[i].x = (int)(fDelta_T * (float)fAryCtrlPoint[i].x +
				fDelta * (float)fAryCtrlPoint[i + 1].x);
			fAryCtrlPoint[i].y = (int)(fDelta_T * (float)fAryCtrlPoint[i].y +
				fDelta * (float)fAryCtrlPoint[i + 1].y);
		}

	return fAryCtrlPoint[0];
}


void CPractice13_1View::CreateCurvePoint(int nDegree, int nPointNum, CPoint ptControl[], CPoint ptCurve[])
{
	float fDelta, t;

	fDelta = 1.0f / (float)(nPointNum);
	t = 0.0f;
	for (int i = 0; i <= nPointNum; i++)
	{
		ptCurve[i] = ComputeCurvePoint(nDegree, ptControl, t);
		t = t + fDelta;
	}
}


void CPractice13_1View::DrawBezierCurve(CDC* pDC, bool bLine)
{
	CPen CurvePen, *OldPen;
	CurvePen.CreatePen(PS_SOLID, 1, m_colorCurve);
	OldPen = pDC->SelectObject(&CurvePen);

	if (m_nCtrlPointNum > 1)
	{
		CreateCurvePoint(m_nCtrlPointNum - 1, m_nResolution, m_ptControl, m_ptCurve);

		if (bLine)
			pDC->Polyline(m_ptCurve, m_nResolution+1);
	}

	pDC->SelectObject(OldPen);
	DeleteObject(CurvePen);
}


void CPractice13_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// 현재 그리기 모드이면
	if (m_nMode == DRAW_MODE)
	{
		// 다시 그리기 또는 처음 그리는 경우이면 --- 초기화.
		if (m_bStart == FALSE)
		{
			m_nCtrlPointNum = 0;
			for (int i = 0; i < 50; i++)
				m_ptControl[i] = 0;

			Invalidate();   			// 뷰를 갱신한다.
		}
		CRect rectPoint(point.x - 4, point.y - 4, point.x + 4, point.y + 4);

		// 선택한 지점에 컨트롤 포인트를 그린다.
		CClientDC dc(this);
		CPen NewPen, *OldPen;
		NewPen.CreatePen(PS_SOLID, 3, m_colorPoint);
		OldPen = dc.SelectObject(&NewPen);
		dc.Ellipse(&rectPoint);
		dc.SelectObject(OldPen);
		DeleteObject(NewPen);

		// 러버밴드 구현을 위한 임시 저장
		m_ptOrigin = m_ptPrev = point;

		// 현재 좌표 값을 배열에 저장
		m_ptControl[m_nCtrlPointNum++] = point;

		// 마우스 캡쳐
		SetCapture();
		RECT rectClient;
		GetClientRect(&rectClient);
		ClientToScreen(&rectClient);
		// 마우스 이동 범위를 클라이언트 영역으로 제한
		::ClipCursor(&rectClient);
		// 선을 그리기 시작했음을 저장
		m_bStart = TRUE;
	}
	if (m_nMode = MOVE_MODE)
	{
		for (int i = 0; i < m_nCtrlPointNum; i++)
		{
			CRect rectPoint(m_ptControl[i].x - 4, m_ptControl[i].y - 4, m_ptControl[i].x + 4, m_ptControl[i].y + 4);
			if (rectPoint.PtInRect(point))
			{
				m_bSelectedPoint = TRUE;
				m_nSelectedPointIndex = i;

				SetCapture();
				RECT rectClient;
				GetClientRect(&rectClient);
				ClientToScreen(&rectClient);
				::ClipCursor(&rectClient);
				Invalidate();
			}
		}
	}
	CView::OnLButtonDown(nFlags, point);
}


void CPractice13_1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);

	// 현재 그리기 모드이면
	if (m_nMode == DRAW_MODE)
	{
		// 러버밴드 동작이 시작되었으면
		if (m_bStart)
		{
			dc.SetROP2(R2_NOT);
			dc.MoveTo(m_ptOrigin);
			dc.LineTo(m_ptPrev);

			dc.MoveTo(m_ptOrigin);
			dc.LineTo(point);

			m_ptPrev = point;
		}
		if (m_nMode == MOVE_MODE)
		{
			CRect rectClient;
			GetClientRect(&rectClient);

			if (m_bSelectedPoint)
			{
				m_ptControl[m_nSelectedPointIndex] = point;
				InvalidateRect(&rectClient, TRUE);
			}
		}
	}
	
	CView::OnMouseMove(nFlags, point);
}


void CPractice13_1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// 현재 선 그리기 모드이면
	if (m_nMode == DRAW_MODE)
	{
		// 현재 저장된 점들의 수가 PolyBezier() 함수가 요구하는
		// 점의 개수와 동일하면
		if (m_nCtrlPointNum > 1)
		{
			// 선 그리기가 시작되었다면....
			if (m_bStart)
			{
				//오른쪽을 눌러서 마지막 점을 저장
				m_ptControl[m_nCtrlPointNum++] = point;

				// 마지막 점의 컨트롤 포인트를 그린다.
				CRect rectPoint(point.x - 4, point.y - 4, point.x + 4, point.y + 4);
				CClientDC dc(this);
				CPen NewPen, *OldPen;
				NewPen.CreatePen(PS_SOLID, 3, m_colorPoint);
				OldPen = dc.SelectObject(&NewPen);
				dc.Ellipse(&rectPoint);
				dc.SelectObject(OldPen);
				DeleteObject(NewPen);

				// 모든 컨트로로 폴리곤을 그린다.
				DrawControlPolygon(&dc, m_bVisiblePolygon);

				// 베지어 곡선을 완성한다.
				DrawBezierCurve(&dc, m_bVisibleCurve);
				//dc.PolyBezier(m_PointArray, m_nPointNum);

				// 그리기 작업의 끝을 저장한다.
				m_bStart = FALSE;
				// 마우스 캡쳐와 제한을 해제한다.
				::ReleaseCapture();
				::ClipCursor(NULL);
			}
		}
		else
		{
			AfxMessageBox(_T("적어도 2개 이상의 컨트롤 포인트가 있어야 합니다"));
		}
	}
	CView::OnRButtonDown(nFlags, point);
}


void CPractice13_1View::OnDrawBezier()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nCtrlPointNum = 0;
	m_bStart = FALSE;

	for (int i = 0; i < 50; i++)
		m_ptControl[i] = 0;

	m_nMode = DRAW_MODE;
	Invalidate();
}


void CPractice13_1View::OnViewPolygon()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_bVisiblePolygon = !m_bVisiblePolygon;
	Invalidate();
}


void CPractice13_1View::OnUpdateViewPolygon(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_bVisiblePolygon);
}


void CPractice13_1View::OnViewCurve()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_bVisibleCurve = !m_bVisibleCurve;
	Invalidate();
}


void CPractice13_1View::OnUpdateViewCurve(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_bVisibleCurve);
}


void CPractice13_1View::OnCurveRes8()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nResolution = 8;
	Invalidate();
}


void CPractice13_1View::OnCurveRes16()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nResolution =16;
	Invalidate();
}


void CPractice13_1View::OnCurveRes32()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nResolution = 32;
	Invalidate();

}


void CPractice13_1View::OnSelectPoint()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nMode = MOVE_MODE;
	m_bVisiblePolygon = TRUE;
	Invalidate();
}


void CPractice13_1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	if (m_nMode == MOVE_MODE)
	{
		if (m_bSelectedPoint)
		{
			m_ptControl[m_nSelectedPointIndex] = point;
			dc.SetROP2(R2_COPYPEN);

			DrawControlPolygon(&dc, m_bVisiblePolygon);
			DrawBezierCurve(&dc, m_bVisibleCurve);

			m_bSelectedPoint = FALSE;
			::ReleaseCapture();
			::ClipCursor(NULL);
			Invalidate();
		}
	}
	CView::OnLButtonUp(nFlags, point);
}
