
// Practice7_2.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CPractice7_2App:
// �� Ŭ������ ������ ���ؼ��� Practice7_2.cpp�� �����Ͻʽÿ�.
//

class CPractice7_2App : public CWinApp
{
public:
	CPractice7_2App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CPractice7_2App theApp;