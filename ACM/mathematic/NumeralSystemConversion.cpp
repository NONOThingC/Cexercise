#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
/*
以下需使用#include <cstdlib>
从char转到int
1.任意2-36进制数转化为10进制数。
strtol 函数：

它的功能是将一个任意1-36进制数转化为10进制数，返回是long int型。

函数为long int strtol(const char *nptr, char **endptr, int base)

base是要转化的数的进制，非法字符会赋值给endptr，nptr是要转化的字符，例如：


char buffer[20]="10379cend$3";
char *stop;
printf("%d\n",strtol(buffer, &stop, 8));
printf("%s\n", stop);

输出结果：
543
9cend$3
将一个8进制转化为10进制，读取1037，其他后面的为非法字符，转化结果以int型输出来。
另外，如果base为0，且字符串不是以0x(或者0X)开头，则按十进制进行转化。如果base为0或者16，并且字符串以0x（或者0X）开头，那么，x（或者X）被忽略，字符串按16进制转化。如果base不等于0和16，并且字符串以0x(或者0X)开头，那么x被视为非法字符。
最后，需要说明的是，对于nptr指向的字符串，其开头和结尾处的空格被忽视，字符串中间的空格被视为非法字符。


2.itoa()函数（可以将一个10进制数转换为任意的2-36进制字符串）
函数原型：char*itoa(int value,char*string,int radix);
#include<cstdlib>
#include<cstdio>
int main()
{
int num = 10;
char str[100];
itoa(num, str, 2);
printf("%s\n", str);
return 0;
}
输出结果：
1010
3.sprintf()函数（可以将一个10进制数转换为指定格式的n进制字符串）
函数原型：int sprintf( char *buffer, const char *format, [ argument] … );
*/
/*从 int到int可以使用库函数代码转换，或者+-'0'（chartoint '3'-'0'=3）*/
/*比较简单，不写了*/
