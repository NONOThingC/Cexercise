
#include <string.h>
#include <stdio.h>
#include <ctype.h>


int main()
{
	int T;
    char s[80];
	scanf("%d",&T);
    while (T--)
	{
	scanf("%s", s);
		int i=0,sum=0,j=1;

		int n=strlen(s);
		for(;i<n;i++)
		{
			if(s[i]== 'O')
                sum+=j++;
				else
					j = 1;
		}
		printf("%d\n",sum);
	}

    return 0;
}
