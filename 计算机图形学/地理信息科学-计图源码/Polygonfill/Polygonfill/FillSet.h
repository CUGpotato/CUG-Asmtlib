#pragma once


#include "afxcmn.h"
#include"Resource.h"
// CFillSet �Ի���

class CFillSet : public CDialog
{
	DECLARE_DYNAMIC(CFillSet)

public:
	CFillSet(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFillSet();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	double m_nScanLineAngle;
	double m_nScanLineGap;
	CTreeCtrl m_nScanLineColor;
	afx_msg void OnBnClickedScancolor(); 

	bool OnIntDialog();
	double ScanLineColor;
};
