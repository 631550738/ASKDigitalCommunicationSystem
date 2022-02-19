// SigTranmit.h: interface for the SigTranmit class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SIGTRANMIT_H__5E35D638_BA86_43B4_ABFE_B330DCCF5F92__INCLUDED_)
#define AFX_SIGTRANMIT_H__5E35D638_BA86_43B4_ABFE_B330DCCF5F92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define pi 3.1415926
#define T 1/200;//单个码元持续时间
#define fs 4000//采样频率
#ifndef N
#define N 320//采样点数
#endif
#define fc 1000//载波频率
class SigTranmit  
{
public:
	SigTranmit();//构造函数

	void Set_ID(int ID);//设置ID的值
	void Set_SNR(int SNR);//设置SNR的值

	void Set_wc(float f);//设置wc
	void Set_w1(float f);//设置w1
	void Set_w2(float f);//设置w2

	float *Conv(float *s1,float *s2);//卷积函数
	float *DFT(float *x);//离散傅里叶变换

	/*生成基带信号*/
	void Num2bin();//十进制转BCD码
	void Sample();//采样生成基带信号

	/*生成滤波器单位脉冲响应*/
	void Set_h1();//设置低通滤波器h1[N+1]的值
	void Set_h2();//设置带通滤波器h2[N+1]的值
	

	/*生成高斯白噪声*/
	float Random(float min,float max);//生成min~max之间均匀分布的一个随机数
	float Normal(float x, float miu,float sigma);//求均值为miu，方差为sigma的正态分布函数在x处的函数值
	float Randn();//舍选抽样法生成一个符合高斯分布随机数
	void Randn_Seq();//生成高斯分布随机序列
	void Turn_White();//噪声白色化

	/*对信号的变换和处理*/
	void LPF();//低通滤波
	void ASK_Mod();//ASK调制
	void Make_Noise();//叠加高斯白噪声
	void BPF();//带通滤波
	void ASK_Demod();//ASK相干解调
	void Sample_Judge();//抽样判决

	/*获取序列数组*/
	int *Get_seq(int num);//获取二进制序列
	float *Get_s();//获取各个环节的信号序列
	float *Get_h1();//获取低通滤波器单位脉冲响应
	float *Get_h2();//获取低通滤波器单位脉冲响应
	float *Get_noise();//获取高斯白噪声序列

	virtual ~SigTranmit();//析构函数
private:

	int myID;//学号
	int mySNR;//信噪比
	
	float wc;//低通滤波器截止频率
	float w1;//带通滤波器下截止频率
	float w2;//带通滤波器上截止频率

	int seq1[16];//输入数字的BCD二进制序列
	float s[N];//采样离散化序列
	float *s_c;//临时信号序列的指针
	float h1[N+1];//低通滤波器单位脉冲响应
	float h2[N+1];//带通滤波器单位脉冲响应
	float noise[N];//N点高斯白噪声序列
	float S[N];//频谱序列
	int seq2[16];//抽样判决所得序列


};
#endif // !defined(AFX_SIGTRANMIT_H__5E35D638_BA86_43B4_ABFE_B330DCCF5F92__INCLUDED_)
