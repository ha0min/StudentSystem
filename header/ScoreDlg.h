#pragma once


// ScoreDlg 对话框

class ScoreDlg : public CDialog
{
	DECLARE_DYNAMIC(ScoreDlg)

public:
	ScoreDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ScoreDlg();
	CString m_strOKText;

// 对话框数据
//#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCORE_TABLE };
	CComboBox	m_comboNO;
	float	m_fCredit;
	float	m_fScore;
	CString	m_strCourseNO;
	CString	m_strStudentNO;
	CString	m_strNO;
	CString	m_strHours;
	CString	m_strName;
	CString	m_strOpen;
	CString	m_strSpecial;
//#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 映射
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeComboNo();
	DECLARE_MESSAGE_MAP()
};
