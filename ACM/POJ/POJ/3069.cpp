#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int R,N;
    int X[1001];

    while(scanf("%d%d",&R,&N)==2&&R!=-1&&N!=-1)
    {
        int countn=0;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&X[i]);
        }
        sort(X,X+N);

        for(int i=0,j=1;i<N;)
        {
            while(X[j]-X[i]<=R&&j<N)
            {
                j++;
            }

            i=j-1;
            countn++;
            while(X[j]-X[i]<=R&&j<N)
            {
                j++;
            }
            i=j;

        }
        printf("%d\n",countn);
    }
    return 0;
}
