
// Draw2D.h : Draw2D Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CDraw2DApp:
// �йش����ʵ�֣������ Draw2D.cpp
//

class CDraw2DApp : public CWinApp
{
public:
	CDraw2DApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDraw2DApp theApp;
