
// Practice11_3.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CPractice11_3App:
// �� Ŭ������ ������ ���ؼ��� Practice11_3.cpp�� �����Ͻʽÿ�.
//

class CPractice11_3App : public CWinApp
{
public:
	CPractice11_3App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CPractice11_3App theApp;