#pragma once


// StuInfoDlg 对话框

class StuInfoDlg : public CDialog
{
	DECLARE_DYNAMIC(StuInfoDlg)

public:
	void ResetComboBox();
	BOOL m_bPhotoChange;
	HBITMAP m_hBitmap;
	void DrawPhoto();
	CString m_strPhotoFilePath;
	CString m_strOKText;
	BOOL	m_bSex;


	StuInfoDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~StuInfoDlg();

// 对话框数据
//#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUINFO };
	CComboBox	m_comboSpecial;
	CTime	m_tBirth;
	CString	m_strName;
	CString	m_strNO;
	CString	m_strSpecial;
//#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	//{{AFX_MSG(CStuInfoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioMale();
	afx_msg void OnRadioFemale();
	virtual void OnOK();
	afx_msg void OnButtonPhoto();
	afx_msg void OnPaint();
	afx_msg void OnButtonSpecial1();

	DECLARE_MESSAGE_MAP()
};
