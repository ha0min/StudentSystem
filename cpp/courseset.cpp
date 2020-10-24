// courseset.h : Ccourseset 类的实现



// Ccourseset 实现

// 代码生成在 2019年6月29日, 12:31

#include "stdafx.h"
#include "courseset.h"
IMPLEMENT_DYNAMIC(Ccourseset, CRecordset)

Ccourseset::Ccourseset(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_courseno = L"";
	m_special = L"";
	m_coursename = L"";
	m_coursetype = L"";
	m_openterm = 0;
	m_hours = 0;
	m_credit = 0.0;
	m_nFields = 7;
	m_nDefaultType = dynaset;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString Ccourseset::GetDefaultConnect()
{
	return _T("DSN=test;DBQ=C:\\Users\\haomin\\Desktop\\main.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString Ccourseset::GetDefaultSQL()
{
	return _T("[course]");
}

void Ccourseset::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[courseno]"), m_courseno);
	RFX_Text(pFX, _T("[special]"), m_special);
	RFX_Text(pFX, _T("[coursename]"), m_coursename);
	RFX_Text(pFX, _T("[coursetype]"), m_coursetype);
	RFX_Byte(pFX, _T("[openterm]"), m_openterm);
	RFX_Byte(pFX, _T("[hours]"), m_hours);
	RFX_Single(pFX, _T("[credit]"), m_credit);

}
/////////////////////////////////////////////////////////////////////////////
// Ccourseset 诊断

#ifdef _DEBUG
void Ccourseset::AssertValid() const
{
	CRecordset::AssertValid();
}

void Ccourseset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


