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
	/*画时域图*/
	CWnd *pWnd=GetDlgItem(IDC_T);//获取编辑框IDC_T窗口
	CDC *pDC=pWnd->GetDC();//编辑框窗口绘图指针

	CRect rect;//新建矩形对象
	pWnd->GetClientRect(rect);//获得编辑框ID_T的矩形区域
	int W=rect.Width();//指定画图区域宽度
	int H=rect.Height();//指定画图区域高度

	RedrawWindow();//重画窗口
	CBrush newbrush;//新建画刷对象
	newbrush.CreateSolidBrush(RGB(255,255,255));//指定画刷颜色
	pDC->Rectangle(rect);//填充矩形区域背景色

	int StepX=int((W-1)/N);//根据N确定X方向的步进距离
	double maxt=Findmax(S,N);//获取序列最大值
	double StepY=(H/2-10)/(fabs(maxt));//根据序列最大值确定Y方向上的步进

	int oxt=int((W-N*StepX)/2);//起始x坐标
	int oyt=rect.bottom-int(H/2);//起始y坐标

	CPen CoordinatePen,pen;//新建画笔对象
	CoordinatePen.CreatePen(PS_SOLID,1,RGB(0,0,0));//指定画笔颜色
	pen.CreatePen(PS_SOLID,1,RGB(255,0,0));//指定画笔颜色

	pDC->SelectObject(&CoordinatePen);//选择画笔对象
	pDC->MoveTo(rect.left,oyt);//移动到最左端起始高度
	pDC->LineTo(rect.left+W,oyt);//划长度为W的横线
	pDC->SelectObject(&pen);//选择画笔对象
	pDC->MoveTo(oxt,oyt);//移动到起点
	for(int i=0;i<N;i++)//画N点序列
	{
		pDC->LineTo(oxt+i*StepX,int(oyt-StepY*S[i]));
	}
	/*画频谱图*/
	CWnd *pWnd1=GetDlgItem(IDC_F);//获取编辑框IDC_F窗口
	CDC *pDC1=pWnd1->GetDC();//获取编辑框窗口绘图指针

	CRect rect1;//新建矩形对象
	pWnd1->GetClientRect(rect1);//获得编辑框ID_F的矩形区域
	int W1=rect1.Width();//指定画图区域宽度
	int H1=rect1.Height();//指定画图区域高度

	CBrush newbrush1;//新建画刷对象
	newbrush1.CreateSolidBrush(RGB(255,255,255));//指定画刷颜色
	pDC1->Rectangle(rect1);//填充矩形区域背景色

	int StepX1=int(2*(W1-1)/N);//根据N设置X方向步进距离
	float maxt1=Findmax(Freq,int(N/2));//寻找序列最大值
	float StepY1=(4*H1/5-10)/(fabs(maxt1));//根据序列最大值确定Y方向步进距离

	int oxf=int((W1-N*StepX1/2)/2);//设置起始x坐标
	int oyf=rect1.bottom-int(H1/5);//设置起始y坐标

	CPen CoordinatePen1,pen1;//新建画笔对象
	CoordinatePen1.CreatePen(PS_SOLID,1,RGB(0,0,0));//指定画笔颜色
	pen1.CreatePen(PS_SOLID,1,RGB(0,0,255));//指定画笔颜色

	pDC1->SelectObject(&CoordinatePen1);//选择画笔对象
	pDC1->MoveTo(rect1.left,oyf);//移动到矩形框最左端起始高度处
	pDC1->LineTo(rect1.left+W1,oyf);//画长度为W1的横线
	pDC1->TextOut(oxf,oyf+5,L"0");//在指定位置显示字符“0”
	pDC1->TextOut(oxf+StepX1*N/2-StepX1*3,oyf+5,L"π");//在指定位置显示“π”
	pDC1->SelectObject(&pen1);//选择画笔对象
	pDC1->MoveTo(oxf,oyf);//移动到起始点
	for(int i=0;i<N/2;i++)//画N/2点序列
	{
		pDC1->MoveTo(oxf+StepX1*i,oyf);
		pDC1->LineTo(oxf+StepX1*i,int(oyf-StepY1*Freq[i]));
	}
	

}
void CDigitalCommunicationSystemDlg::Graph1(int *S)
{
	/*画时域图*/
	CWnd *pWnd=GetDlgItem(IDC_T);//获取编辑框IDC_T窗口
	CDC *pDC=pWnd->GetDC();//编辑框窗口绘图指针

	CRect rect;//新建矩形对象
	pWnd->GetClientRect(rect);//获得编辑框ID_T的矩形区域
	int W=rect.Width();//指定画图区域宽度
	int H=rect.Height();//指定画图区域高度

	int StepX=int((W-1)/N);//根据N确定X方向的步进距离
	double StepY=(H/2-10);//根据序列最大值确定Y方向上的步进

	int oxt=int((W-N*StepX)/2);//起始x坐标
	int oyt=rect.bottom-int(H/2);//起始y坐标

	CPen CoordinatePen,pen;//新建画笔对象
	CoordinatePen.CreatePen(PS_SOLID,1,RGB(0,255,0));//指定画笔颜色
	pen.CreatePen(PS_SOLID,1,RGB(0,255,0));//指定画笔颜色

	pDC->SelectObject(&CoordinatePen);//选择画笔对象
	pDC->MoveTo(oxt,oyt);//移动到最左端起始高度
	pDC->LineTo(oxt+W/2,oyt);//划长度为W的横线
	pDC->SelectObject(&pen);//选择画笔对象
	pDC->MoveTo(oxt,oyt);//移动到起点
	for(int i=0;i<16;i++)//画N点序列
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


	Sig.Set_ID(m_ID);//设置ID号
	Sig.Num2bin();//数字转BCD码

	int *seq;
	seq=Sig.Get_seq(1);//获取二进制序列
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

	Sig.Sample();//抽样得到离散序列

	float *x,*X;
	x=Sig.Get_s();//获取N点基带信号序列
	X=Sig.DFT(x);//DFT变换
	Graph(x,X);//显示图像

	UpdateData(false);
	
	
}

void CDigitalCommunicationSystemDlg::OnLpf() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	
	Sig.Set_wc(m_fc);//设置低通滤波器截止频率
	Sig.Set_h1();//生成低通滤波器单位脉冲响应

	float *h1,*H1;
	h1=Sig.Get_h1();//获取N+1点低通滤波器单位脉冲响应序列
	H1=Sig.DFT(h1);//DFT变换
	Graph(h1,H1);//显示图像

	UpdateData(false);
}

void CDigitalCommunicationSystemDlg::OnBpf() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	
	Sig.Set_w1(m_f1);//设置带通滤波器下截止频率
	Sig.Set_w2(m_f2);//设置带通滤波器上截止频率
	Sig.Set_h2();//生成带通滤波器单位脉冲响应

	float *h2,*H2;
	h2=Sig.Get_h2();//获取N+1点带通滤波器单位脉冲响应序列
	H2=Sig.DFT(h2);//DFT变换
	Graph(h2,H2);//显示图像

	UpdateData(false);
}

void CDigitalCommunicationSystemDlg::OnNoise() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	

	/*Sig.Set_ID(m_ID);//设置ID号
	Sig.Num2bin();//数字转BCD码
	Sig.Sample();//抽样得到离散序列*/
	Sig.Set_SNR(m_Intensity);//设置SNR的值
	Sig.Randn_Seq();//生成高斯分布随机序列
	Sig.Turn_White();//噪声白色化

	float *no,*No;
	no=Sig.Get_noise();//获取高斯白噪声序列
	No=Sig.DFT(no);//DFT变换
	Graph(no,No);//显示图像

	UpdateData(false);
}

void CDigitalCommunicationSystemDlg::OnPassLpf1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	
	/*Sig.Set_ID(m_ID);//设置ID号
	Sig.Num2bin();//数字转BCD码
	Sig.Sample();//抽样得到离散序列
	Sig.Set_wc(m_fc);//设置低通滤波器截止频率
	Sig.Set_h1();//生成低通滤波器单位脉冲响应*/
	Sig.LPF();//低通滤波

	float *x,*X;
	x=Sig.Get_s();//滤波以后的信号序列
	X=Sig.DFT(x);//DFT变换
	Graph(x,X);//显示图像

	UpdateData(false);
}

void CDigitalCommunicationSystemDlg::OnModulate() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	
	/*Sig.Set_ID(m_ID);//设置ID号
	Sig.Num2bin();//数字转BCD码
	Sig.Sample();//抽样得到离散序列
	Sig.Set_wc(m_fc);//设置低通滤波器截止频率
	Sig.Set_h1();//生成低通滤波器单位脉冲响应
	Sig.LPF();//低通滤波*/
	Sig.ASK_Mod();//ASK调制

	float *x,*X;
	x=Sig.Get_s();//调制以后的信号序列
	X=Sig.DFT(x);//DFT变换
	Graph(x,X);//显示图像

	UpdateData(false);
}

void CDigitalCommunicationSystemDlg::OnChannel() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);


	/*Sig.Set_ID(m_ID);//设置ID号
	Sig.Num2bin();//数字转BCD码
	Sig.Sample();//抽样得到离散序列
	Sig.Set_wc(m_fc);//设置低通滤波器截止频率
	Sig.Set_h1();//生成低通滤波器单位脉冲响应
	Sig.LPF();//低通滤波
	Sig.ASK_Mod();//ASK调制
	Sig.Set_SNR(m_Intensity);//设置SNR的值
	Sig.Randn_Seq();//生成高斯分布随机序列
	Sig.Turn_White();//噪声白色化*/
	Sig.Make_Noise();//叠加高斯白噪声

	float *x,*X;
	x=Sig.Get_s();//加噪以后的信号序列
	X=Sig.DFT(x);//DFT变换
	Graph(x,X);//显示图像

	UpdateData(false);
}

void CDigitalCommunicationSystemDlg::OnPassBpf() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	
	/*Sig.Set_ID(m_ID);//设置ID号
	Sig.Num2bin();//数字转BCD码
	Sig.Sample();//抽样得到离散序列
	Sig.Set_wc(m_fc);//设置低通滤波器截止频率
	Sig.Set_h1();//生成低通滤波器单位脉冲响应
	Sig.LPF();//低通滤波
	Sig.ASK_Mod();//ASK调制
	Sig.Set_SNR(m_Intensity);//设置SNR的值
	Sig.Randn_Seq();//生成高斯分布随机序列
	Sig.Turn_White();//噪声白色化
	Sig.Make_Noise();//叠加高斯白噪声
	Sig.Set_w1(m_f1);//设置带通滤波器下截止频率
	Sig.Set_w2(m_f2);//设置带通滤波器上截止频率
	Sig.Set_h2();//生成带通滤波器单位脉冲响应*/
	Sig.BPF();//带通滤波

	float *x,*X;
	x=Sig.Get_s();//滤波以后的信号序列
	X=Sig.DFT(x);//DFT变换
	Graph(x,X);//显示图像

	UpdateData(false);
}

void CDigitalCommunicationSystemDlg::OnDemodulate() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	
	/*Sig.Set_ID(m_ID);//设置ID号
	Sig.Num2bin();//数字转BCD码
	Sig.Sample();//抽样得到离散序列
	Sig.Set_wc(m_fc);//设置低通滤波器截止频率
	Sig.Set_h1();//生成低通滤波器单位脉冲响应
	Sig.LPF();//低通滤波
	Sig.ASK_Mod();//ASK调制
	Sig.Set_SNR(m_Intensity);//设置SNR的值
	Sig.Randn_Seq();//生成高斯分布随机序列
	Sig.Turn_White();//噪声白色化
	Sig.Make_Noise();//叠加高斯白噪声
	Sig.Set_w1(m_f1);//设置带通滤波器下截止频率
	Sig.Set_w2(m_f2);//设置带通滤波器上截止频率
	Sig.Set_h2();//生成带通滤波器单位脉冲响应
	Sig.BPF();//带通滤波*/
	Sig.ASK_Demod();//ASK相干解调

	float *x,*X;
	x=Sig.Get_s();//解调以后的信号序列
	X=Sig.DFT(x);//DFT变换
	Graph(x,X);//显示图像

	UpdateData(false);
}

void CDigitalCommunicationSystemDlg::OnPassLpf2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	
	/*Sig.Set_ID(m_ID);//设置ID号
	Sig.Num2bin();//数字转BCD码
	Sig.Sample();//抽样得到离散序列
	Sig.Set_wc(m_fc);//设置低通滤波器截止频率
	Sig.Set_h1();//生成低通滤波器单位脉冲响应
	Sig.LPF();//低通滤波
	Sig.ASK_Mod();//ASK调制
	Sig.Set_SNR(m_Intensity);//设置SNR的值
	Sig.Randn_Seq();//生成高斯分布随机序列
	Sig.Turn_White();//噪声白色化
	Sig.Make_Noise();//叠加高斯白噪声
	Sig.Set_w1(m_f1);//设置带通滤波器下截止频率
	Sig.Set_w2(m_f2);//设置带通滤波器上截止频率
	Sig.Set_h2();//生成带通滤波器单位脉冲响应
	Sig.BPF();//带通滤波
	Sig.ASK_Demod();//ASK相干解调*/
	Sig.LPF();//低通滤波

	float *x,*X;
	x=Sig.Get_s();//滤波以后的信号序列
	X=Sig.DFT(x);//DFT变换
	Graph(x,X);//显示图像

	UpdateData(false);
}

void CDigitalCommunicationSystemDlg::OnAdjust() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	
	/*Sig.Set_ID(m_ID);//设置ID号
	Sig.Num2bin();//数字转BCD码
	Sig.Sample();//抽样得到离散序列
	Sig.Set_wc(m_fc);//设置低通滤波器截止频率
	Sig.Set_h1();//生成低通滤波器单位脉冲响应
	Sig.LPF();//低通滤波
	Sig.ASK_Mod();//ASK调制
	Sig.Set_SNR(m_Intensity);//设置SNR的值
	Sig.Randn_Seq();//生成高斯分布随机序列
	Sig.Turn_White();//噪声白色化
	Sig.Make_Noise();//叠加高斯白噪声
	Sig.Set_w1(m_f1);//设置带通滤波器下截止频率
	Sig.Set_w2(m_f2);//设置带通滤波器上截止频率
	Sig.Set_h2();//生成带通滤波器单位脉冲响应
	Sig.BPF();//带通滤波
	Sig.ASK_Demod();//ASK相干解调
	Sig.LPF();//低通滤波
	float *x,*X;
	x=Sig.Get_s();//滤波以后的信号序列
	X=Sig.DFT(x);//DFT变换
	Graph(x,X);//显示图像*/
	Sig.Sample_Judge();//抽样判决

	int *seq;
	seq=Sig.Get_seq(2);//抽样判决得到的二进制序列
	Graph1(seq);//抽样判决显示
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
