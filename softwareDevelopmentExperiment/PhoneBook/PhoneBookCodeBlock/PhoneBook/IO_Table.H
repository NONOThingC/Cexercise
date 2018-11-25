#ifndef IO_TABLE_H_INCLUDED
#define IO_TABLE_H_INCLUDED
#pragma once
#include <cstdio>
#include <windows.h>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
class IO_Table
{
public:
	/*********************************
	┌───────┬───────┐
	│ 标题1 │ 标题2 │
	├───────┼───────┤
	│ 内容1 │ 内容2 │
	└───────┴───────┘
	*********************************/
private:
	typedef struct DATA
	{
		string *mRowData;
		struct DATA *mNext;
	}Data;

	static Data *mHead;
	static Data *mTemp;

private:
	int mLeft;				//起始x坐标(为了居中显示，所以动态获取)
	static const int mTop = 1;		//起始y坐标
	int mRow;				//逻辑行数
	int mCol;				//逻辑列数
	static int *mWidth;		//每一列的宽度
	int mAllWidth;			//总宽度（包括边框）

	static string *mInput;	//输入内容
	string mTitle;			//标题

private:
	HANDLE mHand;									//控制台句柄

	static CONSOLE_CURSOR_INFO cursor_true ;		//光标可见
	static CONSOLE_CURSOR_INFO cursor_false;		//光标不可见

	void gotoxy(int x,int y);						//广角定位
	int getAllWidth();								//获取表格总宽度（包括边框）

	void printNavigation(string *navigation);			//打印导航栏
	void printRow(string *content);						//打印行
	void refresh();										//刷新
	void clear();										//清空
	void delPoint(Data*);								//删除某个节点

public:
	IO_Table(void);										//构造函数
	~IO_Table();										//析构函数

	void setTitle(string title);						//设置标题栏

	/*************************************************************
	* 对于char型数组，可以用string(char *)转换成为string类型
	* 对于其他的数据类型，可以利用to_string()函数来转换到string类型
	*************************************************************/
	void setNavigation(string *navigation, int col);	//设置导航栏
	void setNavigation(string navigation, int col);		//设置导航栏
	void addRow(string *content);						//插入一整行

	//用完以后一定要用delete[]删除，切记切记！
	string *inputData(string *navigation, int row);		//输入数据
	string *inputData(string navigation, int row);		//输入数据

	void setInputResult(string strTips);				//输入提示

};



#endif // IO_TABLE_H_INCLUDED
