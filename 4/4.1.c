#define TEST
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 150
int cmp(const void *a,const void *b){
	if(*(int *)a > *(int *)b)
	{
		return 0;
	}	
	else if(*(int *)a = *(int *)b) return 1;
	else return -1;
}

int main()
{
    #ifdef TEST
    freopen("input4.1.txt", "r", stdin);
    freopen("output4.1.txt", "w", stdout);
    #endif
    char s1[maxn], s2[maxn];
    while(scanf("%s%s",s1,s2)==2)
    {
        char cnt1[28], cnt2[28];
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        int n1=strlen(s1),n2=strlen(s2);
        int i=0,j=0;
        while(s1[i] != '\0')
        {
            int index = s1[i] - 'A';
            cnt1[index] += 1;
            i++;
        }
//        qsort(cnt1,n1,sizeof(cnt1),cmp());
        while(s2[j] != '\0')
        {
            int index = s2[j] - 'A';
            cnt2[index] += 1;
            j++;
        }
        
    }
//        qsort(cnt2,n2,sizeof(cnt2),cmp());
    return 0;

}