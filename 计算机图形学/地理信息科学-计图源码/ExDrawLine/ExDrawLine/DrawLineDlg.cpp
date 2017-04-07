// DrawLineDlg.cpp : ʵ���ļ�
//


#include "stdafx.h"
#include "resource.h"
#include "afxdialogex.h"



// CDrawLineDlg �Ի���

IMPLEMENT_DYNAMIC(CDrawLineDlg, CDialog)

CDrawLineDlg::CDrawLineDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDrawLineDlg::IDD, pParent)
	, m_algorithm(0)
	, m_r(0)
	, m_g(0)
	, m_b(0)
{

}

CDrawLineDlg::~CDrawLineDlg()
{
}

void CDrawLineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_algorithm);
	DDX_Text(pDX, IDC_EDIT1, m_r);
	DDX_Text(pDX, IDC_EDIT2, m_g);
	DDX_Text(pDX, IDC_EDIT3, m_b);
}


BEGIN_MESSAGE_MAP(CDrawLineDlg, CDialog)
	ON_BN_CLICKED(IDC_RADIO1, &CDrawLineDlg::OnBnClickedMid)
	ON_BN_CLICKED(IDC_RADIO2, &CDrawLineDlg::OnBnClickedDDA)
	ON_BN_CLICKED(IDC_RADIO3, &CDrawLineDlg::OnBnClickedBresenham)
END_MESSAGE_MAP()


// CDrawLineDlg ��Ϣ�������


void CDrawLineDlg::OnBnClickedMid()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_algorithm = 0;
}


void CDrawLineDlg::OnBnClickedDDA()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_algorithm = 1;
}


void CDrawLineDlg::OnBnClickedBresenham()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_algorithm = 2;
}

