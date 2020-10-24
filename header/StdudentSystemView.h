
// StdudentSystemView.h: CStdudentSystemView 类的接口
//
// 添加OnUpdate函数
//
//
//
//
//
//
//

#include "StdudentSystemDoc.h"
#pragma once

class CStudentSystemDoc;
class CStdudentSystemView : public CListView
{
protected: // 仅从序列化创建
	CStdudentSystemView() noexcept;
	DECLARE_DYNCREATE(CStdudentSystemView)

// 特性
public:
	CStdudentSystemDoc* GetDocument();
	typedef struct {
		CSize sizePage;			// 页面/纸大小
		CSize sizeLine;			// 每行的大小
		CSize sizeChar;			// 每个字符的平均大小
		int nLMargin;			// 左边距
		int nRMargin;			// 右边距
		int nTMargin;			// 上边距
		int nBMargin;			// 下边距
		int nPhyLeft;			// 物理左边距
		int nPhyRight;			// 物理右边距
		int nPhyTop;			// 物理上边距
		int nPhyBottom;			// 物理下边距
		LOGFONT lfHead;		// 页眉字体
		LOGFONT lfFoot;		// 页脚字体
		LOGFONT lfText;		// 正文字体
	} PAGEINFO;		// 页面信息结构

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	void DispStatusRecord();
	CString AppendStringSpace(CString str, int nNum);
	void AdjustAllLine(CDC *pDC);
	// need to be changed
	void PrintFoot(CDC* pDC, CPrintInfo* pInfo, PAGEINFO page, CString title, int margin, int mode);
	void PrintHead(CDC* pDC, CPrintInfo* pInfo, PAGEINFO page, CString title, int margin, int mode);
	void SetPageInfo(CDC *pDC, CPrintInfo *pInfo, PAGEINFO *pPage, int l, int t, int r, int b, int nLineSpace);
	void ReadListViewData();
	CStringArray	m_strContents;
	PAGEINFO 		m_pageInfo;
	CStringArray 	m_arrText;		// 处理后的文档内容
	CUIntArray  	m_nLineArray;	// 记录每页的开始行号

	void DelCourseInfo(int nItem);
	void DelScoreInfo(int nItem);
	void DelStudentInfo(int nItem);
	// need to be changed
	void ChangeScoreInfo(int nItem);
	void ChangeCourseInfo(int nItem);
	void ChangeStudentInfo(int nItem);
	void DispScoreAndCourseInfo2(CString strSpecFilter, CString strFilter2 = L"");
	void DispScoreAndCourseInfo(CString strFilter, CString strFilter2 = L"");
	void DispCourseInfo(CString strFilter, CString strSort);
	void DispStudentInfo(CString strFilter, CString strSort);
	void DeleteAllColumn();
	virtual ~CStdudentSystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnOpChange();
	afx_msg void OnOpDel();
	afx_msg void OnSelSeek();
	afx_msg void OnSelStat();
	afx_msg void OnUpdateSelStat(CCmdUI* pCmdUI);

	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // StdudentSystemView.cpp 中的调试版本
inline CStdudentSystemDoc* CStdudentSystemView::GetDocument() const
   { return reinterpret_cast<CStdudentSystemDoc*>(m_pDocument); }
#endif

