// studentset.h : CStudentset ������

#pragma once

// ���������� 2019��6��30��, 14:04

class CStudentset : public CRecordset
{
public:
	CStudentset(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CStudentset)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	CStringW	m_studentname;	//����
	CStringW	m_studentno;	//ѧ��
	BOOL	m_xb;	//�Ա�
	CTime	m_birthday;	//��������
	CStringW	m_special;	//רҵ
	CStringW	m_classname;	//�༶

// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


