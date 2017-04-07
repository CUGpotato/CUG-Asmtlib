// SetParamDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DrawBrizer.h"
#include "SetParamDlg.h"
#include "afxdialogex.h"


// SetParamDlg �Ի���

IMPLEMENT_DYNAMIC(SetParamDlg, CDialog)

SetParamDlg::SetParamDlg(CWnd* pParent /*=NULL*/)
	: CDialog(SetParamDlg::IDD, pParent)
	, m_nSection(0)
	, m_nColor(0)
{

}

SetParamDlg::~SetParamDlg()
{
}

void SetParamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Section, m_nSection);
	DDX_Text(pDX, IDC_Color, m_nColor);
}


BEGIN_MESSAGE_MAP(SetParamDlg, CDialog)
	ON_BN_CLICKED(IDC_SetColor, &SetParamDlg::OnBnClickedSetcolor)
END_MESSAGE_MAP()


// SetParamDlg ��Ϣ�������


void SetParamDlg::OnBnClickedSetcolor()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CColorDialog dlg;
	if (dlg.DoModal())
	{
		this->m_nColor = dlg.GetColor();
		UpdateData(FALSE);
	}
}
