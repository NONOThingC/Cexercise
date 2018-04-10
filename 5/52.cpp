#define DEBUG
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
                find_block(n1, pl1, h1);
                find_block(n2, pl2, h2);
                if (n1 == n2)
                    continue;
                if (s1 == "move")
                    if (s2 == "onto") //operation 1
                    {

                        clear_above(pl1, h1);
                        clear_above(pl2, h2);
                    }
                    else //2
                    {
                        clear_above(pl1, h1);
                    }
                else if (s2 == "onto")
                {
                    clear_above(pl2, h2);
                }
 //4

            pile_onto(pl1, h1, n2);
            }
            print();
        }
    return 0;
}