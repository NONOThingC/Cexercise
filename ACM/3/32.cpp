#include<stdio.h>
#include<ctype.h>
int main()
{
    int T;
    char a[1000];
	scanf("%d",&T);
    double sum;
    while (T--)
    {
        scanf("%s",a);
        for(int i=0;i<strlen(a);i++)
        {
            if(isalpha(a[i]) 
                if(isalpha(a[i+1])) 
                switch (a[i])
                {
                case 'C':sum+=12.01;break;
                case 'H':sum+=1.008;break;
                case 'O':sum+=16.00;break;
                case 'N':sum+=14.01;break;
                }
        }
        
    }

    scanf("%s",a);
    
    return 0;
}