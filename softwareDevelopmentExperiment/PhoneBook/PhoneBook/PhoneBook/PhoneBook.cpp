#include <cstdio>
#include "PhoneBook.h"
#include "tools.h"
#include <conio.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;
const string nosense("");
ostream& operator<<(ostream& out, const PhoneNumber& dataInfo) //重载输出操作符
{

	cout << "姓名：" << dataInfo.name << "   电话：" << dataInfo.number
		<< "    地址：" << dataInfo.address << endl;
	return out;
}
PhoneBook::PhoneBook() {

	printf("loading...wait some second.");
	for (int i = 0; i < HASH_MAXSIZE; i++)
	{
		value[i] = new PhoneNumber();
		valuename[i] = new PhoneNumber();
	}
	ifstream outfile;
	outfile.open("1.txt");
	if (outfile.fail())
	{
		cout << "文件打开失败！" << endl;
		exit(1);
	}
	//读入数据到两张hash表中
	string str;
	//读取一行数据
	while (!outfile.eof())//按行读入数据
	{

		PhoneNumber *phonenumber = new PhoneNumber();
		char *str = new char[100];
		outfile.getline(str, 100, '\n');

		if (str[0] == '*')//判断数据结束!!!!!!注意，最后看看要不要加这个
		{
			break;
		}

		int i = 0;//记录字符串数组的下标
		//a-z:97-122     A-Z:65-90
		//本程序的姓名和地址都使用小写字母
		while (((str[i] < 97) && (str[i] > 90)) || (str[i] < 65) || (str[i] > 122))//读入名字
		{
			i++;
		}

		for (; str[i] != '_'; i++)
		{
			phonenumber->name += str[i];
		}

		while (str[i] == '_')
		{
			i++;
		}
		for (int j = 0; str[i] != '_'; j++, i++)//读入地址
		{
			phonenumber->address += str[i];
		}


		while (str[i] == '_')
		{
			i++;
		}
		for (; str[i] != ','; i++)//读入电话号码
		{
			phonenumber->number += str[i];
		}

		phonenumber->next = nullptr;

		int key1 = Hashname(phonenumber->name), key2 = Hashphone(phonenumber->number);

		CreateHashNameNode(key1, phonenumber);

		CreateHashNode(key2, phonenumber);




		delete[] str;
	}

	outfile.close();
}//注意在此函数结束后的下一函数清屏

PhoneBook::~PhoneBook() {
	//fopen(phonebooktext, "w");

	PhoneNumber * deletetemp;

	//删除value链表
	for (int i = 0; i < HASH_MAXSIZE; i++)
	{
		deletetemp = value[i];
		if (deletetemp == nullptr) continue;
		else
		{
			deletetemp = deletetemp->next;//value的下一个指针
			while (deletetemp->next != nullptr)
			{
				PhoneNumber* deletenext = deletetemp->next;
				deletetemp->next = nullptr;
				delete deletetemp;
				deletetemp = deletenext;
			}
			delete deletetemp;
		}
	}
	//删除valuename链表
	for (int i = 0; i < HASH_MAXSIZE; i++)
	{
		deletetemp = valuename[i];
		if (deletetemp == nullptr) continue;
		else
		{
			deletetemp = deletetemp->next;//value的下一个指针
			while (deletetemp->next != nullptr)
			{
				PhoneNumber* deletenext = deletetemp->next;
				deletetemp->next = nullptr;
				delete deletetemp;
				deletetemp = deletenext;
			}
			delete deletetemp;
		}
	}
	delete[] * value;
	delete[] * valuename;
	//需要二维销毁
	printf("Successfully close");
}//注意在此函数结束后的下一函数清屏

int PhoneBook::mainGUI(void)
{
	/* code */
	int  funCode;
	/*这里请给出界面定义*/
	/*初始化界面选项*/
	SetColor(3);
	SetCursorPosition(13, 26);
	std::cout << "                          ";
	SetCursorPosition(13, 27);
	std::cout << "                          ";
	SetCursorPosition(6, 21);
	std::cout << "选择您需要的操作:";
	SetCursorPosition(6, 22);
	std::cout << "(上下键选择,回车确认)";
	SetCursorPosition(27, 22);
	SetBackColor();//第一个选项设置背景色以表示当前选中
	std::cout << "增加电话号码";
	SetCursorPosition(27, 24);
	SetColor(3);
	std::cout << "删除电话号码";
	SetCursorPosition(27, 26);
	std::cout << "查询电话号码";
	SetCursorPosition(27, 28);
	std::cout << "退出";
	SetCursorPosition(0, 31);
	/*上下方向键选择模块*/
	int ch;//记录键入值
	int key = 1;//记录选中项，初始选择第一个
	bool flag = false;//记录是否键入Enter键标记，初始置为否
	while ((ch = getch()))
	{
		switch (ch)//检测输入键
		{
		case 72://UP上方向键
			if (key > 1)//当此时选中项为第一项时，UP上方向键无效
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(27, 22);//给待选中项设置背景色
					SetBackColor();
					std::cout << "增加电话号码";

					SetCursorPosition(27, 24);//将已选中项取消我背景色
					SetColor(3);
					std::cout << "删除电话号码";

					--key;
					break;
				case 3:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "删除电话号码";

					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "查询电话号码";

					--key;
					break;
				case 4:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "查询电话号码";

					SetCursorPosition(27, 28);
					SetColor(3);
					std::cout << "退出";

					--key;
					break;
				}
			}
			break;

		case 80://DOWN下方向键
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "删除电话号码";
					SetCursorPosition(27, 22);
					SetColor(3);
					std::cout << "增加电话号码";

					++key;
					break;
				case 2:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "查询电话号码";
					SetCursorPosition(27, 24);
					SetColor(3);
					std::cout << "删除电话号码";

					++key;
					break;
				case 3:
					SetCursorPosition(27, 28);
					SetBackColor();
					std::cout << "退出";
					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "查询电话号码";

					++key;
					break;
				}
			}
			break;

		case 13://Enter回车键
			flag = true;
			break;
		default://无效按键
			break;
		}
		if (flag) break;//输入Enter回车键确认，退出检查输入循环

		SetCursorPosition(0, 31);//将光标置于左下角，避免关标闪烁影响游戏体验
	}
	/*输入定义*/
	switch (key)//根据所选选项设置蛇的移动速度，speed值越小，速度越快
	{
	case 1:
		funCode = 1;//增加电话
		break;
	case 2:
		funCode = 2;//删除电话
		break;
	case 3:
		funCode = 3;//查询电话
		break;
	case 4:
		funCode = 0;//退出
		break;
	default:
		break;
	}
	return funCode;


}
bool isPhoneNum(string str) {
	if (str.size() != 11) return false;
	else
		for (int i = 0; i < (int)str.size(); i++) {
			int tmp = (int)str[i];
			if (tmp >= 48 && tmp <= 57) { continue; }
			else { return false; }
		}
	return true;
}
void PhoneBook::addnumberGUI(int funCode)
{
	string number, address, name;
	while (1) {
		/*初始化界面选项*/
		system("cls");
		/*电话号码*/
		SetColor(3);
		SetCursorPosition(6, 3);
		std::cout << "请输入要增加的电话号码(输入q可以返回主界面)：";

		/*姓名*/
		SetCursorPosition(6, 5);
		std::cout << "请输入姓名：";
		SetCursorPosition(6, 7);
		std::cout << "请输入地址：";
		SetCursorPosition(30, 3);
		//SetBackColor();//第一个选项设置背景色以表示当前选中
		std::cin >> number;
		/*此部分用于先判断输入号码正确与否*/
		if (number[0] == 'q' || number[0] == 'Q')
		{
			break;
		}
		if (isPhoneNum(number))
		{
			SetCursorPosition(30, 9);
			cout << "号码合法";

		}
		else
		{
			SetCursorPosition(30, 9);
			cout << "号码不合法";
			getch();
			continue;
		}
		SetCursorPosition(30, 5);
		//SetBackColor();//第一个选项设置背景色以表示当前选中
		std::cin >> name;
		SetCursorPosition(30, 7);
		//SetBackColor();//第一个选项设置背景色以表示当前选中
		std::cin >> address;
		//加至hash表中
		PhoneNumber * tempphone = new PhoneNumber();
		tempphone->name = name;
		tempphone->address = address;
		tempphone->number = number;
		tempphone->next = nullptr;
		int key1 = Hashname(name), key2 = Hashphone(number);
		CreateHashNameNode(key1, tempphone);
		CreateHashNode(key2, tempphone);

		//不必销毁动态分配，销毁放到析构函数中
		/*
		delete tempphone;
		tempphone=nullptr;
		*/
		//读入信息到文件。

		SetCursorPosition(30, 9);
		cout << "添加成功";
		getch();
	}
}
void PhoneBook::deletenumberGUI(int funCode)
{
	string information;
	while (1) {
		/*初始化界面选项*/
		system("cls");

		/*电话号码*/
		SetColor(3);
		SetCursorPosition(6, 3);
		std::cout << "请输入要删除的信息(输入q可以返回主界面)：";

		SetCursorPosition(30, 3);
		//SetBackColor();//第一个选项设置背景色以表示当前选中
		std::cin >> information;
		/*此部分用于先判断输入号码正确与否*/
		if (information[0] == 'q' || information[0] == 'Q')
		{
			break;
		}
		if (isPhoneNum(information))
		{
			//是号码，用号码查询hash表
			SetCursorPosition(30, 5);
			cout << "号码合法";
			int key2 = Hashphone(information);

			if (searchHashList(4, key2, nosense, information))
			{
				SetCursorPosition(15, 7);
				cout << "删除成功" << endl;

			}
			else
			{
				SetCursorPosition(15, 7);
				cout << "删除失败，没有这个号码" << endl;
			}
		}
		else
		{
			//不是电话号码，只能是姓名
			int key1 = Hashname(information);
			if (searchHashList(3, key1, information, nosense))
			{
				SetCursorPosition(15, 7);
				cout << "删除成功" << endl;
			}
			else
			{
				SetCursorPosition(15, 7);
				cout << "删除失败，没有这个名字" << endl;

			}
		}
		getch();
	}
}
void PhoneBook::searchnumberGUI(int funCode)
{

	while (1) {
		/*初始化界面选项*/
		system("cls");
		string information;

		/*电话号码*/
		SetColor(3);
		SetCursorPosition(6, 3);
		std::cout << "请输入要查询的信息(输入q可以返回主界面)：";

		SetCursorPosition(30, 3);
		//SetBackColor();//第一个选项设置背景色以表示当前选中
		std::cin >> information;
		/*此部分用于先判断输入号码正确与否*/
		if (information[0] == 'q' || information[0] == 'Q')
		{
			break;
		}
		if (isPhoneNum(information))
		{
			//是号码，用号码查询hash表
			SetCursorPosition(30, 5);
			cout << "号码合法";
			int key2 = Hashphone(information);
			if (searchHashList(1, key2, nosense, information))
			{
				SetCursorPosition(15, 7);
				cout << "查询号码成功" << endl;

			}
			else
			{
				SetCursorPosition(15, 7);
				cout << "查询失败，没有这个号码" << endl;
			}

		}
		else
		{
			//不是电话号码，只能是姓名
			int key1 = Hashname(information);
			if (searchHashList(0, key1, information, nosense))
			{
				SetCursorPosition(15, 7);
				cout << "查询名字成功" << endl;

			}
			else
			{
				SetCursorPosition(15, 7);
				cout << "查询失败，没有这个名字" << endl;
			}
		}
		getch();
	}
}
bool PhoneBook::searchHashList(int functioncode, const int key, const string name, const string number)
{
	int findflag = 0;
	PhoneNumber *tempname = valuename[key];
	PhoneNumber *tempnumber = value[key];
	switch (functioncode)
	{
	case 0://根据名字只查询功能

		while (tempname->next != nullptr)
		{
			if (tempname->name == name)
			{
				SetCursorPosition(12, 3);
				cout << tempname->name << "_" << tempname->address << "_" << tempname->number << endl;
				findflag = 1;
			}
			else tempname = tempname->next;
		}
		if (findflag) return true;
		else return false;//不必写break

	case 1://根据号码只查询功能

		while (tempnumber->next != nullptr)
		{
			if (tempnumber->number == number)
			{
				SetCursorPosition(12, 3);
				cout << tempnumber->name << "_" << tempnumber->address << "_" << tempnumber->number << endl;
				findflag = 1;
			}
			else tempnumber = tempnumber->next;
		}
		if (findflag) return true;
		else return false;//不必写break
	case 2://根据名字查询，并删除电话号码
		while (tempname->next != nullptr)
		{
			if (tempname->next->name == name)
			{
				PhoneNumber * deletetemp = tempname->next->next;
				delete tempname->next;
				tempname->next = deletetemp;
				findflag = 1;
			}
			else tempname = tempname->next;
		}
		if (findflag) return true;
		else return false;//不必写break
	default://根据号码查询，并删除电话号码

		while (tempnumber->next != nullptr)
		{
			if (tempnumber->next->name == name)
			{
				PhoneNumber * deletetemp = tempnumber->next->next;
				delete tempnumber->next;
				tempnumber->next = deletetemp;
				findflag = 1;
			}
			else tempnumber = tempnumber->next;
		}
		if (findflag) return true;
	}
}
void PhoneBook::start()//初始化，销毁，循环调用
{

	int funCode = -1;
	while (1)
	{
		system("cls");//清屏
		funCode = mainGUI(); //决定了主界面的显示
		switch (funCode)
		{ //funCode是功能码，1为增加号码，2为删除号码，3为查询号码,0为退出输入其他无效，直接滞留主界面
		case 0:
			exit(0);
			break;
		case 1:
			addnumberGUI(funCode);//请把这里改对！！！！！！！！！！！！并删除此注释，下同。
			break;
		case 2:
			deletenumberGUI(funCode);
			break;
		case 3:
			searchnumberGUI(funCode);
			break;

		default:
			continue;
		}
	}

}
//hash part
void PhoneBook::CreateHashNode(int key, PhoneNumber *phonenumber)
{

	if (value[key] == nullptr)
	{
		value[key]->name = "start error";
		value[key]->address = "start error";
		value[key]->number = "start error";
		value[key]->next = phonenumber;
		value[key]->next->next = nullptr;
	}
	else
	{
		PhoneNumber * temp;
		temp = value[key];
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = phonenumber;//上一个指针指向新添加数据
		temp = temp->next;
		temp->next = nullptr;
	}
}

void PhoneBook::CreateHashNameNode(int key, PhoneNumber *phonenumber)
{

	if (valuename[key] == nullptr)
	{
		valuename[key]->name = "start error";
		valuename[key]->address = "start error";
		valuename[key]->number = "start error";
		valuename[key]->next = phonenumber;
		valuename[key]->next->next = nullptr;
	}
	else
	{
		PhoneNumber * temp;
		temp = valuename[key];
		while (nullptr != temp->next)
		{
			temp = temp->next;
		}
		temp->next = phonenumber;//上一个指针指向新添加数据
		temp = temp->next;
		temp->next = nullptr;
	}
}

int PhoneBook::Hashname(string name)//以名字为关键字建立哈希表，并链地址法存放
{

	int key = 0;
	for (int t = 0; name[t] != '\0'; t++)
	{
		key = key + name[t];
	}
	key = key % 42;
	return key;

}

int PhoneBook::Hashphone(string number)//以名字为关键字建立哈希表，并链地址法存放
{

	int key = 0;
	for (int t = 0; number[t] != '\0'; t++)
	{
		key = key + number[t];
	}
	key = key % 42;
	return key;

}
