// StudentSystemTreeView.cpp: 实现文件
//

#include "stdafx.h"
#include "StdudentSystem.h"
#include "StudentSystemTreeView.h"

#include "StdudentSystemDoc.h"

#include "studentset.h"


// StudentSystemTreeView

IMPLEMENT_DYNCREATE(StudentSystemTreeView, CTreeView)

StudentSystemTreeView::StudentSystemTreeView()
{

}

StudentSystemTreeView::~StudentSystemTreeView()
{
}

BEGIN_MESSAGE_MAP(StudentSystemTreeView, CTreeView)
END_MESSAGE_MAP()


// StudentSystemTreeView 诊断

#ifdef _DEBUG
HTREEITEM StudentSystemTreeView::FindTreeItem(CTreeCtrl & treeCtrl, HTREEITEM hParent, CString str)
{
	HTREEITEM hNext;
	CString strItem;

	hNext = treeCtrl.GetChildItem(hParent);
	while (hNext != NULL) {
		strItem = treeCtrl.GetItemText(hNext);
		if (strItem == str) {
			return hNext;
		}
		else {
			hNext = treeCtrl.GetNextItem(hNext, TVGN_NEXT);
		}
	}
	return NULL;
	//return HTREEITEM();
}

void StudentSystemTreeView::ResetTreeItem()
{
	CTreeCtrl& m_TreeCtrl = GetTreeCtrl();
	if (m_TreeCtrl.GetCount() > 0)
		m_TreeCtrl.DeleteAllItems();

	HTREEITEM hRoot, hSpec, hClass;
	CString strRoot[3] = { L"学生信息", L"课程信息", L"学生成绩" };

	for (int nRoot = 0; nRoot < 3; nRoot++)
	{
		hRoot = m_TreeCtrl.InsertItem(strRoot[nRoot], 0, 1);

		Cstudentset sSet;
		sSet.m_strSort = "special";	// 按专业排序
		sSet.Open();
		while (!sSet.IsEOF())
		{
			hSpec = FindTreeItem(m_TreeCtrl, hRoot, sSet.m_special);
			// 查找是否有重复的专业节点
			if (hSpec == NULL)	// 若没有重复的专业节点
				hSpec = m_TreeCtrl.InsertItem(sSet.m_special, 0, 1, hRoot);
			if (nRoot != 1)
			{
				hClass = FindTreeItem(m_TreeCtrl, hSpec, sSet.m_studentno.Left(6));
				// 查找是否有重复的班级节点
				if (hClass == NULL)	// 若没有重复的班级节点
					hClass = m_TreeCtrl.InsertItem(sSet.m_studentno.Left(6), 0, 1, hSpec);
				//m_TreeCtrl.InsertItem(sSet.m_studentno, hClass);			
			}
			sSet.MoveNext();
		}
		sSet.Close();
	}
}

void StudentSystemTreeView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	CTreeCtrl& m_TreeCtrl = GetTreeCtrl();
	m_ImageList.Create(16, 16, ILC_COLOR8 | ILC_MASK, 2, 1);
	m_TreeCtrl.SetImageList(&m_ImageList, TVSIL_NORMAL);
	SHFILEINFO fi;		// 定义一个文件信息结构变量
	
	ResetTreeItem();
}

void StudentSystemTreeView::OnDraw(CDC * pDC)
{
	CDocument* pDoc = GetDocument();
}

BOOL StudentSystemTreeView::PreCreateWindow(CREATESTRUCT & cs)
{
	cs.style |= (TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS);

	return CTreeView::PreCreateWindow(cs);
	//return 0;
}

void StudentSystemTreeView::OnUpdate(CView * pSender, LPARAM lHint, CObject * pHint)
{
	if (lHint == 1)
		ResetTreeItem();
}

void StudentSystemTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void StudentSystemTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// StudentSystemTreeView 消息处理程序
