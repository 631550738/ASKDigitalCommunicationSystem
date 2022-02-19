一个ASK数字通信系统的仿真程序
开发平台：VS2019,C++，MFC
包含文件：
SigTranmit.c/.h ：编码，加噪声，滤波等操作的实现代码
DigitalCommunicationSystemDlg.c/h 在图形界面添加控件
DigitalCommunicationSystem.c/h 图形界面启动窗口及主窗口
StdAfx.c/.h ????
主要内容：
1.将一个4位数字作为基带信号编码为二进制序列
2.生成低通滤波器，带通滤波器和噪声
3.将二进制信号通过低通滤波器并进行ASK调制
4.将调制后的信号加入噪声模拟通过信道
5.对信号进行带通滤波并进行相干解调
6.对解调后的信号进行低通滤波并恢复判决