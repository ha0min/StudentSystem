// courseset.h : Ccourseset ������

#pragma once

// ���������� 2019��6��29��, 12:31

class Ccourseset : public CRecordset
{
public:
	Ccourseset(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(Ccourseset)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	CStringW	m_courseno;	//�γ̺�
	CStringW	m_special;	//����רҵ
	CStringW	m_coursename;	//�γ���
	CStringW	m_coursetype;	//�γ�����
	BYTE	m_openterm;	//����ѧ��
	BYTE	m_hours;	//��ʱ��
	float	m_credit;	//ѧ��

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


