
// XComHostDlg.h : 헤더 파일
//

#pragma once
#include "xcomproctrl1.h"
#include "afxwin.h"


// CXComHostDlg 대화 상자
class CXComHostDlg : public CDialogEx
{
// 생성입니다.
public:
	CXComHostDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_XCOMHOST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
