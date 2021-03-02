#include <bits/stdc++.h>
using namespace std;

#define inf 2147483647

vector<int>graph[100005],cost[100005];
int vis[100005];
int mxcost[100005];
int n,e;
int numNodes, numEdges;

struct node
{
    int u;
    int cost;
    node(int _u, int _cost)
    {
        u = _u;
        cost = _cost;
    }
};
bool operator<(node A, node B)
{
    return A.cost>B.cost;
}

void dijstkra(int source)
{

    for(int i=0; i<numNodes; i++)
    {
        mxcost[i]=inf;
    }

    priority_queue<node>q;
    q.push(node(source,0));
    mxcost[source]=0;

    while(!q.empty())
    {
        node top = q.top();
        q.pop();
        int u=top.u;

        if(vis[u]==1)
            continue;
        vis[u]=1;
        for(int i=0; i<(int)graph[u].size(); i++)
        {
            int v=graph[u][i];

            if(max(mxcost[u],cost[u][i])<mxcost[v])
            {
                mxcost[v]=max(mxcost[u],cost[u][i]);
                q.push(node(v, mxcost[v]));
            }
        }
    }
}
int main()
{
    int t,z;
    scanf("%d",&t);
    for(z=1; z<=t; z++)
    {
        int p;
        scanf("%d%d",&numNodes,&numEdges);
        for(int i=1; i<=numEdges; i++)
        {
            int u, v, w;
            scanf("%d%d%d",&u,&v,&w);
            graph[u].push_back(v);
            graph[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        int s;
        scanf("%d",&s);
        dijstkra(s);
        printf("Case %d:\n",z);
        for(int i=0; i<numNodes; i++)
        {
            if(vis[i]==0)
                printf("Impossible\n");
            else
                printf("%d\n",mxcost[i]);
        }
        for(p=0; p<=numNodes; p++)
        {
            graph[p].clear();
            cost[p].clear();
        }
        for(p=0; p<=numNodes; p++)
            vis[p]=0;
    }
    return 0;
}
