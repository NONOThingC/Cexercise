#include <cstdio>
#include "PhoneBook.h"
#include "tools.h"
#include <conio.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
PhoneBook::PhoneBook(){
	printf("loading...wait some second.");
	outfile.open("1.txt", ios::out | ios::trunc );
}//注意在此函数结束后的下一函数清屏

PhoneBook::~PhoneBook(){
    //fopen(phonebooktext, "w");
    outfile.close();

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
                    std::cout << "增加电话号码" ;

                    SetCursorPosition(27, 24);//将已选中项取消我背景色
                    SetColor(3);
                    std::cout << "删除电话号码" ;

                    --key;
                    break;
                case 3:
                    SetCursorPosition(27, 24);
                    SetBackColor();
                    std::cout << "删除电话号码" ;

                    SetCursorPosition(27, 26);
                    SetColor(3);
                    std::cout << "查询电话号码" ;

                    --key;
                    break;
                case 4:
                    SetCursorPosition(27, 26);
                    SetBackColor();
                    std::cout << "查询电话号码" ;

                    SetCursorPosition(27, 28);
                    SetColor(3);
                    std::cout << "退出" ;

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
                    std::cout << "删除电话号码" ;
                    SetCursorPosition(27, 22);
                    SetColor(3);
                    std::cout << "增加电话号码" ;

                    ++key;
                    break;
                case 2:
                    SetCursorPosition(27, 26);
                    SetBackColor();
                    std::cout << "查询电话号码" ;
                    SetCursorPosition(27, 24);
                    SetColor(3);
                    std::cout << "删除电话号码" ;

                    ++key;
                    break;
                case 3:
                    SetCursorPosition(27, 28);
                    SetBackColor();
                    std::cout << "退出" ;
                    SetCursorPosition(27, 26);
                    SetColor(3);
                    std::cout << "查询电话号码" ;

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
    if(str.size()!=11) return false;
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

    while(1){
    /*初始化界面选项*/
    system("cls");
	SetColor(3);
	SetCursorPosition(6, 3);
	std::cout << "请输入要增加的电话号码(输入q可以返回主界面)：";

	SetCursorPosition(30, 3);
	//SetBackColor();//第一个选项设置背景色以表示当前选中
	std::cin>>number;

	if(number[0]=='q'||number[0]=='Q')
    {
        break;
    }
    if(isPhoneNum(number))
    {
        SetCursorPosition(30, 5);
        cout<<"添加成功";
    }
    else
    {
        SetCursorPosition(30, 5);
        cout<<"添加失败";
    }
    getch();
    }
}
void PhoneBook::deletenumberGUI(int funCode)
{
    while(1){
    /*初始化界面选项*/
    system("cls");
	SetColor(3);
	SetCursorPosition(6, 3);
	std::cout << "请输入要删除电话号码(输入q可以返回主界面)：";

	SetCursorPosition(30, 3);
	//SetBackColor();//第一个选项设置背景色以表示当前选中
	std::cin>>number;

	if(number[0]=='q'||number[0]=='Q')
    {
        break;
    }
    if(isPhoneNum(number))
    {
        SetCursorPosition(30, 5);
        cout<<"删除成功";
    }
    else
    {
        SetCursorPosition(30, 5);
        cout<<"删除失败";
    }
    getch();
    }
}
void PhoneBook::searchnumberGUI(int funCode)
{
    while(1){
    /*初始化界面选项*/
    system("cls");
	SetColor(3);
	SetCursorPosition(6, 3);
	std::cout << "请输入要查询的电话号码(输入q可以返回主界面)：";

	SetCursorPosition(30, 3);
	//SetBackColor();//第一个选项设置背景色以表示当前选中
	std::cin>>number;

	if(number[0]=='q'||number[0]=='Q')
    {
        break;
    }
    if(isPhoneNum(number))
    {
        SetCursorPosition(30, 5);
        cout<<"查询成功";
    }
    else
    {
        SetCursorPosition(30, 5);
        cout<<"请输入正确的电话号码";
    }
    getch();
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
