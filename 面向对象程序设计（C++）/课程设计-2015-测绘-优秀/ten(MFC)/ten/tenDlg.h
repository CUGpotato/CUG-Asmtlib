
// tenDlg.h : ͷ�ļ�
//
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<iomanip>
#include "stdafx.h"
#include "Date.h"

using namespace std;

#pragma once
#include "afxcmn.h"


// CtenDlg �Ի���
class CtenDlg : public CDialogEx
{
// ����
public:
	CtenDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TEN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CString m_strFileDirectory;
	CListCtrl m_listRecords;

	CString m_strFileDirectoryOut;
	bool m_bExistRecords;
	int nMaxRow;
	int nMaxCol;
	int nActualRowNum;
	string **strRecords;
	string **strRecordsOut;

	bool GetCSVInfo(int &nRowNum, int &nColNum);
	bool ReadCSV(string **data);
	bool SaveCSV(string **data, int nRowNum, int nColNum);
	void AllocateMemories();
	void ReleaseMemories();

public:
	afx_msg void OnBnClickedButtonFileOpen();
	afx_msg void OnBnClickedOk();
};
