#include <cstdio>
using namespace std;
#define MAX_RANGE 150001
int par[MAX_RANGE], rankArray[MAX_RANGE];
void init(int n)
{
    for (int j = 0; j < n; j++)
    {
        par[j] = j;
        rankArray[j] = 0;
    }
}
int findroot(int x) // Find root
{
    while (x != par[x])
    {
        x = par[x];
    }
    return x;
}
bool same(int x, int y) //depend if x,y from same root
{
    return findroot(x) == findroot(y);
}
void unite(int x, int y)
{
    x = findroot(x);
    y = findroot(y);
    if (x == y)
        return;
    if (rankArray[x] < rankArray[y])
    {
        par[x] = y;
        rankArray[y]++;
    }
    else
    {
        par[y] = x;
        rankArray[x]++;
    }
}
int main()
{
    int N, K;
    int T, X, Y;
    if (scanf("%d %d", &N, &K) == 2)
    {
        int ans = 0;
        //init union-find
        init(3 * N);
        for (int i = 0; i < K; i++)
        {

            if (scanf("%d %d %d", &T, &X, &Y) == 3)
            {
                int t = T;
                int x = X - 1;
                int y = Y - 1;

                //
                if (x < 0 || y < 0 || x > N - 1 || y > N - 1)
                {
                    ans++;
                    continue;
                }
                if (t == 1) //same class
                {
                    if (same(x, y + N) || same(x, y + 2 * N)) //如果和前有冲突
                    {
                        ans++;
                    }
                    else
                    {
                        unite(x, y);
                        unite(x + N, y + N);
                        unite(x + 2 * N, y + 2 * N);
                    }
                }
                else if (t == 2)
                {
                    if (same(x, y) || same(x, y + 2 * N))
                    {
                        ans++;
                    }
                    else
                    {
                        unite(x, y + N);
                        unite(x + N, y + 2 * N);
                        unite(x + 2 * N, y);
                    }
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
