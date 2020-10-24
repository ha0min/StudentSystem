
// StdudentSystemDoc.h: CStdudentSystemDoc 类的接口
//
//
//
//
//
//
//
//
//



#pragma once


class CStdudentSystemDoc : public CDocument
{
protected: // 仅从序列化创建
	CStdudentSystemDoc() noexcept;
	DECLARE_DYNCREATE(CStdudentSystemDoc)

// 特性
public:

// 操作
public:
	CString m_strCourseNO;
	int m_nInfoType;
	int m_nViewPos;

	void DoCopyFile(CString strFileTo, CString strFileFrom);
	void AddCourseInfo();
	void AddScoreInfo();
	void AddStudentInfo();

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CStdudentSystemDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnOpAdd();
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
