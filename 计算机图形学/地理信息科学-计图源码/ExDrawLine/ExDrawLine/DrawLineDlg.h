#pragma once

#include "resource.h"
#include "afxdialogex.h"

// CDrawLineDlg 对话框

class CDrawLineDlg : public CDialog
{
	DECLARE_DYNAMIC(CDrawLineDlg)

public:
	CDrawLineDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDrawLineDlg();



// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_algorithm;

	afx_msg void OnBnClickedMid();
	afx_msg void OnBnClickedDDA();
	afx_msg void OnBnClickedBresenham();
	int m_r;
	int m_g;
	int m_b;
};
