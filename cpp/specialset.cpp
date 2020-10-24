// specialset.h : Cspecialset ���ʵ��



// Cspecialset ʵ��

// ���������� 2019��6��29��, 12:32

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
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
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
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[special]"), m_special);

}
/////////////////////////////////////////////////////////////////////////////
// Cspecialset ���

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


