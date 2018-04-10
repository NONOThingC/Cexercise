#include <stdio.h>
#define maxn 25
int n, k, m, a[maxn];
int sel(int startpoint,int stepLength,int stepnumber)
{
    while(stepnumber--)
    {
        do
        {
            startpoint += startpoint + stepLength + n + 1;
        } while (a[startpoint] == 0);
    }
    return startpoint;
}
int main()
{
    while(scanf("%d%d%d",&n,&k,&m)==3 && n)
    {
        for (int i = 0; i <= n;i++)
        {
            a[i] = i;
        }
        int left = n, p1 = n, p2 = 1;
        while (left)
        {
            p1 = sel(p1, 1, k);
            p2 = sel(p2, -1, m);
            printf("%3d", p1);
            if(p1 !=p2)
            {
                printf("%3d", p2);
            }
            a[p1] = a[p2];
            if(left)
            {
                printf(",");
            }
        }
        printf("\n");
    }

    return 0;

}