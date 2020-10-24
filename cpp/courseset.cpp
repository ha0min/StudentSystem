// courseset.h : Ccourseset ���ʵ��



// Ccourseset ʵ��

// ���������� 2019��6��29��, 12:31

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
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
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
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[courseno]"), m_courseno);
	RFX_Text(pFX, _T("[special]"), m_special);
	RFX_Text(pFX, _T("[coursename]"), m_coursename);
	RFX_Text(pFX, _T("[coursetype]"), m_coursetype);
	RFX_Byte(pFX, _T("[openterm]"), m_openterm);
	RFX_Byte(pFX, _T("[hours]"), m_hours);
	RFX_Single(pFX, _T("[credit]"), m_credit);

}
/////////////////////////////////////////////////////////////////////////////
// Ccourseset ���

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


