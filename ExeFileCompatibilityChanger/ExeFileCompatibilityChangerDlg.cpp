
// ExeFileCompatibilityChangerDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "ExeFileCompatibilityChanger.h"
#include "ExeFileCompatibilityChangerDlg.h"
#include "afxdialogex.h"
#include "FileCompatibilityManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExeFileCompatibilityChangerDlg 대화 상자



CExeFileCompatibilityChangerDlg::CExeFileCompatibilityChangerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EXEFILECOMPATIBILITYCHANGER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExeFileCompatibilityChangerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_OS, m_ComboOS);
	DDX_Control(pDX, IDC_COMBO_COLOR, m_ComboColor);
}

BEGIN_MESSAGE_MAP(CExeFileCompatibilityChangerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_FIND, &CExeFileCompatibilityChangerDlg::OnBnClickedBtnFind)
	ON_BN_CLICKED(IDC_CHECK_COMPATIBILITY, &CExeFileCompatibilityChangerDlg::OnBnClickedCheckCompatibility)
	ON_BN_CLICKED(IDC_CHECK_COLORMODE, &CExeFileCompatibilityChangerDlg::OnBnClickedCheckColormode)
	ON_BN_CLICKED(IDC_BTN_APPLY, &CExeFileCompatibilityChangerDlg::OnBnClickedBtnApply)
END_MESSAGE_MAP()


// CExeFileCompatibilityChangerDlg 메시지 처리기

BOOL CExeFileCompatibilityChangerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	InitData();
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CExeFileCompatibilityChangerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CExeFileCompatibilityChangerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CExeFileCompatibilityChangerDlg::InitData()
{
	m_ComboOS.AddString(_T("Windows 95"));
	m_ComboOS.AddString(_T("Windows 98 /Windows Me"));
	m_ComboOS.AddString(_T("Windows XP(서비스 팩 2)"));
	m_ComboOS.AddString(_T("Windows XP(서비스 팩 3)"));
	m_ComboOS.AddString(_T("Vista"));
	m_ComboOS.AddString(_T("Vista(서비스 팩 1)"));
	m_ComboOS.AddString(_T("Vista(서비스 팩 2)"));
	m_ComboOS.AddString(_T("Windows 7"));
	m_ComboOS.AddString(_T("Windows 8"));

	m_ComboOS.SetCurSel(7);
	m_ComboOS.EnableWindow(FALSE);


	m_ComboColor.AddString(_T("8비트(256)색"));
	m_ComboColor.AddString(_T("16비트(65536)색"));

	m_ComboColor.SetCurSel(0);
	m_ComboColor.EnableWindow(FALSE);
}


void CExeFileCompatibilityChangerDlg::OnBnClickedBtnFind()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog _fdlg(TRUE, _T(".exe"), NULL, OFN_HIDEREADONLY, _T("Exe File|*.exe|All FILE|*.*|"));

	if (_fdlg.DoModal() == IDOK)
	{
		GetDlgItem(IDC_EDIT_EXEPATH)->SetWindowText(_fdlg.GetPathName());
	}
}


void CExeFileCompatibilityChangerDlg::OnBnClickedCheckCompatibility()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BOOL bCheck = ((CButton*)(GetDlgItem(IDC_CHECK_COMPATIBILITY)))->GetCheck();


	if (bCheck)
	{
		m_ComboOS.EnableWindow(TRUE);
	}
	else
	{
		m_ComboOS.EnableWindow(FALSE);
	}

	
	
}


void CExeFileCompatibilityChangerDlg::OnBnClickedCheckColormode()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BOOL bCheck = ((CButton*)(GetDlgItem(IDC_CHECK_COLORMODE)))->GetCheck();

	if (bCheck)
	{
		m_ComboColor.EnableWindow(TRUE);
	}
	else
	{
		m_ComboColor.EnableWindow(FALSE);
	}
}


void CExeFileCompatibilityChangerDlg::OnBnClickedBtnApply()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BOOL	bCheck = FALSE;
	int		nFlag = 0;
	int		nSelectItemIndex = 0;
	osMode	_osMode;
	colorMode	_colorMode;
	CString		strExeFilePath = _T("");

	GetDlgItem(IDC_EDIT_EXEPATH)->GetWindowText(strExeFilePath);

	bCheck = ((CButton*)(GetDlgItem(IDC_CHECK_COMPATIBILITY)))->GetCheck();

	if (bCheck)
	{
		nFlag = nFlag | _check_compatibility;

		nSelectItemIndex = m_ComboOS.GetCurSel();
	
		_osMode = (osMode)nSelectItemIndex;
	}


	bCheck = ((CButton*)(GetDlgItem(IDC_CHECK_COLORMODE)))->GetCheck();

	if (bCheck)
	{
		nFlag = nFlag | _check_colormode;

		nSelectItemIndex = m_ComboColor.GetCurSel();
		_colorMode = (colorMode)nSelectItemIndex;
	}

	bCheck = ((CButton*)(GetDlgItem(IDC_CHECK_RESOLUTION)))->GetCheck();
	if (bCheck)
	{
		nFlag = nFlag | _check_resolution;
	}


	bCheck = ((CButton*)(GetDlgItem(IDC_CHECK_NOTUSEFULLSCREEN)))->GetCheck();
	if (bCheck)
	{
		nFlag = nFlag | _check_notfullscreen;
	}


	bCheck = ((CButton*)(GetDlgItem(IDC_CHECK_RUNASADMIN)))->GetCheck();
	if (bCheck)
	{
		nFlag = nFlag | _check_runasadmin;
	}

	bCheck = ((CButton*)(GetDlgItem(IDC_CHECK_REGRESTART)))->GetCheck();
	if (bCheck)
	{
		nFlag = nFlag | _check_restart;
	}

	FileCompatibilityManager _manger;
	int nResult = _manger.SetCompatibilityData(strExeFilePath, nFlag, _osMode, _colorMode);

	if (nResult != 0)
	{
		CString strError = _T("");
		strError.Format(_T(" %s 파일 옵션 변경 실패. [Err = %d] "), strExeFilePath, nResult);
		AfxMessageBox(strError);
	}
	else
	{
		AfxMessageBox(_T("Success!!"));
	}
}
