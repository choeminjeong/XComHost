
// XComHost.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CXComHostApp:
// �� Ŭ������ ������ ���ؼ��� XComHost.cpp�� �����Ͻʽÿ�.
//

class CXComHostApp : public CWinApp
{
public:
	CXComHostApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CXComHostApp theApp;