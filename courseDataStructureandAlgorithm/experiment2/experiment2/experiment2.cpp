// experiment2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cstdio>
#define MAX 10000
using namespace std;
int main()
{
	/*最简单的搜索法,时间复杂度m*n，空间复杂度n^2*/
	int total,rmt,interval;
	scanf_s("%d%d%d", &total, &rmt, &interval);
	int a[MAX][2];
	int left = total;
	int result[MAX];
	for (int i = 1; i <= total; i++)
	{
		a[i][0] = i;
		a[i][1] = 0;
	}
	a[0][1] = 1;
	int j = 1;
	int k = 0;
	int kk;
	while (left != rmt)
	{
		int count = interval;
		while (count--)
		{
			if (a[j][1] == 1)
			{
				count++;
				j++;
			}
			else j++;
			kk = j-1;
			if (kk == total )
				j = 1;

		}
		
		result[k++] = a[kk][0];
		a[kk][1] = 1;
		left--;//剩余人数-1
	}
	int i;
	for (i= 0; i < total - rmt - 1; i++) printf("%d,", result[i]);
	printf("%d", result[i]);

}
/*
	int total,rmt,interval;
	scanf_s("%d%d%d", &total, &rmt, &interval);
	int a[MAX][MAX];
	int left = total;
	int select;
	int result[MAX];
	int i = 0;
	while (left != rmt)
	{
		if (left < interval)//剩下人数不足于要选的间隔人数
			select = interval - left;
		else select = interval;
		result[i] = select;
		i++;
		left--;//剩余人数-1

	}
*/
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
