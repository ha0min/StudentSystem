
// StdudentSystemDoc.cpp: CStdudentSystemDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "StdudentSystem.h"
#endif

#include "StdudentSystemDoc.h"

#include "scoreset.h"
#include "courseset.h"
#include "specialset.h"
#include "studentset.h"

#include "CourseDlg.h"
#include "ScoreDlg.h"
#include "SeekDlg.h"
#include "StuInfoDlg.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CStdudentSystemDoc

IMPLEMENT_DYNCREATE(CStdudentSystemDoc, CDocument)

BEGIN_MESSAGE_MAP(CStdudentSystemDoc, CDocument)
END_MESSAGE_MAP()


// CStdudentSystemDoc 构造/析构

CStdudentSystemDoc::CStdudentSystemDoc() noexcept
{
	// TODO: 在此添加一次性构造代码

}

CStdudentSystemDoc::~CStdudentSystemDoc()
{
}

void CStdudentSystemDoc::DoCopyFile(CString strFileTo, CString strFileFrom)
{
	CFile fileFrom, fileTo;

	if (!fileFrom.Open(strFileFrom, CFile::modeRead))
	{
		AfxMessageBox(L"源文件无法打开，复制失败！");
		return;
	}
	fileTo.Open(strFileTo, CFile::modeCreate | CFile::modeWrite);

	BYTE buffer[4096];
	DWORD dwRead;
	do {
		dwRead = fileFrom.Read(buffer, 4096);
		fileTo.Write(buffer, dwRead);
	} while (dwRead > 0);

	fileFrom.Close();
	fileTo.Close();
}

void CStdudentSystemDoc::AddCourseInfo()
{
	CourseDlg dlg;
	if (dlg.DoModal() != IDOK) return;
	// 先判断课程信息是否添加过，然后再添加
	Ccourseset cSet;
	cSet.m_strFilter.Format(L"courseno='%s'", dlg.m_strNO);
	cSet.Open();
	if (!cSet.IsEOF()) {
		AfxMessageBox(dlg.m_strNO + L" 课程已添加过！");
		if (cSet.IsOpen())
			cSet.Close();
		return;
	}
	if (cSet.IsOpen()) cSet.Close();

	Ccourseset addSet;
	if (addSet.Open()) {
		// 添加一个新记录
		addSet.AddNew();
		addSet.m_courseno = dlg.m_strNO;
		addSet.m_coursename = dlg.m_strName;
		addSet.m_coursetype = dlg.m_strType;
		addSet.m_openterm = dlg.m_nOpen;
		addSet.m_hours = BYTE(dlg.m_nHours);
		addSet.m_credit = dlg.m_fCredit;
		addSet.m_special = dlg.m_strSpecial;

		addSet.Update();
		addSet.Requery();
	}
	if (addSet.IsOpen())addSet.Close();

	// 更新列表视图
	// 1,2,3 表示课程信息添加、删除、修改
	this->UpdateAllViews(NULL, 1, (CObject *)new CString(dlg.m_strNO));

}

void CStdudentSystemDoc::AddScoreInfo()
{
	ScoreDlg dlg;
	if (m_strCourseNO.IsEmpty())
		dlg.m_strCourseNO = m_strCourseNO;
	if (dlg.DoModal() != IDOK) return;
	m_strCourseNO = dlg.m_strCourseNO;
	Cscoreset sSet;
	sSet.Open();

	sSet.AddNew();
	sSet.m_course = dlg.m_strCourseNO;
	sSet.m_studentno = dlg.m_strStudentNO;
	sSet.m_score = dlg.m_fScore;
	sSet.m_credit = dlg.m_fCredit;
	sSet.Update();
	sSet.Requery();

	sSet.Close();

	// 向视图发送更新消息
	// 1,2,3 表示学生信息添加、删除、修改
	this->UpdateAllViews(NULL, 1, (CObject *)new CString(dlg.m_strStudentNO));

}

void CStdudentSystemDoc::AddStudentInfo()
{
	StuInfoDlg dlg;
	if (dlg.DoModal() != IDOK) return;
	// 向student表添加新的记录，为了防止相同的记录添加，这里先来判断
	Cstudentset infoSet;
	infoSet.m_strFilter.Format(L"studentname='%s' AND studentno='%s'",
		dlg.m_strName, dlg.m_strNO);
	infoSet.Open();
	if (!infoSet.IsEOF()) {
		AfxMessageBox(dlg.m_strName + L" 学生记录已添加过！");
		if (infoSet.IsOpen())
			infoSet.Close();
		return;
	}
	if (infoSet.IsOpen()) infoSet.Close();

	Cstudentset addSet;
	if (addSet.Open()) {
		// 添加一个新记录
		addSet.AddNew();
		addSet.m_studentname = dlg.m_strName;
		addSet.m_studentno = dlg.m_strNO;
		addSet.m_xb = dlg.m_bSex;
		addSet.m_birthday = dlg.m_tBirth;
		addSet.m_special = dlg.m_strSpecial;
		//addSet.m_totalcredit	= 0.0;

		addSet.Update();
		addSet.Requery();
	}
	if (addSet.IsOpen())addSet.Close();


	// 向视图发送更新消息
	// 1,2,3 表示学生信息添加、修改、删除
	this->UpdateAllViews(NULL, 1, (CObject *)new CString(dlg.m_strNO));
}

BOOL CStdudentSystemDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CStdudentSystemDoc 序列化

void CStdudentSystemDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CStdudentSystemDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CStdudentSystemDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CStdudentSystemDoc::OnOpAdd()
{
	if (m_nInfoType == 1)
		AddStudentInfo();
	else if (m_nInfoType == 2)
		AddCourseInfo();
	else if (m_nInfoType == 3)
		AddScoreInfo();
}

void CStdudentSystemDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CStdudentSystemDoc 诊断

#ifdef _DEBUG
void CStdudentSystemDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStdudentSystemDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CStdudentSystemDoc 命令
