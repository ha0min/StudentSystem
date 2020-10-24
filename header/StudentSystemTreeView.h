#pragma once


// StudentSystemTreeView 视图
//
// 用于建立切分窗口的类
//
//// 添加的主要函数有 
//////// ResetTreeItem 
//////// FindTreeItem
//
//
//
//
//
//
//

class StudentSystemTreeView : public CTreeView
{
	DECLARE_DYNCREATE(StudentSystemTreeView)

protected:
	StudentSystemTreeView();           // 动态创建所使用的受保护的构造函数
	virtual ~StudentSystemTreeView();

//操作
public:
	CString m_strClass;
	BOOL m_bEnableAnalyze;
	CImageList m_ImageList;
	HTREEITEM FindTreeItem(CTreeCtrl &treeCtrl, HTREEITEM hParent, CString str);
	void ResetTreeItem();

//重载
public:
	virtual void OnInitialUpdate();
protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);

#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


