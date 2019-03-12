#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

#define MAX_V 5010 //the number of point
#define Inf 0x3f3f3f3f
struct edge
{
    edge(int x,int y):to(x),cost(y){}
    int to;
    int cost;
};
typedef pair<int, int> P; //distance,point number
vector<edge> G[MAX_V];
int dist[MAX_V];  // shortest path
int dist2[MAX_V]; //second shortest path
const int V = MAX_V;

void dijkstra(int s)
{

    priority_queue<P, vector<P>, greater<P>> pri_que;
    dist[s] = 0;
    pri_que.push(P(0, s));
    while (!pri_que.empty())
    {
        P p = pri_que.top();
        pri_que.pop();
        int v = p.second, d = p.first;
        if (dist2[v] < d)
            continue;
        for (int i = 0; i < G[v].size(); i++)
        {
            edge e = G[v][i];
            int d2 = d + e.cost;
            if (dist[e.to] > d2)
            {
                swap(dist[e.to], d2);
                pri_que.push(P(dist[e.to], e.to));
            }
            if (dist2[e.to] > d2 && dist[e.to] < d2) //longer than shortest path,but shorter than second shortest path
            {
                dist2[e.to] = d2;
                pri_que.push(P(dist2[e.to], e.to));
            }
        }
    }
}

int main(int argc, char const *argv[])
{

    int N, R;

#ifdef DEBUG
    freopen("input3255.txt", "r", stdin);
#endif

    cin >> N >> R;

    while (R--)
    {
        int from, to, cost;
        if (scanf("%d %d %d", &from, &to, &cost) == 3)
        {

            G[from].push_back(edge(to,cost));
            G[to].push_back(edge(from,cost));
        }
    }
    fill(dist, dist + MAX_V, Inf);
    fill(dist2, dist2 + MAX_V, Inf);//Attention！1--N,not 0--N-1.
    dijkstra(1);
    printf("%d\n", dist2[N]);
    return 0;
}
