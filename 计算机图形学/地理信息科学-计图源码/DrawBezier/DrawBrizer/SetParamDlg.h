#pragma once

#include"Resource.h"
// SetParamDlg �Ի���

class SetParamDlg : public CDialog
{
	DECLARE_DYNAMIC(SetParamDlg)

public:
	SetParamDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~SetParamDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_nSection;
	int m_nColor;
	afx_msg void OnBnClickedSetcolor();
};
