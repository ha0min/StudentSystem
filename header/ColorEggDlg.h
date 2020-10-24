#pragma once


// ColorEgg 对话框

class ColorEggDlg : public CDialog
{
	DECLARE_DYNAMIC(ColorEggDlg)

public:
	ColorEggDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ColorEggDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_COLOREGG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
