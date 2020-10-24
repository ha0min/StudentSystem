// StuInfoDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "StdudentSystem.h"
#include "StuInfoDlg.h"
#include "afxdialogex.h"

#include "courseset.h"
#include "scoreset.h"
#include "specialset.h"
#include "studentset.h"

#include "ColorEggDlg.h"

// StuInfoDlg 对话框

IMPLEMENT_DYNAMIC(StuInfoDlg, CDialog)

void StuInfoDlg::ResetComboBox()
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

void StuInfoDlg::DrawPhoto()
{
	MessageBox(L"这里是一片荒芜！");
}

StuInfoDlg::StuInfoDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_STUINFO, pParent)
{

}

StuInfoDlg::~StuInfoDlg()
{
}

void StuInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BOOL StuInfoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
	if (!m_bSex)
		CheckRadioButton(IDC_RADIO_MALE, IDC_RADIO_FEMALE, IDC_RADIO_FEMALE);
	else
		CheckRadioButton(IDC_RADIO_MALE, IDC_RADIO_FEMALE, IDC_RADIO_MALE);
	m_strOKText.TrimLeft();
	if (m_strOKText.IsEmpty())	m_strOKText = L"添加";
	GetDlgItem(IDOK)->SetWindowText(m_strOKText);
	if (m_strOKText == L"修改")
		GetDlgItem(IDC_EDIT_NO)->EnableWindow(FALSE);
	if (!m_strPhotoFilePath.IsEmpty())
	{
		m_hBitmap = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			m_strPhotoFilePath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	}
	m_bPhotoChange = FALSE;

	// 这里对专业组合框进行初如化
	ResetComboBox();
	return TRUE;
}

void StuInfoDlg::OnRadioMale()
{
	m_bSex = TRUE;
}

void StuInfoDlg::OnRadioFemale()
{
	m_bSex = FALSE;
}

void StuInfoDlg::OnOK()
{
	// TODO: Add extra validation here
	UpdateData();
	m_strName.TrimLeft();
	m_strNO.TrimLeft();
	if (m_strName.IsEmpty())
		MessageBox(L"必须要有姓名！");
	else if (m_strNO.IsEmpty())
		MessageBox(L"必须要有学号！");
	else if (m_strSpecial.IsEmpty())
		MessageBox(L"必须要有专业！");
	else
		CDialog::OnOK();
}

void StuInfoDlg::OnButtonPhoto()
{
	MessageBox(L"好难不会做！");
}

void StuInfoDlg::OnPaint()
{
	MessageBox(L"opps!出错了！");
}

void StuInfoDlg::OnButtonSpecial1()
{
	ColorEggDlg dlg;
	dlg.DoModal();

}


BEGIN_MESSAGE_MAP(StuInfoDlg, CDialog)
END_MESSAGE_MAP()


// StuInfoDlg 消息处理程序
