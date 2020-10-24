// CourseDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "StdudentSystem.h"
#include "CourseDlg.h"
#include "afxdialogex.h"

#include "courseset.h"
#include "scoreset.h"
#include "specialset.h"

#include "ColorEggDlg.h"

// CourseDlg 对话框

IMPLEMENT_DYNAMIC(CourseDlg, CDialog)

CourseDlg::CourseDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_COURSEINFO, pParent)
{

}

CourseDlg::~CourseDlg()
{
}

void CourseDlg::ResetComboBox()
{
	m_comboSpecial.ResetContent();
	Cspecialset cSet;
	cSet.m_strSort = "special";
	cSet.Open();
	while (!cSet.IsEOF())
	{
		m_comboSpecial.AddString(cSet.m_special);
		cSet.MoveNext();
	}
	cSet.Close();
	if (m_strSpecial.IsEmpty())
		m_comboSpecial.SetCurSel(0);
}

void CourseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BOOL CourseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_spinOpen.SetRange(1, 8);

	if (m_strOKText.IsEmpty())
	{
		m_nHours = 60;
		m_fCredit = 2.0;
		m_nOpen = 1;
		m_strType = "专修";
	}
	else
	{
		GetDlgItem(IDOK)->SetWindowText(m_strOKText);
		GetDlgItem(IDC_EDIT_COURSENO)->EnableWindow(FALSE);
	}
	UpdateData(FALSE);
	// TODO: Add extra initialization here
	// 更新专业
	ResetComboBox();

	return TRUE;
}

void CourseDlg::OnOK()
{
	UpdateData();
	m_strNO.TrimLeft();
	if (m_strNO.IsEmpty())
	{
		MessageBox(L"课程号不能为空！");
		return;
	}
	m_strName.TrimLeft();
	if (m_strName.IsEmpty())
	{
		MessageBox(L"课程名称不能为空！");
		return;
	}
	CDialog::OnOK();
}

void CourseDlg::OnButtonSpecial()
{
	ColorEggDlg dlg;
	dlg.DoModal();
}


BEGIN_MESSAGE_MAP(CourseDlg, CDialog)
END_MESSAGE_MAP()


// CourseDlg 消息处理程序
