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
	a[1]=randT<int, int>(1,N);
	for (int i = 2; i <= N; i++)
	{
		int flag = 1;
		while (flag)
		{
			int temp = randT<int, int>(1, N);
			for (int j = 1; j < i; j++)
			{
				if (temp == a[j])
					break;
				else if (j == i - 1)
				{
					flag = 0;
					a[i] = temp;
				}
			}
			if (flag != 1)
				break;
		}

	}
	//=========================================================
	End = clock();//结束计时
	double duration = double(End - Begin) / CLK_TCK;//duration就是运行函数的时间,CLK_TCK是每秒所打点数
	return duration;
	


}
double algorithm2(int a[], const int N) {

	clock_t  Begin, End;
	Begin = clock();//开始计时
					//====================这里写要测试的代码===================
	a[1] = randT<int, int>(1, N);
	int temparray[MAXARRAY];
	for (int i = 0; i <= N; i++) temparray[i] = 0;
	temparray[a[1]] = 1;
	for (int i = 2; i <= N; i++)
	{
		int flag = 1;
		while (flag)
		{
			int temp = randT<int, int>(1, N);
			if (temp == i)continue;
			if (temparray[temp] != 1)
			{
				flag = 0;
				temparray[temp] = 1;
				a[i] = temp;
			}
		}

	}
	//=========================================================
	End = clock();//结束计时
	double duration = double(End - Begin) / CLK_TCK;//duration就是运行函数的时间,CLK_TCK是每秒所打点数
	return duration;



}
template<typename T>
void Swap(T &a,T &b) {//仅用于单元素交换
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}
double algorithm3(int a[], const int N) {

	clock_t  Begin, End;
	Begin = clock();//开始计时
	//====================这里写要测试的代码===================
	for (int i = 1; i < N; i++)
		Swap<int>(a[i], a[randT<int, int>(0, i)]);
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
	while(scanf_s("%d", &N)!=1);
	if ( N < 2)
		printf("error intput");
	else
	{
		for (int i = 0; i <= N; i++) a[i] = 0;
			printf("%f\n",timeofalgorithm1=algorithm1(a, N));
			printf("%f\n",timeofalgorithm2=algorithm2(a, N));
		for (int i = 0; i <= N; i++) a[i] = i+1;
			printf("%f\n",timeofalgorithm3=algorithm3(a, N));
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
