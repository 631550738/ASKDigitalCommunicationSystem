// DigitalCommunicationSystemDlg.h : header file
//
#include "SigTranmit.h"
#if !defined(AFX_DIGITALCOMMUNICATIONSYSTEMDLG_H__BCE9950D_0EA0_4CAB_BB48_681CE16625E4__INCLUDED_)
#define AFX_DIGITALCOMMUNICATIONSYSTEMDLG_H__BCE9950D_0EA0_4CAB_BB48_681CE16625E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDigitalCommunicationSystemDlg dialog
#ifndef N
#define N 320
#endif
class CDigitalCommunicationSystemDlg : public CDialog
{
// Construction
public:
	CDigitalCommunicationSystemDlg(CWnd* pParent = NULL);	// standard constructor
	float Findmax(float S[],int n);//查找最大序列值
	void Graph(float S[],float Freq[]);//画图函数
	void Graph1(int *S);//抽样判决显示
	SigTranmit Sig;//新建信号传输对象
// Dialog Data
	//{{AFX_DATA(CDigitalCommunicationSystemDlg)
	enum { IDD = IDD_DIGITALCOMMUNICATIONSYSTEM_DIALOG };
	int		m_ID;
	int		m_Intensity;
	int		ms1_0;
	int		ms1_1;
	int		ms1_10;
	int		ms1_11;
	int		ms1_12;
	int		ms1_13;
	int		ms1_14;
	int		ms1_15;
	int		ms1_2;
	int		ms1_3;
	int		ms1_4;
	int		ms1_5;
	int		ms1_6;
	int		ms1_7;
	int		ms1_8;
	int		ms1_9;
	int		ms2_0;
	int		ms2_1;
	int		ms2_10;
	int		ms2_11;
	int		ms2_12;
	int		ms2_13;
	int		ms2_14;
	int		ms2_15;
	int		ms2_2;
	int		ms2_3;
	int		ms2_4;
	int		ms2_5;
	int		ms2_6;
	int		ms2_7;
	int		ms2_8;
	int		ms2_9;
	int		m_fc;
	int		m_f2;
	int		m_f1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDigitalCommunicationSystemDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDigitalCommunicationSystemDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnChangeId();
	afx_msg void OnChangeIntensity();
	afx_msg void OnLpf();
	afx_msg void OnBpf();
	afx_msg void OnBaseSignal();
	afx_msg void OnModulate();
	afx_msg void OnNoise();
	afx_msg void OnChannel();
	afx_msg void OnPassBpf();
	afx_msg void OnDemodulate();
	afx_msg void OnPassLpf2();
	afx_msg void OnAdjust();
	afx_msg void OnChangewc();
	afx_msg void OnPassLpf1();
	afx_msg void OnChangeseq10();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIGITALCOMMUNICATIONSYSTEMDLG_H__BCE9950D_0EA0_4CAB_BB48_681CE16625E4__INCLUDED_)
