
// ExeFileCompatibilityChangerDlg.h: 헤더 파일
//

#pragma once


// CExeFileCompatibilityChangerDlg 대화 상자
class CExeFileCompatibilityChangerDlg : public CDialogEx
{
// 생성입니다.
public:
	CExeFileCompatibilityChangerDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXEFILECOMPATIBILITYCHANGER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.



// 구현입니다.
protected:
	HICON m_hIcon;

	void		InitData();

	
	
	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnFind();
	afx_msg void OnBnClickedCheckCompatibility();
	afx_msg void OnBnClickedCheckColormode();
	afx_msg void OnBnClickedBtnApply();
	CComboBox m_ComboOS;
	CComboBox m_ComboColor;
};
