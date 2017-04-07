// FillSet.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Polygonfill.h"
#include "FillSet.h"
#include "afxdialogex.h"


// CFillSet �Ի���

IMPLEMENT_DYNAMIC(CFillSet, CDialog)

CFillSet::CFillSet(CWnd* pParent /*=NULL*/)
	: CDialog(CFillSet::IDD, pParent)
	, m_nScanLineAngle(0)
	, m_nScanLineGap(0)
{

}

CFillSet::~CFillSet()
{
}

void CFillSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nScanLineAngle);
	DDX_Text(pDX, IDC_EDIT2, m_nScanLineGap);
	DDX_Control(pDX, IDC_TREE1, m_nScanLineColor);
}


BEGIN_MESSAGE_MAP(CFillSet, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CFillSet::OnBnClickedScancolor)
END_MESSAGE_MAP()


// CFillSet ��Ϣ�������


void CFillSet::OnBnClickedScancolor()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CColorDialog lineColordlg;
	if (lineColordlg.DoModal() == IDOK)
	{
		ScanLineColor = lineColordlg.GetColor();
		m_nScanLineColor.SetBkColor(ScanLineColor);
	}
}

bool CFillSet::OnIntDialog()
{
	CDialog::OnInitDialog();
	m_nScanLineColor.SetBkColor(ScanLineColor);
	return TRUE;
}