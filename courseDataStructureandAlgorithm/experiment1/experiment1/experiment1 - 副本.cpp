// experiment1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#define DEBUG
#define MAXARRAY 32767
using namespace std;
template<typename T, typename BACK> BACK randT(T Lower, T Upper);//注意不可超过RAND_MAX,RAND_MAX至少为32767
template<>
int randT(int Lower, int Upper)
{
	int temp;
	if (Lower > Upper)
	{
		temp = Upper;
		Upper = Lower;
		Lower = temp;
	}
	return rand() % (Upper - Lower + 1) + Lower;
}
template<typename T, typename BACK>
BACK randT(T Lower, T Upper)//注意这里lower和upper是闭区间
{
	T temp;
	if (Lower > Upper)
	{
		temp = Upper;
		Upper = Lower;
		Lower = temp;
	}
	return rand() / (double)RAND_MAX *(Upper - Lower) + Lower;
}


double algorithm1(int a[],const int N) {

	clock_t  Begin, End;
	Begin = clock();//开始计时
					//====================这里写要测试的代码===================
	
	







	//=========================================================
	End = clock();//结束计时
	double duration = double(End - Begin) / CLK_TCK;//duration就是运行函数的时间,CLK_TCK是每秒所打点数
	return duration;
	


}
double algorithm2(int a[], const int N) {

	clock_t  Begin, End;
	Begin = clock();//开始计时
					//====================这里写要测试的代码===================








	//=========================================================
	End = clock();//结束计时
	double duration = double(End - Begin) / CLK_TCK;//duration就是运行函数的时间,CLK_TCK是每秒所打点数
	return duration;



}

double algorithm3(int a[], const int N) {

	clock_t  Begin, End;
	Begin = clock();//开始计时
					//====================这里写要测试的代码===================
	









	//=========================================================
	End = clock();//结束计时
	double duration = double(End - Begin) / CLK_TCK;//duration就是运行函数的时间,CLK_TCK是每秒所打点数
	return duration;



}
int main()
{
	srand((unsigned)time(0));
	// DEBUG
#ifdef DEBUG 
//...debugging code 
	/*
		for (int i = 0; i <= 1000; i++)
		printf("%d\n", randT<int, int>(1, 2));
	for (int i = 0; i <= 1000; i++)
		printf("%f", randT<float, float>(1, 2));
	*/

	//printf("\n\n%f",algorithm1());
#endif 
	/*程序开始*/
	int N;
	int a[MAXARRAY];
	double timeofalgorithm1, timeofalgorithm2, timeofalgorithm3;
	while(scanf_s("%d", &N)==1);

	if ( N < 2)
		printf("error intput");
	else
	{

	}

	return 0;
}


