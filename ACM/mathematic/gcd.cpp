#include<algorithm>
int gcd(int x,int y)
{
    if(x==0) return x;
    else if (y==0) return y;
    else{
    while(x%y)
    {
        int t=x;
        x=y;
        y=t%x;
    }
    return x;
    }
}