#include "pch.h"
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
const int MAX_SIZE = 100;
const long long MAX_INT = 12345678908642;

long long BestValue( int * row, int * col,const int n)
{

	long long f[MAX_SIZE][MAX_SIZE];
	long long s[MAX_SIZE][MAX_SIZE];
	long long tempf;
	for (int i = 0; i < n; i++) f[i][i] = 0;
	for (int j = 1; j < n; j++)//间隔大小
	{
		int m = j;
		for (int i = 0; i <= n - m-1; i++)
		{
			m = i + m;
			f[i][m] = MAX_INT;
			s[i][m] = i;
			for (int k = i; k <= m - 1; k++)
			{
				tempf = f[i][k] + f[k + 1][m] + row[i] * col[k] * col[m];
				if (tempf < f[i][m])
				{
					f[i][m] = tempf;
					s[i][m] = k;
				}
			}
		}
		
	}
	return f[0][n - 1];
}

int main()
{
	//
	int N;
	int a[MAX_SIZE];
	int b[MAX_SIZE];
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &a[i]);
		scanf_s("%d", &b[i]);
	}

	int aaa = BestValue(a, b, N);
	printf("\nanswer:\n%ld", aaa);

	return 0;
}
