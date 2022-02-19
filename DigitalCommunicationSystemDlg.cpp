// DigitalCommunicationSystemDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DigitalCommunicationSystem.h"
#include "DigitalCommunicationSystemDlg.h"
#include "SigTranmit.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDigitalCommunicationSystemDlg dialog

CDigitalCommunicationSystemDlg::CDigitalCommunicationSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDigitalCommunicationSystemDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDigitalCommunicationSystemDlg)
	m_ID = 85;
	m_Intensity = 20;
	ms1_0 = 0;
	ms1_1 = 0;
	ms1_10 = 0;
	ms1_11 = 0;
	ms1_12 = 0;
	ms1_13 = 0;
	ms1_14 = 0;
	ms1_15 = 0;
	ms1_2 = 0;
	ms1_3 = 0;
	ms1_4 = 0;
	ms1_5 = 0;
	ms1_6 = 0;
	ms1_7 = 0;
	ms1_8 = 0;
	ms1_9 = 0;
	ms2_0 = 0;
	ms2_1 = 0;
	ms2_10 = 0;
	ms2_11 = 0;
	ms2_12 = 0;
	ms2_13 = 0;
	ms2_14 = 0;
	ms2_15 = 0;
	ms2_2 = 0;
	ms2_3 = 0;
	ms2_4 = 0;
	ms2_5 = 0;
	ms2_6 = 0;
	ms2_7 = 0;
	ms2_8 = 0;
	ms2_9 = 0;
	m_fc = 200;
	m_f2 = 1200;
	m_f1 = 800;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDigitalCommunicationSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDigitalCommunicationSystemDlg)
	DDX_Text(pDX, IDC_ID, m_ID);
	DDV_MinMaxInt(pDX, m_ID, 0, 9999);
	DDX_Text(pDX, IDC_Intensity, m_Intensity);
	DDV_MinMaxInt(pDX, m_Intensity, 0, 40);
	DDX_Text(pDX, IDC_seq1_0, ms1_0);
	DDX_Text(pDX, IDC_seq1_1, ms1_1);
	DDX_Text(pDX, IDC_seq1_10, ms1_10);
	DDX_Text(pDX, IDC_seq1_11, ms1_11);
	DDX_Text(pDX, IDC_seq1_12, ms1_12);
	DDX_Text(pDX, IDC_seq1_13, ms1_13);
	DDX_Text(pDX, IDC_seq1_14, ms1_14);
	DDX_Text(pDX, IDC_seq1_15, ms1_15);
	DDX_Text(pDX, IDC_seq1_2, ms1_2);
	DDX_Text(pDX, IDC_seq1_3, ms1_3);
	DDX_Text(pDX, IDC_seq1_4, ms1_4);
	DDX_Text(pDX, IDC_seq1_5, ms1_5);
	DDX_Text(pDX, IDC_seq1_6, ms1_6);
	DDX_Text(pDX, IDC_seq1_7, ms1_7);
	DDX_Text(pDX, IDC_seq1_8, ms1_8);
	DDX_Text(pDX, IDC_seq1_9, ms1_9);
	DDX_Text(pDX, IDC_seq2_0, ms2_0);
	DDX_Text(pDX, IDC_seq2_1, ms2_1);
	DDX_Text(pDX, IDC_seq2_10, ms2_10);
	DDX_Text(pDX, IDC_seq2_11, ms2_11);
	DDX_Text(pDX, IDC_seq2_12, ms2_12);
	DDX_Text(pDX, IDC_seq2_13, ms2_13);
	DDX_Text(pDX, IDC_seq2_14, ms2_14);
	DDX_Text(pDX, IDC_seq2_15, ms2_15);
	DDX_Text(pDX, IDC_seq2_2, ms2_2);
	DDX_Text(pDX, IDC_seq2_3, ms2_3);
	DDX_Text(pDX, IDC_Eseq2_4, ms2_4);
	DDX_Text(pDX, IDC_seq2_5, ms2_5);
	DDX_Text(pDX, IDC_seq2_6, ms2_6);
	DDX_Text(pDX, IDC_seq2_7, ms2_7);
	DDX_Text(pDX, IDC_seq2_8, ms2_8);
	DDX_Text(pDX, IDC_seq2_9, ms2_9);
	DDX_Text(pDX, IDC_wc, m_fc);
	DDV_MinMaxInt(pDX, m_fc, 0, 400);
	DDX_Text(pDX, IDC_w2, m_f2);
	DDV_MinMaxInt(pDX, m_f2, 1000, 1300);
	DDX_Text(pDX, IDC_w1, m_f1);
	DDV_MinMaxInt(pDX, m_f1, 700, 1000);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDigitalCommunicationSystemDlg, CDialog)
	//{{AFX_MSG_MAP(CDigitalCommunicationSystemDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_ID, OnChangeId)
	ON_EN_CHANGE(IDC_Intensity, OnChangeIntensity)
	ON_BN_CLICKED(IDC_Lpf, OnLpf)
	ON_BN_CLICKED(IDC_Bpf, OnBpf)
	ON_BN_CLICKED(IDC_BaseSignal, OnBaseSignal)
	ON_BN_CLICKED(IDC_Modulate, OnModulate)
	ON_BN_CLICKED(IDC_Noise, OnNoise)
	ON_BN_CLICKED(IDC_Channel, OnChannel)
	ON_BN_CLICKED(IDC_PassBpf, OnPassBpf)
	ON_BN_CLICKED(IDC_Demodulate, OnDemodulate)
	ON_BN_CLICKED(IDC_PassLpf2, OnPassLpf2)
	ON_BN_CLICKED(IDC_Adjust, OnAdjust)
	ON_EN_CHANGE(IDC_wc, OnChangewc)
	ON_BN_CLICKED(IDC_PassLpf1, OnPassLpf1)
	ON_EN_CHANGE(IDC_seq1_0, OnChangeseq10)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDigitalCommunicationSystemDlg message handlers

BOOL CDigitalCommunicationSystemDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDigitalCommunicationSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDigitalCommunicationSystemDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDigitalCommunicationSystemDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
float CDigitalCommunicationSystemDlg::Findmax(float S[],int n)
{
	float temp=S[0];
	for(int i=1;i<n;i++)
	{
		if(S[i]>temp)
		{
			temp=S[i];
		}
	}
	return temp;
}
void CDigitalCommunicationSystemDlg::Graph(float S[],float Freq[])
{
	/*��ʱ��ͼ*/
	CWnd *pWnd=GetDlgItem(IDC_T);//��ȡ�༭��IDC_T����
	CDC *pDC=pWnd->GetDC();//�༭�򴰿ڻ�ͼָ��

	CRect rect;//�½����ζ���
	pWnd->GetClientRect(rect);//��ñ༭��ID_T�ľ�������
	int W=rect.Width();//ָ����ͼ������
	int H=rect.Height();//ָ����ͼ����߶�

	RedrawWindow();//�ػ�����
	CBrush newbrush;//�½���ˢ����
	newbrush.CreateSolidBrush(RGB(255,255,255));//ָ����ˢ��ɫ
	pDC->Rectangle(rect);//���������򱳾�ɫ

	int StepX=int((W-1)/N);//����Nȷ��X����Ĳ�������
	double maxt=Findmax(S,N);//��ȡ�������ֵ
	double StepY=(H/2-10)/(fabs(maxt));//�����������ֵȷ��Y�����ϵĲ���

	int oxt=int((W-N*StepX)/2);//��ʼx����
	int oyt=rect.bottom-int(H/2);//��ʼy����

	CPen CoordinatePen,pen;//�½����ʶ���
	CoordinatePen.CreatePen(PS_SOLID,1,RGB(0,0,0));//ָ��������ɫ
	pen.CreatePen(PS_SOLID,1,RGB(255,0,0));//ָ��������ɫ

	pDC->SelectObject(&CoordinatePen);//ѡ�񻭱ʶ���
	pDC->MoveTo(rect.left,oyt);//�ƶ����������ʼ�߶�
	pDC->LineTo(rect.left+W,oyt);//������ΪW�ĺ���
	pDC->SelectObject(&pen);//ѡ�񻭱ʶ���
	pDC->MoveTo(oxt,oyt);//�ƶ������
	for(int i=0;i<N;i++)//��N������
	{
		pDC->LineTo(oxt+i*StepX,int(oyt-StepY*S[i]));
	}
	/*��Ƶ��ͼ*/
	CWnd *pWnd1=GetDlgItem(IDC_F);//��ȡ�༭��IDC_F����
	CDC *pDC1=pWnd1->GetDC();//��ȡ�༭�򴰿ڻ�ͼָ��

	CRect rect1;//�½����ζ���
	pWnd1->GetClientRect(rect1);//��ñ༭��ID_F�ľ�������
	int W1=rect1.Width();//ָ����ͼ������
	int H1=rect1.Height();//ָ����ͼ����߶�

	CBrush newbrush1;//�½���ˢ����
	newbrush1.CreateSolidBrush(RGB(255,255,255));//ָ����ˢ��ɫ
	pDC1->Rectangle(rect1);//���������򱳾�ɫ

	int StepX1=int(2*(W1-1)/N);//����N����X���򲽽�����
	float maxt1=Findmax(Freq,int(N/2));//Ѱ���������ֵ
	float StepY1=(4*H1/5-10)/(fabs(maxt1));//�����������ֵȷ��Y���򲽽�����

	int oxf=int((W1-N*StepX1/2)/2);//������ʼx����
	int oyf=rect1.bottom-int(H1/5);//������ʼy����

	CPen CoordinatePen1,pen1;//�½����ʶ���
	CoordinatePen1.CreatePen(PS_SOLID,1,RGB(0,0,0));//ָ��������ɫ
	pen1.CreatePen(PS_SOLID,1,RGB(0,0,255));//ָ��������ɫ

	pDC1->SelectObject(&CoordinatePen1);//ѡ�񻭱ʶ���
	pDC1->MoveTo(rect1.left,oyf);//�ƶ������ο��������ʼ�߶ȴ�
	pDC1->LineTo(rect1.left+W1,oyf);//������ΪW1�ĺ���
	pDC1->TextOut(oxf,oyf+5,L"0");//��ָ��λ����ʾ�ַ���0��
	pDC1->TextOut(oxf+StepX1*N/2-StepX1*3,oyf+5,L"��");//��ָ��λ����ʾ���С�
	pDC1->SelectObject(&pen1);//ѡ�񻭱ʶ���
	pDC1->MoveTo(oxf,oyf);//�ƶ�����ʼ��
	for(int i=0;i<N/2;i++)//��N/2������
	{
		pDC1->MoveTo(oxf+StepX1*i,oyf);
		pDC1->LineTo(oxf+StepX1*i,int(oyf-StepY1*Freq[i]));
	}
	

}
void CDigitalCommunicationSystemDlg::Graph1(int *S)
{
	/*��ʱ��ͼ*/
	CWnd *pWnd=GetDlgItem(IDC_T);//��ȡ�༭��IDC_T����
	CDC *pDC=pWnd->GetDC();//�༭�򴰿ڻ�ͼָ��

	CRect rect;//�½����ζ���
	pWnd->GetClientRect(rect);//��ñ༭��ID_T�ľ�������
	int W=rect.Width();//ָ����ͼ������
	int H=rect.Height();//ָ����ͼ����߶�

	int StepX=int((W-1)/N);//����Nȷ��X����Ĳ�������
	double StepY=(H/2-10);//�����������ֵȷ��Y�����ϵĲ���

	int oxt=int((W-N*StepX)/2);//��ʼx����
	int oyt=rect.bottom-int(H/2);//��ʼy����

	CPen CoordinatePen,pen;//�½����ʶ���
	CoordinatePen.CreatePen(PS_SOLID,1,RGB(0,255,0));//ָ��������ɫ
	pen.CreatePen(PS_SOLID,1,RGB(0,255,0));//ָ��������ɫ

	pDC->SelectObject(&CoordinatePen);//ѡ�񻭱ʶ���
	pDC->MoveTo(oxt,oyt);//�ƶ����������ʼ�߶�
	pDC->LineTo(oxt+W/2,oyt);//������ΪW�ĺ���
	pDC->SelectObject(&pen);//ѡ�񻭱ʶ���
	pDC->MoveTo(oxt,oyt);//�ƶ������
	for(int i=0;i<16;i++)//��N������
	{
		for(int j=0;j<N/16;j++)
		{
			if(S[i]==1)
			{
				pDC->LineTo(oxt+(i*N/16+j)*StepX,int(oyt-StepY));
				if(j==N/16/2)
				{
					pDC->TextOut(oxt+(i*N/16+j)*StepX,int(oyt-StepY/2),L"1");
				}
			}
			else if(S[i]==0)
			{
				pDC->LineTo(oxt+(i*N/16+j)*StepX,int(oyt));
				if(j==N/16/2)
				{
					pDC->TextOut(oxt+(i*N/16+j)*StepX,int(oyt-StepY/2),L"0");
				}
			}
			
		}
	}
}
void CDigitalCommunicationSystemDlg::OnChangeId() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CDigitalCommunicationSystemDlg::OnChangeIntensity() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CDigitalCommunicationSystemDlg::OnBaseSignal() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);


	Sig.Set_ID(m_ID);//����ID��
	Sig.Num2bin();//����תBCD��

	int *seq;
	seq=Sig.Get_seq(1);//��ȡ����������
	ms1_0=seq[0];
	ms1_1=seq[1];
	ms1_2=seq[2];
	ms1_3=seq[3];
	ms1_4=seq[4];
	ms1_5=seq[5];
	ms1_6=seq[6];
	ms1_7=seq[7];
	ms1_8=seq[8];
	ms1_9=seq[9];
	ms1_10=seq[10];
	ms1_11=seq[11];
	ms1_12=seq[12];
	ms1_13=seq[13];
	ms1_14=seq[14];
	ms1_15=seq[15];

	Sig.Sample();//�����õ���ɢ����

	float *x,*X;
	x=Sig.Get_s();//��ȡN������ź�����
	X=Sig.DFT(x);//DFT�任
	Graph(x,X);//��ʾͼ��

	UpdateData(false);
	
	
}

void CDigitalCommunicationSystemDlg::OnLpf() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	
	Sig.Set_wc(m_fc);//���õ�ͨ�˲�����ֹƵ��
	Sig.Set_h1();//���ɵ�ͨ�˲�����λ������Ӧ

	float *h1,*H1;
	h1=Sig.Get_h1();//��ȡN+1���ͨ�˲�����λ������Ӧ����
	H1=Sig.DFT(h1);//DFT�任
	Graph(h1,H1);//��ʾͼ��

	UpdateData(false);
}

void CDigitalCommunicationSystemDlg::OnBpf() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	
	Sig.Set_w1(m_f1);//���ô�ͨ�˲����½�ֹƵ��
	Sig.Set_w2(m_f2);//���ô�ͨ�˲����Ͻ�ֹƵ��
	Sig.Set_h2();//���ɴ�ͨ�˲�����λ������Ӧ

	float *h2,*H2;
	h2=Sig.Get_h2();//��ȡN+1���ͨ�˲�����λ������Ӧ����
	H2=Sig.DFT(h2);//DFT�任
	Graph(h2,H2);//��ʾͼ��

	UpdateData(false);
}

void CDigitalCommunicationSystemDlg::OnNoise() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	

	/*Sig.Set_ID(m_ID);//����ID��
	Sig.Num2bin();//����תBCD��
	Sig.Sample();//�����õ���ɢ����*/
	Sig.Set_SNR(m_Intensity);//����SNR��ֵ
	Sig.Randn_Seq();//���ɸ�˹�ֲ��������
	Sig.Turn_White();//������ɫ��

	float *no,*No;
	no=Sig.Get_noise();//��ȡ��˹����������
	No=Sig.DFT(no);//DFT�任
	Graph(no,No);//��ʾͼ��

	UpdateData(false);
}

void CDigitalCommunicationSystemDlg::OnPassLpf1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	
	/*Sig.Set_ID(m_ID);//����ID��
	Sig.Num2bin();//����תBCD��
	Sig.Sample();//�����õ���ɢ����
	Sig.Set_wc(m_fc);//���õ�ͨ�˲�����ֹƵ��
	Sig.Set_h1();//���ɵ�ͨ�˲�����λ������Ӧ*/
	Sig.LPF();//��ͨ�˲�

	float *x,*X;
	x=Sig.Get_s();//�˲��Ժ���ź�����
	X=Sig.DFT(x);//DFT�任
	Graph(x,X);//��ʾͼ��

	UpdateData(false);
}

void CDigitalCommunicationSystemDlg::OnModulate() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	
	/*Sig.Set_ID(m_ID);//����ID��
	Sig.Num2bin();//����תBCD��
	Sig.Sample();//�����õ���ɢ����
	Sig.Set_wc(m_fc);//���õ�ͨ�˲�����ֹƵ��
	Sig.Set_h1();//���ɵ�ͨ�˲�����λ������Ӧ
	Sig.LPF();//��ͨ�˲�*/
	Sig.ASK_Mod();//ASK����

	float *x,*X;
	x=Sig.Get_s();//�����Ժ���ź�����
	X=Sig.DFT(x);//DFT�任
	Graph(x,X);//��ʾͼ��

	UpdateData(false);
}

void CDigitalCommunicationSystemDlg::OnChannel() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);


	/*Sig.Set_ID(m_ID);//����ID��
	Sig.Num2bin();//����תBCD��
	Sig.Sample();//�����õ���ɢ����
	Sig.Set_wc(m_fc);//���õ�ͨ�˲�����ֹƵ��
	Sig.Set_h1();//���ɵ�ͨ�˲�����λ������Ӧ
	Sig.LPF();//��ͨ�˲�
	Sig.ASK_Mod();//ASK����
	Sig.Set_SNR(m_Intensity);//����SNR��ֵ
	Sig.Randn_Seq();//���ɸ�˹�ֲ��������
	Sig.Turn_White();//������ɫ��*/
	Sig.Make_Noise();//���Ӹ�˹������

	float *x,*X;
	x=Sig.Get_s();//�����Ժ���ź�����
	X=Sig.DFT(x);//DFT�任
	Graph(x,X);//��ʾͼ��

	UpdateData(false);
}

void CDigitalCommunicationSystemDlg::OnPassBpf() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	
	/*Sig.Set_ID(m_ID);//����ID��
	Sig.Num2bin();//����תBCD��
	Sig.Sample();//�����õ���ɢ����
	Sig.Set_wc(m_fc);//���õ�ͨ�˲�����ֹƵ��
	Sig.Set_h1();//���ɵ�ͨ�˲�����λ������Ӧ
	Sig.LPF();//��ͨ�˲�
	Sig.ASK_Mod();//ASK����
	Sig.Set_SNR(m_Intensity);//����SNR��ֵ
	Sig.Randn_Seq();//���ɸ�˹�ֲ��������
	Sig.Turn_White();//������ɫ��
	Sig.Make_Noise();//���Ӹ�˹������
	Sig.Set_w1(m_f1);//���ô�ͨ�˲����½�ֹƵ��
	Sig.Set_w2(m_f2);//���ô�ͨ�˲����Ͻ�ֹƵ��
	Sig.Set_h2();//���ɴ�ͨ�˲�����λ������Ӧ*/
	Sig.BPF();//��ͨ�˲�

	float *x,*X;
	x=Sig.Get_s();//�˲��Ժ���ź�����
	X=Sig.DFT(x);//DFT�任
	Graph(x,X);//��ʾͼ��

	UpdateData(false);
}

void CDigitalCommunicationSystemDlg::OnDemodulate() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	
	/*Sig.Set_ID(m_ID);//����ID��
	Sig.Num2bin();//����תBCD��
	Sig.Sample();//�����õ���ɢ����
	Sig.Set_wc(m_fc);//���õ�ͨ�˲�����ֹƵ��
	Sig.Set_h1();//���ɵ�ͨ�˲�����λ������Ӧ
	Sig.LPF();//��ͨ�˲�
	Sig.ASK_Mod();//ASK����
	Sig.Set_SNR(m_Intensity);//����SNR��ֵ
	Sig.Randn_Seq();//���ɸ�˹�ֲ��������
	Sig.Turn_White();//������ɫ��
	Sig.Make_Noise();//���Ӹ�˹������
	Sig.Set_w1(m_f1);//���ô�ͨ�˲����½�ֹƵ��
	Sig.Set_w2(m_f2);//���ô�ͨ�˲����Ͻ�ֹƵ��
	Sig.Set_h2();//���ɴ�ͨ�˲�����λ������Ӧ
	Sig.BPF();//��ͨ�˲�*/
	Sig.ASK_Demod();//ASK��ɽ��

	float *x,*X;
	x=Sig.Get_s();//����Ժ���ź�����
	X=Sig.DFT(x);//DFT�任
	Graph(x,X);//��ʾͼ��

	UpdateData(false);
}

void CDigitalCommunicationSystemDlg::OnPassLpf2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	
	/*Sig.Set_ID(m_ID);//����ID��
	Sig.Num2bin();//����תBCD��
	Sig.Sample();//�����õ���ɢ����
	Sig.Set_wc(m_fc);//���õ�ͨ�˲�����ֹƵ��
	Sig.Set_h1();//���ɵ�ͨ�˲�����λ������Ӧ
	Sig.LPF();//��ͨ�˲�
	Sig.ASK_Mod();//ASK����
	Sig.Set_SNR(m_Intensity);//����SNR��ֵ
	Sig.Randn_Seq();//���ɸ�˹�ֲ��������
	Sig.Turn_White();//������ɫ��
	Sig.Make_Noise();//���Ӹ�˹������
	Sig.Set_w1(m_f1);//���ô�ͨ�˲����½�ֹƵ��
	Sig.Set_w2(m_f2);//���ô�ͨ�˲����Ͻ�ֹƵ��
	Sig.Set_h2();//���ɴ�ͨ�˲�����λ������Ӧ
	Sig.BPF();//��ͨ�˲�
	Sig.ASK_Demod();//ASK��ɽ��*/
	Sig.LPF();//��ͨ�˲�

	float *x,*X;
	x=Sig.Get_s();//�˲��Ժ���ź�����
	X=Sig.DFT(x);//DFT�任
	Graph(x,X);//��ʾͼ��

	UpdateData(false);
}

void CDigitalCommunicationSystemDlg::OnAdjust() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	
	/*Sig.Set_ID(m_ID);//����ID��
	Sig.Num2bin();//����תBCD��
	Sig.Sample();//�����õ���ɢ����
	Sig.Set_wc(m_fc);//���õ�ͨ�˲�����ֹƵ��
	Sig.Set_h1();//���ɵ�ͨ�˲�����λ������Ӧ
	Sig.LPF();//��ͨ�˲�
	Sig.ASK_Mod();//ASK����
	Sig.Set_SNR(m_Intensity);//����SNR��ֵ
	Sig.Randn_Seq();//���ɸ�˹�ֲ��������
	Sig.Turn_White();//������ɫ��
	Sig.Make_Noise();//���Ӹ�˹������
	Sig.Set_w1(m_f1);//���ô�ͨ�˲����½�ֹƵ��
	Sig.Set_w2(m_f2);//���ô�ͨ�˲����Ͻ�ֹƵ��
	Sig.Set_h2();//���ɴ�ͨ�˲�����λ������Ӧ
	Sig.BPF();//��ͨ�˲�
	Sig.ASK_Demod();//ASK��ɽ��
	Sig.LPF();//��ͨ�˲�
	float *x,*X;
	x=Sig.Get_s();//�˲��Ժ���ź�����
	X=Sig.DFT(x);//DFT�任
	Graph(x,X);//��ʾͼ��*/
	Sig.Sample_Judge();//�����о�

	int *seq;
	seq=Sig.Get_seq(2);//�����о��õ��Ķ���������
	Graph1(seq);//�����о���ʾ
	ms2_0=seq[0];
	ms2_1=seq[1];
	ms2_2=seq[2];
	ms2_3=seq[3];
	ms2_4=seq[4];
	ms2_5=seq[5];
	ms2_6=seq[6];
	ms2_7=seq[7];
	ms2_8=seq[8];
	ms2_9=seq[9];
	ms2_10=seq[10];
	ms2_11=seq[11];
	ms2_12=seq[12];
	ms2_13=seq[13];
	ms2_14=seq[14];
	ms2_15=seq[15];

	UpdateData(false);
}

void CDigitalCommunicationSystemDlg::OnChangewc() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}



void CDigitalCommunicationSystemDlg::OnChangeseq10() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}
