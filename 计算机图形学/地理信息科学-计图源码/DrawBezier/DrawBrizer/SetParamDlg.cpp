// SetParamDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DrawBrizer.h"
#include "SetParamDlg.h"
#include "afxdialogex.h"


// SetParamDlg 对话框

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


// SetParamDlg 消息处理程序


void SetParamDlg::OnBnClickedSetcolor()
{
	// TODO:  在此添加控件通知处理程序代码
	CColorDialog dlg;
	if (dlg.DoModal())
	{
		this->m_nColor = dlg.GetColor();
		UpdateData(FALSE);
	}
}
