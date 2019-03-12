#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <vector>
#define DEBUG
using namespace std;

#define MAX_V 10000 //the number of point
#define Inf 0x3f3f3f3f
struct edge
{
    int to;
    int cost;
};
typedef pair<int, int> P; //distance,point number
vector<edge> G[MAX_V];
int dist[MAX_V];  // shortest path
int dist2[MAX_V]; //second shortest path
int prevm[MAX_V];
int prev2m[MAX_V];
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
                //d2 = dist[e.to];
                //dist[e.to] = dist[v] + e.cost;
                swap(dist[e.to], d2);
                pri_que.push(P(dist[e.to], e.to));
                prevm[e.to] = v;
            }
            if (dist2[e.to] > d2 && dist[e.to] < d2) //longer than shortest path,but shorter than second shortest path
            {
                dist2[e.to] = d2;
                pri_que.push(P(dist2[e.to], e.to));
                prev2m[e.to] = v;
            }
        }
    }
}
//O(V) get path
vector<int> get_path(int final_point)
{
    vector<int> path;
    for (; final_point != -1; final_point = prevm[final_point])
        path.push_back(final_point);
    //#include <algorithm>
    reverse(path.begin(), path.end());
    return path;
}

int main(int argc, char const *argv[])
{

    int N, R;

#ifdef DEBUG
    freopen("input3255.txt", "r", stdin);
#endif

    cin >> N >> R;
    fill(dist, dist + N+1, Inf);
    fill(dist2, dist2 + N+1, Inf);//Attention！1--N,not 0--N-1.
    while (R--)
    {
        int from, to, cost;
        if (scanf("%d %d %d", &from, &to, &cost) == 3)
        {
            //printf("%d+%d+%d\n", from, to, cost);
            edge e={to, cost};
            G[from].push_back(e);
            e.to = from; //无向图
            G[to].push_back(e);
        }
    }
    dijkstra(1);
    printf("%d\n", dist2[N]);
    return 0;
}
