// scoreset.h : Cscoreset ���ʵ��



// Cscoreset ʵ��

// ���������� 2019��6��29��, 12:32

#include "stdafx.h"
#include "scoreset.h"
IMPLEMENT_DYNAMIC(Cscoreset, CRecordset)

Cscoreset::Cscoreset(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_studentno = L"";
	m_course = L"";
	m_score = 0.0;
	m_credit = 0.0;
	m_nFields = 4;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Cscoreset::GetDefaultConnect()
{
	return _T("DSN=test;DBQ=C:\\Users\\haomin\\Desktop\\main.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString Cscoreset::GetDefaultSQL()
{
	return _T("[score]");
}

void Cscoreset::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[studentno]"), m_studentno);
	RFX_Text(pFX, _T("[course]"), m_course);
	RFX_Single(pFX, _T("[score]"), m_score);
	RFX_Single(pFX, _T("[credit]"), m_credit);

}
/////////////////////////////////////////////////////////////////////////////
// Cscoreset ���

#ifdef _DEBUG
void Cscoreset::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cscoreset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


