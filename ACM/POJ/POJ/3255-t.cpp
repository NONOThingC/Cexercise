#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define DEBUG
using namespace std;
typedef long long ll;
const int maxn = 5e3 + 10;
#define INF 0x3f3f3f3f
#define clr(x,y) memset(x,y,sizeof x)
 
typedef pair<int,int> P;
 
struct Node
{
    Node(int x,int y):to(x),val(y){}
    int to;
    int val;
};
int n,m;
vector<Node>v[maxn];
int dist[maxn],dist2[maxn];
void dijkstra()
{
    clr(dist,INF);
    clr(dist2,INF);
    priority_queue<P,vector<P>,greater<P> >q;
    dist[1] = 0;
    q.push(P(0,1));
    while(!q.empty())
    {
        P t = q.top();q.pop();
        int u = t.second;
        if(dist2[u] < t.first)
            continue;
        for(int i = 0; i < v[u].size(); i ++)
        {
            int vs = v[u][i].to,cost = v[u][i].val;
            int d = t.first + cost;
            if(d < dist[vs])
            {
                swap(dist[vs],d);
                q.push(P(dist[vs],vs));
            }
            if(dist[vs] < d && dist2[vs] > d)
            {
                dist2[vs] = d;
                q.push(P(dist2[vs],vs));
            }
        }
    }
    printf("%d\n",dist2[n]);
}
int main()
{
    #ifdef DEBUG
    freopen("input3255.txt", "r", stdin);
#endif
    while( ~ scanf("%d%d",&n,&m))
    {
        for(int i = 1; i <= n; i ++)
            v[i].clear();
        while(m --)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            v[x].push_back(Node(y,z));
            v[y].push_back(Node(x,z));
        }
        dijkstra();
    }
    return 0;
}
