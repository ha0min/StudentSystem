#pragma once


// CourseDlg 对话框

class CourseDlg : public CDialog
{
	DECLARE_DYNAMIC(CourseDlg)

public:
	CourseDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CourseDlg();

// 构造
public:
	void ResetComboBox();
	CString m_strOKText;
// 对话框数据
//#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COURSEINFO };
	CSpinButtonCtrl	m_spinOpen;
	CComboBox	m_comboSpecial;
	CString	m_strType;
	int		m_nHours;
	CString	m_strName;
	CString	m_strNO;
	float	m_fCredit;
	CString	m_strSpecial;
	BYTE	m_nOpen;
//#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 声明
protected:

	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnButtonSpecial();
	DECLARE_MESSAGE_MAP()
};
