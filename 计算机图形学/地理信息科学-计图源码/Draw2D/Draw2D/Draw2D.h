
// Draw2D.h : Draw2D 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CDraw2DApp:
// 有关此类的实现，请参阅 Draw2D.cpp
//

class CDraw2DApp : public CWinApp
{
public:
	CDraw2DApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDraw2DApp theApp;
