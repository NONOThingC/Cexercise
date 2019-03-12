#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_V 10 //the number of point
#define Inf (2<<29)-1
struct edge{
    int to;
    int from;
    int cost;
}
typedef pair<int,int> P;
vector<edge> G[MAX_V];
int d[MAX_V];
int prev[MAX_V];
const int V=MAX_V;
void dijkstra(int s)
{
    priority_queue<P,vector<P>,greater<P>> pri_que;
    for(int i=0;i<MAX_V;i++)
    {
        d[i]=Inf;
    }
    d[s]=0;
    prev[s]=-1;
    pri_que.push(P(0,s));
    while(!queue.empty)
    {
        P p=pri_que.top();
        pri_que.pop();
        int v=p.second();
        for(int i=0;i<G[v].size();i++)
        {
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost)
            {
                d[e.to]=d[v]+e.cost;
                pri_que.push(P(d[e.to],e.to));
                prev[e.to]=v;
            }

        }
    }
}
//O(V) get path
vector<int> get_path(int final_point)
{
    vector<int> path;
    for(;final_point!=-1;final_point=prev[final_point]) path.push_back(final_point);
    //#include <algorithm>
    reverse(path.begin(),path.end());
}
int main(int argc, char const *argv[])
{

    return 0;
    
}
