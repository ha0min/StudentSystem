// ColorEgg.cpp: 实现文件
//

#include "stdafx.h"
#include "StdudentSystem.h"
#include "ColorEggDlg.h"
#include "afxdialogex.h"


// ColorEgg 对话框

IMPLEMENT_DYNAMIC(ColorEggDlg, CDialog)

ColorEggDlg::ColorEggDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_COLOREGG, pParent)
{

}

ColorEggDlg::~ColorEggDlg()
{
}

void ColorEggDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ColorEggDlg, CDialog)
END_MESSAGE_MAP()


// ColorEgg 消息处理程序
