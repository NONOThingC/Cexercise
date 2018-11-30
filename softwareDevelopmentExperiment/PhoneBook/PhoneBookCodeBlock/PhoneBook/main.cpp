#include <iostream>
#include "PhoneBook.h"
using namespace std;

int main(int argc, char const *argv[])
{
	PhoneBook phonebook;
	phonebook.start();//初始化，销毁，循环调用
	return 0;
}

