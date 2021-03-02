#include <bits/stdc++.h>
using namespace std;

#define inf 2147483647

vector<int>graph[100005],cost[100005];
int vis[100005];
int dist[100005];
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

    for(int i=1; i<=numNodes; i++)
    {
        dist[i]=inf;
    }

    priority_queue<node>q;
    q.push(node(source,0));
    dist[source] = 0;

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

            if(dist[u] + cost[u][i] < dist[v])
            {
                dist[v] = dist[u] + cost[u][i];
                q.push(node(v, dist[v]));
            }
        }
    }
}
int main()
{
    int j,t;
    scanf("%d",&t);
    for(j=1; j<=t; j++)
    {
        cin>>numNodes>>numEdges;
        for(int i=0; i<=numNodes; i++)
        {
            graph[i].clear();
            cost[i].clear();
            vis[i]=0;
            dist[i]=0;
        }
        int n=numNodes;
        for(int i=0; i<numEdges; i++)
        {
            int u, v, w;
            cin>>u>>v>>w;
            graph[u].push_back(v);
            graph[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        dijstkra(1);
        if(vis[n]==0)
            printf("Case %d: Impossible\n",j);
        else
            printf("Case %d: %d\n",j,dist[n]);
    }
    return 0;
}

