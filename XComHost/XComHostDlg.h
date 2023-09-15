
// XComHostDlg.h : ��� ����
//

#pragma once
#include "xcomproctrl1.h"
#include "afxwin.h"


// CXComHostDlg ��ȭ ����
class CXComHostDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CXComHostDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_XCOMHOST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CXcomproctrl1 xcompro;
	CListBox listbox;
	afx_msg void OnBnClickedBtnInit();
	afx_msg void OnBnClickedBtnStart();
	afx_msg void OnBnClickedBtnStop();
	DECLARE_EVENTSINK_MAP()
	void SecsEventXcomproctrl1(short nEventId, long lParam);
	afx_msg void OnBnClickedBtnSend();
	void SecsMsgXcomproctrl1();
};
