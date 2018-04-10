/* #include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    freopen("inputtest.txt", "r", stdin);
    freopen("inputout.txt", "w", stdout);
    string line;
    while(getline(cin,line))
    {
        int sum = 0, x;
        stringstream ss(line);
        while(ss>>x)
            sum += x;
        cout << sum << "\n";
    }
	return 0;
} */

/*#include <iostream>
#include <string>
using namespace std;*/
// template <typename T>
// T sum(T *begin, T *end)
// {
//     T *p = begin;
//     T sum = 0;
//     while (p != end)
//     {
//         sum = sum + *p;
//         p++;
//     }
//     return sum;
// }

// template <typename T>
// struct Point
// {
//     T x, y;
//     Point<T>(T x = 0, T y = 0) : x(x), y(x) {}
// };

// template <typename T>
// Point<T> operator+(const Point<T> &A, const Point<T> &B)
// {
//     return Point(A.x + B.x, A.y + B.y);
// }
// template <typename T>
// ostream &operator<<(ostream &out, const Point<T> &p)
// {
//     out << "(" << p.x << "," << p.y << ")";
//     return out;
// }
/*
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
        int n[] = {1,4,2,2} ;
    vector<int> A(n,n+4);
        for(int i=1;i<=A.size()-1;i++)
        {
            if(A[i]==0) continue;
            for(int j=i+1;j<=A.size();j++)
            {
                if(A[j]==0) continue;
                if(A[i]==A[j]) {printf("%d\n",i);A[j]=0;}
            }

            
        }
        printf("\n");
return 0;
}*/
/*
#define DEBUG
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
		printf("%d/n",sum);
	}
	printf("/n");
    return 0;
}
*/
#define DEBUG
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int maxn = 100;
vector<int> pile[maxn];
int n;
void find_block(int a, int &p, int &n)
{
    for (int p = 0; p < n; ++p)
    {
        for (int n = 0; n < pile[p].size(); n++)
        {
            if (a == pile[p][n])
                return;
        }
    }
}
void clear_above(int p, int h)
{
    for (int i = h + 1; i < pile[p].size(); ++i)
    {
        int b = pile[p][i];
        pile[b].push_back(b);
    }
    pile[p].resize(h + 1);
}
void pile_onto(int p, int h, int p2)
{
    for (int i = h; i < pile[p].size(); ++i)
    {
        pile[p2].push_back(pile[p][i]);
    }
    pile[p].resize(h);
}
void print()
{
    for (int j = 0; j < n; ++j)
    {
        printf("%d:", j);
        for (int i = 0; i < pile[j].size(); ++i)
        {
            printf("%d", pile[j][i]);
        }
        printf("\n");
    }
}
int main()
{
#ifdef DEBUG
    freopen("input52.txt", "r", stdin);
    freopen("output52.txt", "w", stdout);
#endif // DEBUG

        while (scanf("%d", &n) == 1)
        {
            for (int i = 0; i < n;++i)
                pile[i].push_back(i);
            string s1, s2;
            int n1, n2;
            while (cin >> s1 && s1 != "quit")
            {
                int pl1, pl2, h1, h2;
                cin >> n1 >> s2 >> n2;
                if (n1 == n2)
                    continue;
                if (s1 == "move")
                    if (s2 == "onto") //operation 1
                    {
                        find_block(n1, pl1, h1);
                        find_block(n2, pl2, h2);
                        clear_above(pl1, h1);
                        clear_above(pl2, h2);
                        pile_onto(pl1, h1, n2);
                    }
                    else //2
                    {
                        find_block(n1, pl1, h1);
                        clear_above(pl1, h1);
                        pile_onto(pl1, h1, n2);
                    }
                else if (s2 == "onto")
                {
                    find_block(n2, pl2, h2);
                    clear_above(pl2, h2);
                    pile_onto(pl1, h1, n2);
                }
                else //4
                {
                    pile_onto(pl1, h1, n2);
                }
            }
            print();
        }
    return 0;
}

