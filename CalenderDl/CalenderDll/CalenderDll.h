// CalenderDll.h : CalenderDll DLL�� �⺻ ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CCalenderDllApp
// �� Ŭ������ ������ ������ CalenderDll.cpp�� �����Ͻʽÿ�.
//

class CCalenderDllApp : public CWinApp
{
public:
	CCalenderDllApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
