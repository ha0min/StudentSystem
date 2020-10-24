// ScoreDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "StdudentSystem.h"
#include "ScoreDlg.h"
#include "afxdialogex.h"

#include "courseset.h"
#include "scoreset.h"
#include "specialset.h"
#include "studentset.h"

// ScoreDlg 对话框

IMPLEMENT_DYNAMIC(ScoreDlg, CDialog)

ScoreDlg::ScoreDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SCORE_TABLE, pParent)
{

}

ScoreDlg::~ScoreDlg()
{
}

void ScoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

void ScoreDlg::OnOK()
{
	UpdateData();
	m_strStudentNO.TrimLeft();
	m_strCourseNO.TrimLeft();
	if (m_strStudentNO.IsEmpty())
		MessageBox(L"学号不能为空！");
	else
		if (m_strCourseNO.IsEmpty())
			MessageBox(L"课程号不能为空！");
		else
			CDialog::OnOK();
}

BOOL ScoreDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将课程信息表的课程号添加到组合框中
	Ccourseset cSet;
	cSet.Open();
	while (!cSet.IsEOF())
	{
		m_comboNO.AddString(cSet.m_courseno);
		cSet.MoveNext();
	}
	if (cSet.IsOpen()) cSet.Close();

	// 确定组合框的当前选择项
	m_strCourseNO.TrimLeft();
	if (!m_strCourseNO.IsEmpty())
	{
		m_strNO = m_strCourseNO;
		UpdateData(FALSE);
		OnSelchangeComboNo();
	}
	else
	{
		m_comboNO.SetCurSel(0);
		OnSelchangeComboNo();
	}
	if (!m_strOKText.IsEmpty())
	{
		GetDlgItem(IDOK)->SetWindowText(m_strOKText);
		GetDlgItem(IDC_STUNO)->EnableWindow(FALSE);
		GetDlgItem(IDC_COURSENO)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_NO)->EnableWindow(FALSE);
		GetDlgItem(IDC_CREDIT)->EnableWindow(FALSE);
	}

	return TRUE;
}

void ScoreDlg::OnSelchangeComboNo()
{
	int nIndex = m_comboNO.GetCurSel();
	if (nIndex == CB_ERR) return;
	CString str;
	m_comboNO.GetLBText(nIndex, str);
	// 根据课程号查找course表中的记录	
	Ccourseset cSet;
	cSet.m_strFilter.Format(L"courseno='%s'", str);
	cSet.Open();
	if (!cSet.IsEOF())		// 如果打开记录集有记录
	{
		m_strNO = m_strCourseNO = str;
		m_strName = cSet.m_coursename;
		m_strHours.Format(L"%d", cSet.m_hours);
		m_strOpen.Format(L"%d", cSet.m_openterm);
		m_fCredit = cSet.m_credit;
		m_strSpecial = cSet.m_special;
		UpdateData(FALSE);
	}
	if (cSet.IsOpen()) cSet.Close();
}


BEGIN_MESSAGE_MAP(ScoreDlg, CDialog)
END_MESSAGE_MAP()


// ScoreDlg 消息处理程序
