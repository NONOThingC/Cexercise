#define TEST
#include <stdio.h>
#define maxn 25
int n, k, m, a[maxn];
int sel(int startpoint,int stepLength,int stepnumber)
{
    while(stepnumber--)
    {
        do
        {
            
            startpoint = (startpoint + stepLength + n -1)%n+1;
        } while (a[startpoint] == 0);
    }
    return startpoint;
}
int main()
{
    #ifdef TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    while(scanf("%d%d%d",&n,&k,&m)==3 && n)
    {
    	int i;
        for (i = 1; i <= n;i++)
        {
            a[i] = i;
        }
        int left = n, p1 = n, p2 = 1;
        while (left)
        {
            p1 = sel(p1, 1, k);
            p2 = sel(p2, -1, m);
            printf("%3d", p1);
            left--;
            if(p1 !=p2)
            {
                printf("%3d", p2);left--;
            }
            a[p1] = a[p2]=0;
            if(left)
            {
                printf(",");

            }
        }
        printf("\n");
    }

    return 0;

}