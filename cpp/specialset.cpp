// specialset.h : Cspecialset 类的实现



// Cspecialset 实现

// 代码生成在 2019年6月29日, 12:32

#include "stdafx.h"
#include "specialset.h"
IMPLEMENT_DYNAMIC(Cspecialset, CRecordset)

Cspecialset::Cspecialset(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_special = L"";
	m_nFields = 2;
	m_nDefaultType = dynaset;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString Cspecialset::GetDefaultConnect()
{
	return _T("DSN=test;DBQ=C:\\Users\\haomin\\Desktop\\main.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString Cspecialset::GetDefaultSQL()
{
	return _T("[special]");
}

void Cspecialset::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[special]"), m_special);

}
/////////////////////////////////////////////////////////////////////////////
// Cspecialset 诊断

#ifdef _DEBUG
void Cspecialset::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cspecialset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


