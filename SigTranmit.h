// SigTranmit.h: interface for the SigTranmit class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SIGTRANMIT_H__5E35D638_BA86_43B4_ABFE_B330DCCF5F92__INCLUDED_)
#define AFX_SIGTRANMIT_H__5E35D638_BA86_43B4_ABFE_B330DCCF5F92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define pi 3.1415926
#define T 1/200;//������Ԫ����ʱ��
#define fs 4000//����Ƶ��
#ifndef N
#define N 320//��������
#endif
#define fc 1000//�ز�Ƶ��
class SigTranmit  
{
public:
	SigTranmit();//���캯��

	void Set_ID(int ID);//����ID��ֵ
	void Set_SNR(int SNR);//����SNR��ֵ

	void Set_wc(float f);//����wc
	void Set_w1(float f);//����w1
	void Set_w2(float f);//����w2

	float *Conv(float *s1,float *s2);//�������
	float *DFT(float *x);//��ɢ����Ҷ�任

	/*���ɻ����ź�*/
	void Num2bin();//ʮ����תBCD��
	void Sample();//�������ɻ����ź�

	/*�����˲�����λ������Ӧ*/
	void Set_h1();//���õ�ͨ�˲���h1[N+1]��ֵ
	void Set_h2();//���ô�ͨ�˲���h2[N+1]��ֵ
	

	/*���ɸ�˹������*/
	float Random(float min,float max);//����min~max֮����ȷֲ���һ�������
	float Normal(float x, float miu,float sigma);//���ֵΪmiu������Ϊsigma����̬�ֲ�������x���ĺ���ֵ
	float Randn();//��ѡ����������һ�����ϸ�˹�ֲ������
	void Randn_Seq();//���ɸ�˹�ֲ��������
	void Turn_White();//������ɫ��

	/*���źŵı任�ʹ���*/
	void LPF();//��ͨ�˲�
	void ASK_Mod();//ASK����
	void Make_Noise();//���Ӹ�˹������
	void BPF();//��ͨ�˲�
	void ASK_Demod();//ASK��ɽ��
	void Sample_Judge();//�����о�

	/*��ȡ��������*/
	int *Get_seq(int num);//��ȡ����������
	float *Get_s();//��ȡ�������ڵ��ź�����
	float *Get_h1();//��ȡ��ͨ�˲�����λ������Ӧ
	float *Get_h2();//��ȡ��ͨ�˲�����λ������Ӧ
	float *Get_noise();//��ȡ��˹����������

	virtual ~SigTranmit();//��������
private:

	int myID;//ѧ��
	int mySNR;//�����
	
	float wc;//��ͨ�˲�����ֹƵ��
	float w1;//��ͨ�˲����½�ֹƵ��
	float w2;//��ͨ�˲����Ͻ�ֹƵ��

	int seq1[16];//�������ֵ�BCD����������
	float s[N];//������ɢ������
	float *s_c;//��ʱ�ź����е�ָ��
	float h1[N+1];//��ͨ�˲�����λ������Ӧ
	float h2[N+1];//��ͨ�˲�����λ������Ӧ
	float noise[N];//N���˹����������
	float S[N];//Ƶ������
	int seq2[16];//�����о���������


};
#endif // !defined(AFX_SIGTRANMIT_H__5E35D638_BA86_43B4_ABFE_B330DCCF5F92__INCLUDED_)
