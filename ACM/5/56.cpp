#define DEBUG
#include <cstdio>
#include <map>
#include <queue>
using namespace std;


int ID(set x){
    if(IDcache[x].count() )
        return IDcache[x];
    Setcache.push_back(x);
    return IDcache[x] = Setcache.size() - 1;
}
#define ALL x.begin(),x.end()
#define INS inserter(x,x.begin())
stack<int> s;
int main()
{
#ifdef DEBUG
    freopen("input55.txt", "r", stdin);
    freopen("output55.txt", "w", stdout);
#endif
    int t,kase=0;
    while(scanf("%d",&t)==)
    for (int i = 0; i < n;i++)
    {
        string op;
        cin >> op;
        if(op[0]=='P')
        {
            s.push(ID)
        }
    }
        return 0;
}