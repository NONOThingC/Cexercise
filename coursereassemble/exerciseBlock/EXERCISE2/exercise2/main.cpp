#include <iostream>
using namespace std;
struct MyStruct{
    int arr[20000]={0};
};
 int __stdcall Add_InnerClean(MyStruct mystruct)
{
    int sum=1;
    return sum;
}
int main()
{
    MyStruct mystruct;
    int i=Add_InnerClean(mystruct);
    return 0;
}
