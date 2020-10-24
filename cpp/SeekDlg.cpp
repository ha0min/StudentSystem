// SeekDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "StdudentSystem.h"
#include "SeekDlg.h"
#include "afxdialogex.h"

#include "courseset.h"
#include "scoreset.h"
#include "specialset.h"
#include "studentset.h"

// SeekDlg 对话框

IMPLEMENT_DYNAMIC(SeekDlg, CDialog)

SeekDlg::SeekDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_SEEK, pParent)
{

}

SeekDlg::~SeekDlg()
{
}

void SeekDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BOOL SeekDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	if (!m_strTitle.IsEmpty())
		UpdateData(FALSE);

	m_comboSeek.ResetContent();
	for (int i = 0; i < m_strItemArray.GetSize(); i++)
	{
		int	nIndex = m_comboSeek.FindString(0, m_strItemArray[i]);
		if (nIndex == CB_ERR)
			m_comboSeek.AddString(m_strItemArray[i]);
	}
	m_comboSeek.SetCurSel(0);
	m_comboTerm.ResetContent();
	CString strTerm;
	for (int i = 0; i <= 8; i++)
	{
		if (i == 0) strTerm = L"所有学期";
		else
			strTerm.Format(L"第%d学期", i);
		int nIndex = m_comboTerm.AddString(strTerm);
		m_comboTerm.SetItemData(nIndex, i);
	}
	m_comboTerm.SetCurSel(0);
	OnSelchangeCombo2();
	GetDlgItem(IDC_STATIC_TERM)->EnableWindow(m_bTerm);
	GetDlgItem(IDC_COMBO2)->EnableWindow(m_bTerm);
	return TRUE;
}

void SeekDlg::OnSelchangeCombo2()
{

	int nIndex = m_comboTerm.GetCurSel();
	if (nIndex == CB_ERR) return;
	m_nTerm = m_comboTerm.GetItemData(nIndex);
}

BEGIN_MESSAGE_MAP(SeekDlg, CDialog)
END_MESSAGE_MAP()


// SeekDlg 消息处理程序
