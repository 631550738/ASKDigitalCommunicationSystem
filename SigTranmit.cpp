// SigTranmit.cpp: implementation of the SigTranmit class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DigitalCommunicationSystem.h"
#include "SigTranmit.h"
#include "math.h"
#include "time.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SigTranmit::SigTranmit()
{
	wc=2*pi*200/fs;//低通滤波器截止频率
	w1=2*pi*800/fs;//带通滤波器下截止频率
	w2=2*pi*1200/fs;//带通滤波器上截止频率

	myID=85;//初始ID号
	mySNR=20;//初始信噪比20dB

}
void SigTranmit::Set_ID(int ID)
{
	myID=ID;//学号
}
void SigTranmit::Set_SNR(int SNR)
{
	mySNR=SNR;//信噪比
}
void SigTranmit::Set_wc(float f)
{
	wc=2*pi*f/fs;//低通滤波器截止频率
}
void SigTranmit::Set_w1(float f)
{
	w1=2*pi*f/fs;//带通滤波器下截止频率
}
void SigTranmit::Set_w2(float f)
{
	w2=2*pi*f/fs;//带通滤波器上截止频率
}
float *SigTranmit::Conv(float *s1,float *s2)//卷积函数
{
	float sum;
	float s3[2*N];
	for(int n=0;n<2*N;n++)
	{
		sum=0;
		for(int m=0;m<N;m++)
		{
			if((n-m>=0)&&(n-m<N+1))
			{
				sum+=s1[m]*s2[n-m];
			}
		}
		s3[n]=sum/10;
	}
	return s3;
}
float *SigTranmit::DFT(float *x)//离散傅里叶变换
{
	float temp;
	for(int k=0;k<N;k++)
	{
		float real=0.0,imag=0.0;
		for(int n=0;n<N;n++)
		{
			temp=2*pi/N*k*n;
			real+=x[n]*cos(temp);
			imag+=x[n]*sin(temp);
		}		
		S[k]=sqrt(real*real+imag*imag)/20;
	}
	return S;
}
void SigTranmit::Num2bin()//十进制转BCD码
{
	int temp;
	for(int i=0;i<4;i++)
	{
		temp=myID/(int)pow(10.0,3-i)%10;
		for(int j=0;j<4;j++)
		{
			seq1[4*i+j]=(temp>>(3-j))&0x01;
		}
	}
}
void SigTranmit::Sample()//采样函数
{
	for(int i=0;i<16;i++)
	{
		for(int j=0;j<N/16;j++)
		{
			if(seq1[i]==1)
			{
				s[i*N/16+j]=1;
			}
			else if(seq1[i]==0)
			{
				s[i*N/16+j]=0;
			}
		}
	}
}
void SigTranmit::Set_h1()//设置低通滤波器h1[N+1]的值
{
	int a=N/2;
	for(int n=0;n<N+1;n++)
	{
		if(n!=a)
		{
			h1[n]=20*sin(wc*(n-a))/(pi*(n-a))*(0.54-0.46*cos(2*pi*n/N));
		}
		else
		{
			h1[n]=20*wc/pi*(0.54-0.46*cos(2*pi*n/N));
		}
	}
}
void SigTranmit::Set_h2()//设置带通滤波器h2[N+1]的值
{
	int a=N/2;
	for(int n=0;n<N+1;n++)
	{
		if(n!=a)
		{
			h2[n]=10*(sin(w2*(n-a))/(pi*(n-a))-sin(w1*(n-a))/(pi*(n-a)))*(0.54-0.46*cos(2*pi*n/N));
		}
		else
		{
			h2[n]=10*(w2/pi-w1/pi)*(0.54-0.46*cos(2*pi*n/N));
		}
	}
}
float SigTranmit::Random(float min,float max)//生成min~max之间均匀分布的一个随机数
{
	return min+(max-min)*rand()/(RAND_MAX+1.0);
}
float SigTranmit::Normal(float x, float miu,float sigma)//求均值为miu，方差为sigma的正态分布函数在x处的函数值
{
    return 1.0/sqrt(2*pi)/sigma*exp(-1*(x-miu)*(x-miu)/(2*sigma*sigma));
}
float SigTranmit::Randn()//生成一个高斯分布随机数
{
	//舍选抽样法
	float x,y,dScope;

	do{

		x=Random(-3.0,3.0);

		y=Normal(x,0,1);

		dScope=Random(0.0,Normal(0,0,1));

	}while(dScope>y);

	return x;
}
void SigTranmit::Randn_Seq()//生成高斯分布随机数列
{
	float p[10]={0.1179,0.1078,0.0902,0.069,0.0483,0.0309,0.018,0.0097,0.0047,0.0022};//（-3,3）区间20等分正太分布概率值
	int num[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//20等分区间高斯分布随机数观测频数
	for(int i=0;i<10;i++)
	{
		float temp=p[i]*N;
		if(temp>floor(temp)+0.5)//四舍五入
		{
			num[i+10]=ceil(temp);
			num[9-i]=ceil(temp);
		}
		else
		{
			num[i+10]=floor(temp);
			num[9-i]=floor(temp);
		}
	}
	int num2[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//实际观测频数
	int k=0;//记录当前产生序列号数，0~N
	float temp;//储存临时随机数
	float sum=0;
	
	/*对随机数进行筛选，使最后生成的数列满足高斯分布概率要求*/
	do
	{
		sum=0;
		k=0;
		while(k<N)
		{
			temp=Randn();//获取随机数
		
			for(int i=0;i<20;i++)//20个区间依次遍历
			{
				if((temp>=-3.0+0.3*i)&&(temp<-3.0+0.3*(i+1)))//落在该区间
				{
					if(num2[i]<num[i])//出现频数未满
					{
						num2[i]++;//计数加一
						noise[k]=temp;//保留该随机数
						k++;//序列数加一	
					}
					break;
				}
			}
		
		}
		for(int i=0;i<N;i++)//计算序列和
		{
			sum+=noise[i];
		}
	}while(sum/N>0.01||sum/N<-0.01);//使随机数序列的均值在给定的误差范围之内

}
void SigTranmit::Turn_White()//噪声白色化
{
	float S1=0.0,S0=0.0;
	float r[N];
	for(int k=0;k<N;k++)//计算初始的自相关函数（未经交换时）
	{
		r[k]=0.0;
		for(int j=0;j<N-k;j++)
		{
			r[k]+=noise[j]*noise[j+k];//自相关函数值	
		}
		S1+=r[k]*r[k];//计算平方和
	}
	S1=S1/N/N;
	for(int i=0;i<1000;i++)
	{
		S0=S1;//将当前计算结果存入S0，准备进行下一次计算
		int r1,r2;
		r1=Random(0,N-1);//生成两个随机数
		r2=Random(0,N-1);
		float temp;
		/*双随机交换*/
		temp=noise[r1];
		noise[r1]=noise[r2];
		noise[r2]=temp;
		for(int k=0;k<N;k++)//计算自相关函数
		{
			r[k]=0.0;
			for(int j=0;j<N-k;j++)
			{
				r[k]+=noise[j]*noise[j+k];//自相关函数值
			}
			S1+=r[k]*r[k];//计算平方和
		}
		S1=S1/N/N;
		if(S1>S0)//第i次的结果大于第i-1次时，放弃交换
		{
			temp=noise[r1];
			noise[r1]=noise[r2];
			noise[r2]=temp;
		}
		if(S1<0.01)
		{
			break;
		}
	}
}
void SigTranmit::LPF()//低通滤波
{
	s_c=Conv(s,h1);
	for(int i=0;i<N;i++)//从滤波后的序列中截取有效长度为N的序列，以消除滤波器的延时特性
	{
		s[i]=s_c[N/2+i];
	}
}
void SigTranmit::ASK_Mod()//ASK调制
{
	for(int i=0;i<N;i++)
	{
		s[i]=s[i]*cos(2*pi*fc*i/fs);
	}
}
void SigTranmit::Make_Noise()//叠加高斯白噪声
{
	float Ps=0.0,Pn=0.0,Pn2,k;
	for(int j=0;j<N;j++)
	{
		Ps+=s[j]*s[j];
		Pn+=noise[j]*noise[j];
	}
	Pn2=Ps/pow(10,mySNR/10);
	k=sqrt(Pn2/Pn);
	for(int j=0;j<N;j++)
	{
		s[j]=s[j]+k*noise[j];
	}
}
void SigTranmit::BPF()//带通滤波
{
	s_c=Conv(s,h2);
	for(int i=0;i<N;i++)
	{
		s[i]=s_c[N/2+i];
	}
}
void SigTranmit::ASK_Demod()//ASK相干解调
{
	for(int i=0;i<N;i++)
	{
		s[i]=s[i]*cos(2*pi*fc*i/fs);
	}
}
void SigTranmit::Sample_Judge()//抽样判决
{
	float sum=0,sum0=0;//sum存储N点序列值平方之和
	float s2[16];//存储长度为N/16的各区间的序列值平方之和
	for(int i=0;i<N;i++)
	{
		sum+=s[i]*s[i];
		if((i+1)%(N/16)==0)
		{
			s2[i/(N/16)]=(sum-sum0)/(N/16);
			sum0=sum;
		}
	}
	for(int i=0;i<16;i++)
	{
		if(s2[i]>=sum/N)
		{
			seq2[i]=1;
		}
		else
		{
			seq2[i]=0;
		}
	}
}
int *SigTranmit::Get_seq(int num)//获取二进制序列
{	
	if(num==2)
	{
		return seq2;
	}
	return seq1;
}
float *SigTranmit::Get_s()//获取各个环节的信号序列
{
	return s;
}
float *SigTranmit::Get_h1()//获取低通滤波器单位脉冲响应
{
	return h1;
}
float *SigTranmit::Get_h2()//获取低通滤波器单位脉冲响应
{
	return h2;
}
float *SigTranmit::Get_noise()//获取高斯白噪声序列
{
	return noise;
}
SigTranmit::~SigTranmit()
{

}
