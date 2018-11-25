// last_homework.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <Windows.h>
#include <Psapi.h>
#pragma comment(lib, "Psapi.lib")
using namespace std;
int add(int x, int y)
{
	return x + y;
}
int main()
{
	printf("GetCurrentProcess:0x%d \n", GetCurrentProcess());
	printf("GetModuleHandle:0x%d \n", GetModuleHandle(NULL));

	MODULEINFO moduleInfoe;
	GetModuleInformation(
		GetCurrentProcess(),         // handle to process
		GetModuleHandle(NULL),         // handle to module
		&moduleInfoe,  // information buffer
		sizeof(moduleInfoe)                 // size of buffer
	);
	printf("模块加载起始地址：0x%X 大小：0x%X(%d) 入口：0x%X \n",
		moduleInfoe.lpBaseOfDll,
		moduleInfoe.SizeOfImage,
		moduleInfoe.SizeOfImage,
		moduleInfoe.EntryPoint);



	int z;
	for (int i = 0; i < 200000; i++) {
		z = add(1, 2);
	}
	
}



