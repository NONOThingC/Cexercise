#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define DEBUG
#define MAX_V 5010 //the number of point
#define Inf 0x3f3f3f3f
struct edge
{
    edge(int x, int y) : to(x), cost(y) {}
    int to;
    int cost;
};

vector<edge> G[MAX_V];
int d[MAX_V];  // shortest path


int main(int argc, char const *argv[])
{

    int N, ML, MD;

#ifdef DEBUG
    freopen("input3169.txt", "r", stdin);
#endif

    if (scanf("%d%d%d", &N, &ML, &MD) == 3)
    {
        int AL, BL, DL;
        for(int i=0;i<N;i++)
        {
            d[i]=Inf;
        }
        while (ML--)
        {
            if (scanf("%d%d%d", &AL, &BL, &DL) == 3)
            {
                G[AL].push_back(edge(BL, DL));
            }
        }
        while (MD--)
        {
            if (scanf("%d%d%d", &AL, &BL, &DL) == 3)
            {
                G[BL].push_back(edge(AL, -DL));
            }
        }
        for (int i = 1; i < N; i++)
        {
            G[i + 1].push_back(edge(i, 0));
        }
        for (int i = 1; i < N+1; i++)
        {
            for (int j = 0; j < G[i].size(); j++)
            {
                edge e=G[i][j];
                d[e.to]=min(d[e.to],d[i]+e.cost);
            }
        }
        int res=d[N];
        if(d[1]<0){
            res=-1;
        }
        else if(d[1]==Inf)
        {
            res=-2;
        }
        printf("%d\n", res);
    }

    
    return 0;
}
