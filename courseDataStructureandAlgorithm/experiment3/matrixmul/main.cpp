#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
const int MAX_SIZE=1000;
const int MAX_INT=(2<<15)-1;

int BestValue(int * row,int * col,int n)
{
    int f[MAX_SIZE][MAX_SIZE];
    int s[MAX_SIZE][MAX_SIZE];
    int tempf;
    memset(f,0,sizeof(f));
    for(int j=1;j<n;j++)
    {
        for(int i=0;i<n-j;i++)
        {
            j=i+j-1;
            f[i][j]=MAX_INT;
            s[i][j]=i;
            for(int k=i;k<=j-1;k++)
            {
                tempf=f[i][k]+f[k+1][j]+row[i]*col[k]*col[j];
                if(tempf<f[i][j])
                {
                f[i][j]=tempf;
                s[i][j]=k;
                }
            }
        }
    }
    return f[0][n-1];
}

int main()
{
    //ÊäÈë²¿·Ö
    int N;
    int a[MAX_SIZE];
    int b[MAX_SIZE];
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
        scanf("%d",&b[i]);
    }

    int aaa=BestValue(a,b,N);
    printf("\n%d",aaa);

    return 0;
}
