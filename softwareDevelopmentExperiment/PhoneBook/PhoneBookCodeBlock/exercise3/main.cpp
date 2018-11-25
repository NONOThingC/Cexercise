#include <iostream>

using namespace std;
class TEST{
    int a[2<<16];//一个2的17次方的数组
public:
    void init();
};
void TEST::init()
{
    for(int i=0;i<(2<<16);i++) a[i]=1;
}
TEST __stdcall Add_InnerClean()
{
    TEST test;
    test.init();
    return test;
}
int main()
{
        Add_InnerClean();
        return 0;
}
