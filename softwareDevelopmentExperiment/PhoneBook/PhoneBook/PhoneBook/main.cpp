// PhoneBook.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "PhoneBook.h"
using namespace std;

int main(int argc, char const *argv[])
{
	PhoneBook phonebook;
	phonebook.start();//初始化，销毁，循环调用
	return 0;
}


