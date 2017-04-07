#pragma once

#include"Resource.h"
// SetParamDlg 对话框

class SetParamDlg : public CDialog
{
	DECLARE_DYNAMIC(SetParamDlg)

public:
	SetParamDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~SetParamDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_nSection;
	int m_nColor;
	afx_msg void OnBnClickedSetcolor();
};
