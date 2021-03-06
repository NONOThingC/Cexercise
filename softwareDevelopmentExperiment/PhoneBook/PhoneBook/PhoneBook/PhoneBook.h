﻿#include <stdlib.h>
#include <string>
#include <cstdio>
#include <fstream>
const int HASH_MAXSIZE = 50;
using namespace std;
class PhoneNumber
{
public:
	PhoneNumber() :name(""), number(""), address(""), next(nullptr)
	{

	}
	friend ostream& operator<<(ostream& out, const PhoneNumber& PhoneNumber);
	//protected:
	string number;
	string name;
	string address;
	PhoneNumber *next;
};

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	void CreateHashNode(int key, PhoneNumber *phonenumber);
	void CreateHashNameNode(int key, PhoneNumber *phonenumber);
	int Hashname(string);//以名字为关键字建立哈希表
	int Hashphone(string);//以电话为关键字建立哈希表
	bool searchHashList(int functioncode, int key, const string name, const string number);
	void start();
	int mainGUI();
	void addnumberGUI(int funCode);
	void deletenumberGUI(int funCode);
	void searchnumberGUI(int funCode);
private:
	PhoneNumber *value[HASH_MAXSIZE];
	PhoneNumber *valuename[HASH_MAXSIZE];
	int length;//哈希表长度
};



