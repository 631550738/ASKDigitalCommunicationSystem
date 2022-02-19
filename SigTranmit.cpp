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
	wc=2*pi*200/fs;//��ͨ�˲�����ֹƵ��
	w1=2*pi*800/fs;//��ͨ�˲����½�ֹƵ��
	w2=2*pi*1200/fs;//��ͨ�˲����Ͻ�ֹƵ��

	myID=85;//��ʼID��
	mySNR=20;//��ʼ�����20dB

}
void SigTranmit::Set_ID(int ID)
{
	myID=ID;//ѧ��
}
void SigTranmit::Set_SNR(int SNR)
{
	mySNR=SNR;//�����
}
void SigTranmit::Set_wc(float f)
{
	wc=2*pi*f/fs;//��ͨ�˲�����ֹƵ��
}
void SigTranmit::Set_w1(float f)
{
	w1=2*pi*f/fs;//��ͨ�˲����½�ֹƵ��
}
void SigTranmit::Set_w2(float f)
{
	w2=2*pi*f/fs;//��ͨ�˲����Ͻ�ֹƵ��
}
float *SigTranmit::Conv(float *s1,float *s2)//�������
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
float *SigTranmit::DFT(float *x)//��ɢ����Ҷ�任
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
void SigTranmit::Num2bin()//ʮ����תBCD��
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
void SigTranmit::Sample()//��������
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
void SigTranmit::Set_h1()//���õ�ͨ�˲���h1[N+1]��ֵ
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
void SigTranmit::Set_h2()//���ô�ͨ�˲���h2[N+1]��ֵ
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
float SigTranmit::Random(float min,float max)//����min~max֮����ȷֲ���һ�������
{
	return min+(max-min)*rand()/(RAND_MAX+1.0);
}
float SigTranmit::Normal(float x, float miu,float sigma)//���ֵΪmiu������Ϊsigma����̬�ֲ�������x���ĺ���ֵ
{
    return 1.0/sqrt(2*pi)/sigma*exp(-1*(x-miu)*(x-miu)/(2*sigma*sigma));
}
float SigTranmit::Randn()//����һ����˹�ֲ������
{
	//��ѡ������
	float x,y,dScope;

	do{

		x=Random(-3.0,3.0);

		y=Normal(x,0,1);

		dScope=Random(0.0,Normal(0,0,1));

	}while(dScope>y);

	return x;
}
void SigTranmit::Randn_Seq()//���ɸ�˹�ֲ��������
{
	float p[10]={0.1179,0.1078,0.0902,0.069,0.0483,0.0309,0.018,0.0097,0.0047,0.0022};//��-3,3������20�ȷ���̫�ֲ�����ֵ
	int num[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//20�ȷ������˹�ֲ�������۲�Ƶ��
	for(int i=0;i<10;i++)
	{
		float temp=p[i]*N;
		if(temp>floor(temp)+0.5)//��������
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
	int num2[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//ʵ�ʹ۲�Ƶ��
	int k=0;//��¼��ǰ�������к�����0~N
	float temp;//������ʱ�����
	float sum=0;
	
	/*�����������ɸѡ��ʹ������ɵ����������˹�ֲ�����Ҫ��*/
	do
	{
		sum=0;
		k=0;
		while(k<N)
		{
			temp=Randn();//��ȡ�����
		
			for(int i=0;i<20;i++)//20���������α���
			{
				if((temp>=-3.0+0.3*i)&&(temp<-3.0+0.3*(i+1)))//���ڸ�����
				{
					if(num2[i]<num[i])//����Ƶ��δ��
					{
						num2[i]++;//������һ
						noise[k]=temp;//�����������
						k++;//��������һ	
					}
					break;
				}
			}
		
		}
		for(int i=0;i<N;i++)//�������к�
		{
			sum+=noise[i];
		}
	}while(sum/N>0.01||sum/N<-0.01);//ʹ��������еľ�ֵ�ڸ�������Χ֮��

}
void SigTranmit::Turn_White()//������ɫ��
{
	float S1=0.0,S0=0.0;
	float r[N];
	for(int k=0;k<N;k++)//�����ʼ������غ�����δ������ʱ��
	{
		r[k]=0.0;
		for(int j=0;j<N-k;j++)
		{
			r[k]+=noise[j]*noise[j+k];//����غ���ֵ	
		}
		S1+=r[k]*r[k];//����ƽ����
	}
	S1=S1/N/N;
	for(int i=0;i<1000;i++)
	{
		S0=S1;//����ǰ����������S0��׼��������һ�μ���
		int r1,r2;
		r1=Random(0,N-1);//�������������
		r2=Random(0,N-1);
		float temp;
		/*˫�������*/
		temp=noise[r1];
		noise[r1]=noise[r2];
		noise[r2]=temp;
		for(int k=0;k<N;k++)//��������غ���
		{
			r[k]=0.0;
			for(int j=0;j<N-k;j++)
			{
				r[k]+=noise[j]*noise[j+k];//����غ���ֵ
			}
			S1+=r[k]*r[k];//����ƽ����
		}
		S1=S1/N/N;
		if(S1>S0)//��i�εĽ�����ڵ�i-1��ʱ����������
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
void SigTranmit::LPF()//��ͨ�˲�
{
	s_c=Conv(s,h1);
	for(int i=0;i<N;i++)//���˲���������н�ȡ��Ч����ΪN�����У��������˲�������ʱ����
	{
		s[i]=s_c[N/2+i];
	}
}
void SigTranmit::ASK_Mod()//ASK����
{
	for(int i=0;i<N;i++)
	{
		s[i]=s[i]*cos(2*pi*fc*i/fs);
	}
}
void SigTranmit::Make_Noise()//���Ӹ�˹������
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
void SigTranmit::BPF()//��ͨ�˲�
{
	s_c=Conv(s,h2);
	for(int i=0;i<N;i++)
	{
		s[i]=s_c[N/2+i];
	}
}
void SigTranmit::ASK_Demod()//ASK��ɽ��
{
	for(int i=0;i<N;i++)
	{
		s[i]=s[i]*cos(2*pi*fc*i/fs);
	}
}
void SigTranmit::Sample_Judge()//�����о�
{
	float sum=0,sum0=0;//sum�洢N������ֵƽ��֮��
	float s2[16];//�洢����ΪN/16�ĸ����������ֵƽ��֮��
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
int *SigTranmit::Get_seq(int num)//��ȡ����������
{	
	if(num==2)
	{
		return seq2;
	}
	return seq1;
}
float *SigTranmit::Get_s()//��ȡ�������ڵ��ź�����
{
	return s;
}
float *SigTranmit::Get_h1()//��ȡ��ͨ�˲�����λ������Ӧ
{
	return h1;
}
float *SigTranmit::Get_h2()//��ȡ��ͨ�˲�����λ������Ӧ
{
	return h2;
}
float *SigTranmit::Get_noise()//��ȡ��˹����������
{
	return noise;
}
SigTranmit::~SigTranmit()
{

}
