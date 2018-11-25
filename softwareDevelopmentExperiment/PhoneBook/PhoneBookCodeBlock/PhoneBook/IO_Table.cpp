#include "IO_Table.h"
#include <windows.h>
#include <string>
#include <iostream>
#include <iomanip>

/*char *mHalo[] = { "──", "┌", "┬", "┐", "├", "┼", "┤", "└", "┴", "┘", "│" }; */

IO_Table::Data *IO_Table::mHead = NULL;
IO_Table::Data *IO_Table::mTemp = NULL;

string *IO_Table::mInput = NULL;	//输出初始化
int *IO_Table::mWidth = NULL;		//宽度初始化

CONSOLE_CURSOR_INFO IO_Table::cursor_true = { 5, TRUE };
CONSOLE_CURSOR_INFO IO_Table::cursor_false = { 5, FALSE };

IO_Table::IO_Table()
{
	clear();
	mHand = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(mHand, &cursor_false);
}
//==================================设置标题====================================
void IO_Table::setTitle(string title)
{
	if (mCol == 0) return;

	mTitle = title;

	int surplus = title.length() / 2 - (getAllWidth() - 2);

	gotoxy(mLeft + 1, mTop + 1);		//清空标题框
	cout << setw(getAllWidth()-2) << "";

	//判断标题文字是否超过最大宽度
	if (surplus <= 0)
	{
		SetConsoleTextAttribute(mHand, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		gotoxy(mLeft + abs(int((getAllWidth() - title.length()/2) / 2)), mTop + 1);
		cout << title;
	}
	else{
		int minIndex=0;
		for (int c = 0; c < mCol; c++)
		{
			mWidth[c] += (surplus / mCol);
			if (mWidth[minIndex]>mWidth[c]) minIndex = c;
		}
		mWidth[minIndex] += surplus % mCol;
		refresh();

		SetConsoleTextAttribute(mHand, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		gotoxy(mLeft + (getAllWidth() - title.length() / 2) / 2, mTop + 1);
		cout << title;
	}
}
//=========================添加导航栏=============================
void IO_Table::setNavigation(string *navigation, int col)
{
	mCol = col;

	//链表重置，添加导航栏到表头
	if (mHead != NULL) clear();
	mHead = mTemp = (Data*)malloc(sizeof(Data));
	mTemp->mNext = NULL;

	mTemp->mRowData = new string[col];

	//宽度重置，根据所给值分配
	if (mWidth != NULL)
	{
		delete[] mWidth;
		mWidth = NULL;
	}
	mWidth = new int[mCol];
	for (int c = 0; c < mCol; c++)
	{
		mWidth[c] = int(navigation[c].length() / 2 + 0.5);
		mTemp->mRowData[c] = navigation[c];		//把数据存储在链表中
	}

	printNavigation(navigation);
}
void IO_Table::setNavigation(string navigation, int col)
{
	mCol = col;

	//链表重置，添加导航栏到表头
	if (mHead != NULL) clear();
	mHead = mTemp = (Data*)malloc(sizeof(Data));
	mTemp->mNext = NULL;

	mTemp->mRowData = new string[col];

	//宽度重置，根据所给值分配
	if (mWidth != NULL)
	{
		delete[] mWidth;
		mWidth = NULL;
	}
	mWidth = new int[mCol];

	string strTemp = "";	//临时字符
	int index = 0;			//当前元素
	for (int c = 0; c < navigation.length(); c++)
	{
		if (navigation[c] != ',' && navigation[c] != '，')
		{
			strTemp += navigation[c];
		}
		else{
			mTemp->mRowData[index] = strTemp;
			mWidth[index] = int(strTemp.length() / 2 + 0.5);
			strTemp.clear();
			index++;
		}
	}
	mTemp->mRowData[index] = strTemp;
	mWidth[index] = int(strTemp.length() / 2 + 0.5);

	printNavigation(mTemp->mRowData);
}
//绘制表格边框
void IO_Table::printNavigation(string *naviation)
{
	system("cls");
	//每次重绘表头时，行数都归零
	mRow = 0;
	//获取水平位置起始点，以居中显示表格
	mLeft = (40 - getAllWidth()) / 2;

	SetConsoleTextAttribute(mHand, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	//第1行
	gotoxy(mLeft, mTop);
	cout << "┌";
	for (int c = 0; c < mCol; c++)
	{
		for (int w = 0; w < mWidth[c]; w++)
			cout << "─";
		cout << (c == mCol - 1 ? "┐" : "─");
	}
	//第2行
	gotoxy(mLeft, mTop + 1);
	cout << "│";
	cout << setw(getAllWidth()*2 - 4) << "";
	cout << "│";
	//第3行
	gotoxy(mLeft, mTop + 2);
	cout << "├";
	for (int c = 0; c < mCol; c++)
	{
		for (int w = 0; w < mWidth[c]; w++)
			cout << "─";
		cout << (c == mCol - 1 ? "┤" : "┬");
	}
	//第4行
	gotoxy(mLeft, mTop + 3);
	for (int c = 0; c < mCol; c++)
	{
		cout << "│";
		SetConsoleTextAttribute(mHand, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << setw(mWidth[c]*2) << naviation[c];
		SetConsoleTextAttribute(mHand, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}
	cout << "│";
	//第5行
	gotoxy(mLeft, mTop + 4);
	cout << "└";
	for (int c = 0; c < mCol; c++)
	{
		for (int w = 0; w < mWidth[c]; w++)
			cout << "─";
		cout << (c == mCol - 1 ? "┘" : "┴");
	}
}
//==========================添加行======================================
void IO_Table::addRow(string *content)
{
	if (mCol == 0) return;
	bool needRefresh = false;	//是否需要刷新（当某个数据超过当前列的宽度时需要刷新）
	if (mHead == NULL)
		return;	//如果没有表头，直接退出
	else{
		mTemp->mNext = (Data*)malloc(sizeof(Data));
		mTemp = mTemp->mNext;
		mTemp->mNext = NULL;
	}
	mTemp->mRowData = new string[mCol];
	for (int c = 0; c < mCol; c++)
	{
		mTemp->mRowData[c] = content[c];

		if ((content[c].length()/2) > mWidth[c])
		{
			mWidth[c] = (content[c].length() % 2 == 0 ? content[c].length()/2 : content[c].length()/2 + 1);
			needRefresh = true;
		}
	}

	if (needRefresh)
		refresh();
	else
		printRow(content);
}
void IO_Table::printRow(string *content)
{
	SetConsoleTextAttribute(mHand, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(mLeft, mTop + mRow * 2 + 4);
	cout << "├";
	for (int c = 0; c < mCol; c++)
	{
		for (int w = 0; w < mWidth[c] ; w++)
			cout << "─";
		cout << (c == mCol - 1 ? "┤" : "┼");
	}

	gotoxy(mLeft, mTop + mRow * 2 + 5);
	for (int c = 0; c < mCol; c++)
	{
		cout << "│";
		SetConsoleTextAttribute(mHand, 0x0f);
		cout << setw(mWidth[c]*2) << content[c];
		SetConsoleTextAttribute(mHand, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}
	cout << "│";

	gotoxy(mLeft, mTop + mRow * 2 + 6);
	cout << "└";
	for (int c = 0; c < mCol; c++)
	{
		for (int w = 0; w < mWidth[c] ; w++)
			cout << "─";
		cout << (c == mCol - 1 ? "┘" : "┴");
	}

	mRow++;
}
//===========================输入=================================
string *IO_Table::inputData(string *navigation, int row/*数据个数*/)
{
	clear();
	system("cls");

	mRow = row;
	mLeft = 10;

	for (int r = 0; r <= mRow; r++)
	{
		SetConsoleTextAttribute(mHand, FOREGROUND_RED | FOREGROUND_GREEN |FOREGROUND_INTENSITY);
		gotoxy(mLeft, mTop + r * 2 );
		cout << (r == 0 ? "┌" : "├");
		for (int c = 0; c < 20; c++)
		{
			cout << (c == 5 ? (r == 0 ? "┬" : (r == mRow ? "┴" : "┼")) : "─");
		}
		cout << (r == 0 ? "┐" : "┤");

		gotoxy(mLeft, mTop + r * 2 + 1);
		cout << "│";
		if (r != mRow)
		{
			SetConsoleTextAttribute(mHand, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout << setw(10) << navigation[r];
			SetConsoleTextAttribute(mHand, FOREGROUND_RED | FOREGROUND_GREEN |FOREGROUND_INTENSITY);
			cout << "│";
			cout << setw(28) << "";
		}
		else
			cout << setw(40) << "";
		cout << "│";

		gotoxy(mLeft, mTop + r * 2 + 2);
		cout << "└";
		for (int c = 0; c < 20; c++)
			cout << (c == 5 && r != mRow ? "┴" : "─");
		cout << "┘";
	}

	int index = 0;		//当前输入焦点行
	string strTemp;		//临时数据的数据
	string *strInput = new string[row];	//所有输入数据的集合

	SetConsoleCursorInfo(mHand, &cursor_true);
	SetConsoleTextAttribute(mHand, 0x0f);
	do
	{
		gotoxy(mLeft + 7, mTop + index * 2 + 1);
		fflush(stdin);
		getline(cin, strTemp);
		if (strTemp.length() == 0)
			continue;
		strInput[index] = strTemp;
	} while (++index < row);

	SetConsoleCursorInfo(mHand, &cursor_false);
	gotoxy(mLeft + 1, mTop + index * 2 + 1);
	SetConsoleTextAttribute(mHand, 0x0f);
	cout << "  输入成功！  请按任意键继续...";

	return strInput;
}
string *IO_Table::inputData(string navigation, int row)
{
	clear();
	system("cls");

	int width = 5;
	mRow = row;
	mLeft = 10;

	string *strNavigation = new string[row];
	string strTemp = "";	//临时字符
	int index = 0;			//当前元素
	for (int c = 0; c < navigation.length(); c++)
	{
		if (navigation[c] != ',' && navigation[c] != '，')
		{
			strTemp += navigation[c];
		}
		else{
			width = width < strTemp.length()/2 ? width : strTemp.length()/2;
			strNavigation[index++] = strTemp;
			strTemp.clear();
		}
	}
	strNavigation[index] = strTemp;
	width = width < strTemp.length()/2 ? width : strTemp.length()/2;

	for (int r = 0; r <= mRow; r++)
	{
		SetConsoleTextAttribute(mHand, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		gotoxy(mLeft, mTop + r * 2);
		cout << (r == 0 ? "┌" : "├");
		for (int c = 0; c < 20; c++)
		{
			cout << (c == width ? (r == 0 ? "┬" : (r == mRow ? "┴" : "┼")) : "─");
		}
		cout << (r == 0 ? "┐" : "┤");

		gotoxy(mLeft, mTop + r * 2 + 1);
		cout << "│";
		if (r != mRow)
		{
			SetConsoleTextAttribute(mHand, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout << setw(10) << strNavigation[r];
			SetConsoleTextAttribute(mHand, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "│";
			cout << setw(28) << "";
		}
		else
			cout << setw(40) << "";
		cout << "│";

		gotoxy(mLeft, mTop + r * 2 + 2);
		cout << "└";
		for (int c = 0; c < 20; c++)
			cout << (c == width && r != mRow ? "┴" : "─");
		cout << "┘";
	}

	delete[] strNavigation;

	index = 0;		//当前输入焦点行
	string *strInput = new string[row];	//所有输入数据的集合

	SetConsoleCursorInfo(mHand, &cursor_true);
	SetConsoleTextAttribute(mHand, 0x0f);
	do
	{
		gotoxy(mLeft + 7, mTop + index * 2 + 1);
		fflush(stdin);
		getline(cin, strTemp);
		if (strTemp.length() == 0)
			continue;
		strInput[index] = strTemp;
	} while (++index < row);
	setInputResult("输入成功！");
	return strInput;
}
void IO_Table::setInputResult(string strTips)
{
	if (mRow == 0) return;
	SetConsoleCursorInfo(mHand, &cursor_false);
	gotoxy(mLeft + 1, mTop + mRow * 2 + 1);
	cout << setw(40) << "";
	gotoxy(mLeft + 1, mTop + mRow * 2 + 1);
	SetConsoleTextAttribute(mHand, 0x0f);
	cout << strTips;
}

void IO_Table::refresh()
{
	Data *temp;
	for (temp = mHead; temp != NULL; temp = temp->mNext)
	{
		if (temp == mHead)
			printNavigation(temp->mRowData);
		else
			printRow(temp->mRowData);
	}

	if (!mTitle.empty()) setTitle(mTitle);
}

inline void IO_Table::gotoxy(int x, int y)
{
	COORD cd;
	cd.X = x << 1;
	cd.Y = y;
	SetConsoleCursorPosition(mHand,cd);
}

int IO_Table::getAllWidth()
{
	int allWidth = mCol + 1;
	for (int c = 0; c < mCol; c++)
		allWidth += mWidth[c];
	return allWidth;
}

void IO_Table::clear()
{

	mRow = 0;
	mCol = 0;
	mLeft = 0;

	if (mWidth != NULL)
	{
		delete[] mWidth;
		mWidth = NULL;
	}

	if (mInput != NULL)
	{
		delete[] mInput;
		mInput = NULL;
	}

	Data *next;
	mTemp = mHead;
	while (mTemp != NULL)
	{
		//先把行数据清空
		delete[] mTemp->mRowData;
		mTemp->mRowData = NULL;
		//释放节点并删除
		next = mTemp->mNext;
		free(mTemp);
		mTemp = next;
	}
	mHead = mTemp = next = NULL;
}

IO_Table::~IO_Table()
{
	clear();
}
