#pragma once


// SeekDlg 对话框

class SeekDlg : public CDialog
{
	DECLARE_DYNAMIC(SeekDlg)

public:
	SeekDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SeekDlg();

	BOOL m_bTerm;
	int m_nTerm;
	CStringArray m_strItemArray;
	int m_nInfoType;

// 对话框数据
//#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SEEK };
	CComboBox	m_comboSeek;
	CComboBox	m_comboTerm;
	CString	m_strTitle;
	CString	m_strSeek;
//#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCombo2();
	DECLARE_MESSAGE_MAP()
};
