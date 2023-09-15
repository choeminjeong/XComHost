
// XComHostDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "XComHost.h"
#include "XComHostDlg.h"
#include "afxdialogex.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CXComHostDlg ��ȭ ����




CXComHostDlg::CXComHostDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CXComHostDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CXComHostDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_XCOMPROCTRL1, xcompro);
	DDX_Control(pDX, IDC_LIST1, listbox);
}

BEGIN_MESSAGE_MAP(CXComHostDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_INIT, &CXComHostDlg::OnBnClickedBtnInit)
	ON_BN_CLICKED(IDC_BTN_START, &CXComHostDlg::OnBnClickedBtnStart)
	ON_BN_CLICKED(IDC_BTN_STOP, &CXComHostDlg::OnBnClickedBtnStop)
	ON_BN_CLICKED(IDC_BTN_SEND, &CXComHostDlg::OnBnClickedBtnSend)
END_MESSAGE_MAP()


// CXComHostDlg �޽��� ó����

BOOL CXComHostDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CXComHostDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CXComHostDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CXComHostDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CXComHostDlg::OnBnClickedBtnInit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int nReturn;
	CString cfg;
	cfg="host.cfg";

	if((nReturn=xcompro.Initialize(cfg))==0){
		listbox.AddString("Host successed to Initialize");
	}else{
		listbox.AddString("Host failed to Initialize");
	}
}


void CXComHostDlg::OnBnClickedBtnStart()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int nReturn;

	if((nReturn=xcompro.Start())==0){
		listbox.AddString("Host successed to Start");
	}else{
		listbox.AddString("Host failed to Start");
	}

	GetDlgItem(IDC_BTN_START)->EnableWindow(false);
	GetDlgItem(IDC_BTN_STOP)->EnableWindow(true);
}


void CXComHostDlg::OnBnClickedBtnStop()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int nReturn;

	if((nReturn=xcompro.Stop())==0){
		listbox.AddString("Host successed to Stop");
	}else{
		listbox.AddString("Host failed to Stop");
	}

	GetDlgItem(IDC_BTN_START)->EnableWindow(true);
	GetDlgItem(IDC_BTN_STOP)->EnableWindow(false);
}
BEGIN_EVENTSINK_MAP(CXComHostDlg, CDialogEx)
	ON_EVENT(CXComHostDlg, IDC_XCOMPROCTRL1, 1, CXComHostDlg::SecsEventXcomproctrl1, VTS_I2 VTS_I4)
	ON_EVENT(CXComHostDlg, IDC_XCOMPROCTRL1, 2, CXComHostDlg::SecsMsgXcomproctrl1, VTS_NONE)
END_EVENTSINK_MAP()


void CXComHostDlg::SecsEventXcomproctrl1(short nEventId, long lParam)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	char msg[256];

	if(nEventId==203){
		listbox.AddString("[ALARM] T3");
	}else if(nEventId==102){
		listbox.AddString("[EVENT] Not Selected");
	}else if(nEventId==101){
		listbox.AddString("[EVENT] Not Connected");
	}else if(nEventId==103){
		listbox.AddString("[EVENT] Selected");
	}else {
		sprintf(msg, "[EVENT] Event Code: %d, Parameters: %d", nEventId, lParam);
		listbox.AddString(msg);
	}
}


void CXComHostDlg::OnBnClickedBtnSend()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	long lMsgId, lSysByte;
	short nDevId, nStrm, nFunc;
	CString sAscii;
	BYTE u1 = 0;
	
	xcompro.MakeSecsMsg(&lMsgId, 1, 1, 5, 0);

	xcompro.SetListItem(lMsgId, 2);
	//MODULEID
	sAscii="HOST_MODULE";
	xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());
	//SFCD
	u1=0;
	xcompro.SetU1Item(lMsgId, &u1, 1);

	if((xcompro.Send(lMsgId))==0){
		listbox.AddString("Host successed to Send S1F5");
	}else{
		listbox.AddString("Host failed to Send S1F5");
	}
}


void CXComHostDlg::SecsMsgXcomproctrl1()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	long lMsgId, lSysByte, nItems, lCnt;
	short nDevId, nStrm, nFunc, nWbit;
	char msg[256];
	CString sAscii;
	char szString[255];
	BYTE u1;
	WORD u2;
	BYTE nbool;

	while((xcompro.LoadSecsMsg(&lMsgId, &nDevId, &nStrm, &nFunc, &lSysByte, &nWbit))>=0){
		sprintf(msg, "EQ received S%dF%d", nStrm, nFunc);
		listbox.AddString(msg);
		if(nStrm==1&&nFunc==5){
			xcompro.GetListItem(lMsgId, &nItems);
			//MODULEID
			xcompro.GetAsciiItem(lMsgId, (signed char*)szString, &lCnt, sizeof(szString)); 
			sprintf(msg, "MODEULID: %s", szString);
			listbox.AddString(msg);
			//SFCD
			xcompro.GetU1Item(lMsgId, &u1, &lCnt, 1); 
			sprintf(msg, "%u", u1);
			listbox.AddString(msg);

			xcompro.CloseSecsMsg(lMsgId);
			



			xcompro.MakeSecsMsg(&lMsgId, nDevId, 1, 6, lSysByte);

			xcompro.SetListItem(lMsgId, 2);
				u1=3;
				xcompro.SetU1Item(lMsgId, &u1, 1);
				xcompro.SetListItem(lMsgId, 1);
					xcompro.SetListItem(lMsgId, 3); 
						xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());
						u1=3;
						xcompro.SetU1Item(lMsgId, &u1, 1);
						xcompro.SetListItem(lMsgId, 1);
							xcompro.SetListItem(lMsgId, 20);
								sAscii="H_PANELID";
								xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());
								sAscii="H";
								xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());
								sAscii="H";
								xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());
								sAscii="H";
								xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());
								sAscii="H";
								xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());
								sAscii="H";
								xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());
								sAscii="H";
								xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());	
								sAscii="H";
								xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());	
								sAscii="H";
								xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());	
								sAscii="H";
								xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());	
								sAscii="H";
								xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());
								WORD u2arr[]={1, 2};
								xcompro.SetU2Item(lMsgId, u2arr, 2);
								u2 = 10;
								xcompro.SetU2Item(lMsgId, &u2, 1);
								u2=5;
								xcompro.SetU2Item(lMsgId, &u2, 1);
								xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());
								xcompro.SetListItem(lMsgId, 1);
									xcompro.SetListItem(lMsgId, 10);
										BYTE nboolarr[16];
										for(int i =0; i< 16;i++){
											nboolarr[i]=1;
										}
										xcompro.SetBoolItem(lMsgId, nboolarr, 16);
										xcompro.SetBoolItem(lMsgId, nboolarr, 16);
										xcompro.SetBoolItem(lMsgId, nboolarr, 16);
										xcompro.SetBoolItem(lMsgId, nboolarr, 16);
										xcompro.SetBoolItem(lMsgId, nboolarr, 16);
										xcompro.SetBoolItem(lMsgId, nboolarr, 16);
										xcompro.SetBoolItem(lMsgId, nboolarr, 16);
										xcompro.SetBoolItem(lMsgId, nboolarr, 16);
										xcompro.SetBoolItem(lMsgId, nboolarr, 16);
										xcompro.SetBoolItem(lMsgId, nboolarr, 16);
								xcompro.SetListItem(lMsgId, 1);
									xcompro.SetListItem(lMsgId, 8);
										u2=1;
										xcompro.SetU2Item(lMsgId, &u2, 1);
										sAscii="H";
										xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());
										sAscii="H";
										xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());
										sAscii="H";
										xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());
										sAscii="H";
										xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());
										sAscii="H";
										xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());
										BYTE u1arr[28];
										for(int i = 0; i < 28; i++){
											u1arr[i] = 1;
										}
										xcompro.SetU1Item(lMsgId, &u1, 28);
										xcompro.SetU1Item(lMsgId, &u1, 4);
								xcompro.SetListItem(lMsgId, 1);
									xcompro.SetListItem(lMsgId, 5);
										sAscii="H";
										xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());
										sAscii="H";
										xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());
										sAscii="H";
										xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());
										sAscii="H";
										xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());
										xcompro.SetListItem(lMsgId, 1);
											xcompro.SetListItem(lMsgId, 2);
												sAscii="H";
												xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());
												nbool=0;
												xcompro.SetBoolItem(lMsgId, &nbool, 1);
								xcompro.SetListItem(lMsgId, 1);
									xcompro.SetListItem(lMsgId, 4);
										sAscii="H";
										xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());
										sAscii="H";
										xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());
										sAscii="H";
										xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());
										sAscii="H";
										xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());
								xcompro.SetListItem(lMsgId, 1);
									xcompro.SetListItem(lMsgId, 3);
										sAscii="H";
										xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());
										sAscii="H";
										xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());
										sAscii="H";
										xcompro.SetAsciiItem(lMsgId, (signed char*)sAscii.GetBuffer(), sAscii.GetLength());

			if((xcompro.Send(lMsgId))==0){
				listbox.AddString("Host reply S1F6");
			}else{
				listbox.AddString("Host not reply S1F6");
			}
		}
	}
}
