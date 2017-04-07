#pragma once

#include "resource.h"
#include "afxdialogex.h"

// CDrawLineDlg �Ի���

class CDrawLineDlg : public CDialog
{
	DECLARE_DYNAMIC(CDrawLineDlg)

public:
	CDrawLineDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDrawLineDlg();



// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
