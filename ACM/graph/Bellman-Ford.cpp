#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define MAX_V 10 //the number of point
#define MAX_E 10 //the number of edge
#define Inf (2<<29)-1
struct edge{
    int to;
    int from;
    int cost;
}
edge es[MAX_E];
int d[MAX_V];//shortest matrix
//DAG from startPoint to all point in graph
void shortest_path(int startPoint)
{
    for(int i=0;i<V;i++)
    {
        d[i]=Inf;
    }
    d[startPoint]=0;
    while(1)
    {
        bool update=false;
        for(int i=0;i<E;i++)
        {
            edge e=es[i];//get edge information
            if(d[e.from]!=Inf && d[e.from]+e.cost<d[e.to])
            {
                d[e.to]=d[e.from]+e.cost;
                update=True;
            }
        }
        if(!update){
            break;
        }
    }
}



int main(int argc, char const *argv[])
{
    //Directed graph
    struct edge{
        int to,cost;
    };
    vector<edge> G[MAX_V];
    int V,E;
    for(int i=0;i<E;i++)
    {
        G[i].push_back(/*cost*/);
    
    }
    printf("hello");
    return 0;
    
}
