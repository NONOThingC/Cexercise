#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_V 50000  //the number of point
#define MAX_E 100005 //the number of edge
#define Inf 0x3f3f3f3f
int par[MAX_V], rankArray[MAX_V];
struct edge
{
    int cost;
    int to;
    int from;
};              //krustral need from to use union find
edge es[MAX_E]; //no need for priority queue.
void init_union_find(int n)
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




bool comp(const edge &x, const edge &y)
{
    return x.cost < y.cost;
}
int main(int argc, char const *argv[])
{
    if (scanf("%d %d %d", &from, &to, &cost) == 3)
    {
        //printf("%d+%d+%d\n", from, to, cost);
        //Undirected graph
        es[from].from = from;
        es[from].to = to;
        es[from].cost = cost;

    }
    sort(es, es + V, comp); //notice range
    init_union_find(MAX_V);
    int sum_of_cost=0;
    for(int i=0;i<E;i++)
    {
        edge e=es[i];
        if(!same(e.from,e.to))
        {
            unite(e.from,e.to);
            sum_of_cost+=e.cost;
        }
    }
    return 0;
}
