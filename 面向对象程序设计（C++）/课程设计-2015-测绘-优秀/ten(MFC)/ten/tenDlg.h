
// tenDlg.h : 头文件
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


// CtenDlg 对话框
class CtenDlg : public CDialogEx
{
// 构造
public:
	CtenDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TEN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
