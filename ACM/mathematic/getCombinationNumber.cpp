/*注意，以下所有方法都对M取了模，要正确结果可以去除M*/
#include <vector>
#include <cstdio>
using namespace std;
/*方法一：打表法*/
const int M = 10007;
const int MAXN = 1000;
int C[MAXN+1][MAXN+1];
void Initial()
{
    int i,j;
    for(i=0; i<=MAXN; ++i)
    {
        C[0][i] = 0;
        C[i][0] = 1;
    }
    for(i=1; i<=MAXN; ++i)
    {
        for(j=1; j<=MAXN; ++j)
        C[i][j] = (C[i-1][j] + C[i-1][j-1]) % M;
    }
}
 
int Combination(int n, int m)
{
    return C[n][m];
}
//用筛法生成素数
const int MAXN = 1000000;
bool arr[MAXN+1] = {false};
vector<int> produce_prim_number()
{
    vector<int> prim;
    prim.push_back(2);
    int i,j;
    for(i=3; i*i<=MAXN; i+=2)
    {
        if(!arr[i])
        {
            prim.push_back(i);
            for(j=i*i; j<=MAXN; j+=i)
            arr[j] = true;
        }
    }
    while(i<=MAXN)
    {
        if(!arr[i])
        prim.push_back(i);
        i+=2;
    }
    return prim;
}

//计算n!中素因子p的指数
int Cal(int x, int p)
{
    int ans = 0;
    long long rec = p;
    while(x>=rec)
    {
        ans += x/rec;
        rec *= p;
    }
    return ans;
}

//计算n的k次方对M取模，二分法
int Pow(long long n, int k, int M)
{
    long long ans = 1;
    while(k)
    {
        if(k&1)
        {
            ans = (ans * n) % M;
        }
        n = (n * n) % M;
        k >>= 1;
    }
    return ans;
}

//计算C(n,m)
int Combination(int n, int m)
{
    const int M = 10000;
    vector<int> prim = produce_prim_number();
    long long ans = 1;
    int num;
    for(int i=0; i<prim.size() && prim[i]<=n; ++i)
    {
        num = Cal(n, prim[i]) - Cal(m, prim[i]) - Cal(n-m, prim[i]);
        ans = (ans * Pow(prim[i], num, M)) % M;
    }
    return ans;
}
int main(void)
{
    int i,m,n;
    scanf("%d%d",&n, &m);
    printf("%d\n",Combination(n,m));

    return 0;
}
