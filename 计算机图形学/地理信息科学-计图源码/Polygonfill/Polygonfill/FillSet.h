#pragma once


#include "afxcmn.h"
#include"Resource.h"
// CFillSet 对话框

class CFillSet : public CDialog
{
	DECLARE_DYNAMIC(CFillSet)

public:
	CFillSet(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFillSet();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_nScanLineAngle;
	double m_nScanLineGap;
	CTreeCtrl m_nScanLineColor;
	afx_msg void OnBnClickedScancolor(); 

	bool OnIntDialog();
	double ScanLineColor;
};
