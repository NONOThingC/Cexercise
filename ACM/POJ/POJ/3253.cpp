#include <iostream>

#include <cstdio>
#include <queue>
#include<vector>
using namespace std;

int main()
{

    int N;
    int X[20001];

    priority_queue<int,vector<int>,greater<int>> pq;

    if(scanf("%d",&N)==1)
    {
        __int64 ans=0;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&X[i]);
            pq.push(X[i]);
        }

        for(int i=0;i<N-1;i++)
        {
            int node1=pq.top();
            pq.pop();
            int node2=pq.top();
            pq.pop();
            int node_sum=node1+node2;
            ans+=node_sum;
            pq.push(node_sum);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
