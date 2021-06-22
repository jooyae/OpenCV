// CalenderDll.cpp : �ش� DLL�� �ʱ�ȭ ��ƾ�� �����մϴ�.
//

#include "stdafx.h"
#include "CalenderDll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern "C" __declspec(dllexport) void Calender(int year, int month, int *Days);

//
//TODO: �� DLL�� MFC DLL�� ���� �������� ��ũ�Ǿ� �ִ� ���
//		MFC�� ȣ��Ǵ� �� DLL���� ���������� ��� �Լ���
//		���� �κп� AFX_MANAGE_STATE ��ũ�ΰ�
//		��� �־�� �մϴ�.
//
//		��:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �Ϲ����� �Լ� ������ ���⿡ �ɴϴ�.
//		}
//
//		�� ��ũ�δ� MFC�� ȣ���ϱ� ����
//		�� �Լ��� �ݵ�� ��� �־�� �մϴ�.
//		��, ��ũ�δ� �Լ��� ù ��° ���̾�� �ϸ� 
//		��ü ������ �����ڰ� MFC DLL��
//		ȣ���� �� �����Ƿ� ��ü ������ ����Ǳ� ����
//		���;� �մϴ�.
//
//		�ڼ��� ������
//		MFC Technical Note 33 �� 58�� �����Ͻʽÿ�.
//

// CCalenderDllApp

BEGIN_MESSAGE_MAP(CCalenderDllApp, CWinApp)
END_MESSAGE_MAP()


// CCalenderDllApp ����

CCalenderDllApp::CCalenderDllApp()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
}


// ������ CCalenderDllApp ��ü�Դϴ�.

CCalenderDllApp theApp;


// CCalenderDllApp �ʱ�ȭ

BOOL CCalenderDllApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

//extern "C"__declspec(dllexport) void Calender(int year, int month, int*Days);

int FirstDay(int year, int month);
bool IsLeapYear(int year);

static int DaysOfMonth[2][12] = {
		{31,28,31,30,31,30,31,31,30,31,30,31},
		{31,29,31,30,31,30,31,31,30,31,30,31},
};
	int m_nStartYear = 1583;
	int m_nEndYear = 4040;
	int m_nStartMonth = 0;

	bool IsLeapYear(int year) {
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
			return true;
		else
			return false;

}
	int FirstDay(int year, int month) {
		int i, day = 0;

		for (i = m_nStartYear; i < year; i++)
		{
			if (IsLeapYear(i))
				day += 366;
			else
				day += 365;
			day %= 7;
		}
		for (i = m_nStartMonth; i < month; ++i)
		{
			
			day += DaysOfMonth[IsLeapYear(year)][i];
			day %= 7;
		}
		if (day == 0)
		{
			day = 7;
		}
		return (day - 1);
}

	_declspec(dllexport)void Calender(int year, int month, int *Days)
	{
		int ThisDay, EndDay, Week, i;


		ThisDay = FirstDay(year, month);

		EndDay = DaysOfMonth[IsLeapYear(year)][month];
		Week = 0;

		for (i = 0; i <= EndDay; i++)
		{
			*(Days + (Week * 7) + ThisDay) = i;
			ThisDay++;
			if (ThisDay == 7)
			{
				ThisDay = 0;
				Week++;
			}
		}
}
