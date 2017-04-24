
// tenDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ten.h"
#include "tenDlg.h"
#include "afxdialogex.h"
#include "Date.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CtenDlg �Ի���



CtenDlg::CtenDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CtenDlg::IDD, pParent)
	, m_strFileDirectory(_T(""))
{
	m_bExistRecords = false;
	nMaxRow = nMaxCol = nActualRowNum = 0;
	strRecords = strRecordsOut=NULL;

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_FILE_DIRECTORY, m_strFileDirectory);
	DDX_Control(pDX, IDC_LIST_RECORDS, m_listRecords);
}

BEGIN_MESSAGE_MAP(CtenDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_FILE_OPEN, &CtenDlg::OnBnClickedButtonFileOpen)
	ON_BN_CLICKED(IDOK, &CtenDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CtenDlg ��Ϣ�������

BOOL CtenDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	DWORD dwStyle = GetWindowLong(m_listRecords.m_hWnd, GWL_STYLE);
	SetWindowLong(m_listRecords.m_hWnd, GWL_STYLE, dwStyle | LVS_REPORT);
	DWORD styles = m_listRecords.GetExtendedStyle();
	m_listRecords.SetExtendedStyle(styles | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	const int MAX_COL_NUM = 5;
	CString strFields[MAX_COL_NUM] = { "ID", "Gender", "Birthday", "Enrollment date", "Enrollment age" };
	for (int i = 0; i < MAX_COL_NUM; i++)
	{
		m_listRecords.InsertColumn(i, strFields[i], LVCFMT_CENTER, 100, 0);
	}
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CtenDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CtenDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CtenDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

bool CtenDlg::GetCSVInfo(int &nRowNum, int &nColNum)
{
	ifstream inFile(m_strFileDirectory);
	string strLine;
	string strItem;
	int lineNum = 0;
	int itemNum = 0;
	if (!inFile)return false;
	while (getline(inFile, strLine))
	{
		istringstream linestream(strLine);
		if (0 == lineNum)
		{
			while (getline(linestream, strItem, ','))

				itemNum++;
			nColNum = itemNum;
		}
			lineNum++;
	}
	nRowNum = lineNum;
	return true;
}

bool CtenDlg::ReadCSV(string **data)
{
	ifstream inFile(m_strFileDirectory);
	string strLine;
	string strItem;
	int lineNum = 0;
	int itemNum = 0;
	if (!inFile)return false;
	while (getline(inFile, strLine))
	{
		istringstream linestream(strLine);
		itemNum = 0;
		while (getline(linestream, strItem, ','))
		{
			data[lineNum][itemNum] = strItem;
			itemNum++;
		}
		lineNum++;
	}
	return true;
}

bool CtenDlg::SaveCSV(string **data, int nRowNum, int nColNum)
{
	ofstream outFile(m_strFileDirectoryOut);
	int i, k;
	if (!outFile)return false;
	for (i = 0; i < nRowNum;i++)
	{
		for (k = 0; k < nColNum - 1; k++)
		{
			outFile << strRecordsOut[i][k] << ",";
		}
		outFile << strRecordsOut[i][k] << endl;
	}
	return true;
}

void CtenDlg::AllocateMemories()
{
	strRecords = new string*[nMaxRow];
	strRecordsOut = new string*[nMaxRow];
	for (int i = 0; i < nMaxRow; i++)
	{
		strRecords[i] = new string[nMaxCol];
		strRecordsOut[i] = new string[nMaxCol+1];
	}
}

void CtenDlg::ReleaseMemories()
{
	for (int i = 0; i < nMaxRow; i++)
	{
		delete[]strRecords[i];
		delete[]strRecordsOut[i];
	}
	delete[]strRecords;
	delete[]strRecordsOut;
}



void CtenDlg::OnBnClickedButtonFileOpen()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	string strFilter("CSV file(*.CSV)|*.CSV||");
	int i;
	CFileDialog FileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, strFilter.c_str());
	if (FileDlg.DoModal() != IDOK)return;
	m_strFileDirectory = FileDlg.GetPathName();
	UpdateData(FALSE);
	if (m_bExistRecords)
	{
		m_listRecords.DeleteAllItems();
		ReleaseMemories();
	}
	if (!GetCSVInfo(nMaxRow, nMaxCol))return;
	AllocateMemories();
	if (!ReadCSV(strRecords))return;
	m_bExistRecords=true;
	for (i = 0; i < nMaxRow; i++)
	{
		m_listRecords.InsertItem(i, strRecords[i][0].c_str());
		for (int j = 1; j < nMaxCol; j++)
			m_listRecords.SetItemText(i, j, strRecords[i][j].c_str());////////////////////////
	}
}


void CtenDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
	for (int m = 0; m < nMaxRow; m++)
	{
		for (int n = 0; n < nMaxCol; n++)
		{
			strRecordsOut[m][n] = strRecords[m][n];
		}
	}


	string strBirthday, strEnrollmentDate;
	CDate cBirthday, cEnrollmentDate;
	bool bRepeat;
	int i, j, k;
	int nPos = -1;
	int nEnrollmentDays;
	if (!m_bExistRecords)
	{
		MessageBox("Please open a CSV file!","Information",MB_OK);
		return;
	}
	nActualRowNum = 0;
	for (i = 0; i < nMaxRow; i++)
	{
		bRepeat = false;
		for (j = 0; j < nActualRowNum; j++)
			if (strRecords[i][0] == strRecordsOut[j][0])bRepeat = true;
		
		if (!bRepeat)
		{
			for (k = 0; k < nMaxCol; k++)
				strRecordsOut[nActualRowNum][k] = strRecords[i][k];
			nActualRowNum++;
		}
	}
	for (i = 0; i < nActualRowNum; i++)
	{
		strBirthday = strRecordsOut[i][2];
		cBirthday.Set(strBirthday);
		strEnrollmentDate = strRecordsOut[i][3];
		cEnrollmentDate.Set(strEnrollmentDate);
		nEnrollmentDays = cEnrollmentDate.ComplexCompare(cBirthday);
		///////////////////////////////////////////////////////////////////////
		ostringstream streamEnrollmentAge;
		streamEnrollmentAge << setprecision(4) << nEnrollmentDays / 365.25;
		strRecordsOut[i][nMaxCol] = streamEnrollmentAge.str();
	}
	nPos = m_strFileDirectory.Find(".");
	if (-1 == nPos)return;
	m_strFileDirectoryOut = m_strFileDirectory;
	m_strFileDirectoryOut.Insert(nPos, "_modified");
	if (!SaveCSV(strRecordsOut, nActualRowNum, nMaxCol + 1))
	{
		MessageBox("Cannot save the records to a CSV file!", "Information", MB_OK);
		return;
	}
	else
	{
		m_listRecords.DeleteAllItems();
		for (i = 0; i < nActualRowNum; i++)
		{
			m_listRecords.InsertItem(i, strRecordsOut[i][0].c_str());
			for (j = 1; j < nMaxCol + 1; j++)
				m_listRecords.SetItemText(i, j, strRecordsOut[i][j].c_str());
		}
		ShellExecute(NULL, "open", m_strFileDirectoryOut, NULL, NULL, SW_SHOW);
	}
}
