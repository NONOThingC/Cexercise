#include <cstdio>

using namespace std;

int mainGUI(void)
{
    /* code */
    int errorcode,funCode;
    errorcode=scanf("%d",&funCode);
    if(errorcode ==1)
    {
        return funCode;
    }
    else
    {
        printf("error scanf in GUI");
        exit("error scanf in GUI");
    }
    
}
