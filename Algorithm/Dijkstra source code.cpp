/// DIJKSTRA

#include <bits/stdc++.h>
using namespace std;

#define inf 2147483647

vector<int>graph[100005],cost[100005];
int vis[100005];
int dist[100005],parent[100005];
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

void dijkstra(int source)
{

    for(int i=1; i<=numNodes; i++)
    {
        dist[i]=inf;
        parent[i]=-1;
    }

    priority_queue<node>q;
    q.push(node(source,0));
    dist[source] = 0;
    parent[source]=source;

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
                parent[v]=u;
                q.push(node(v, dist[v]));
            }
        }
    }
}
int main()
{

    cin>>numNodes>>numEdges;
    for(int i=0; i<numEdges; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back(v);
        graph[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    dijkstra(1);
    int k;
    cin>>k;
    cout<<dist[k]<<endl;
    stack<int>path;
    //vector<int>path;
    path.push(k);
    while(path.top()!=1)
    {
        path.push(parent[path.top()]);
    }
    while(!path.empty())
    {
        if(path.top()==-1)
            cout<<"impossible"<<endl;
        else
            cout<<path.top()<<" ";
        path.pop();
    }
    cout<<endl;
    return 0;
}
/*
6
11
1 2 7
1 3 5
1 4 3
2 3 2
2 6 1
2 5 1
3 4 1
3 6 1
3 5 2
4 5 1
5 6 2
*/
