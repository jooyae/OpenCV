
// Practice11_1.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CPractice11_1App:
// �� Ŭ������ ������ ���ؼ��� Practice11_1.cpp�� �����Ͻʽÿ�.
//

class CPractice11_1App : public CWinApp
{
public:
	CPractice11_1App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CPractice11_1App theApp;