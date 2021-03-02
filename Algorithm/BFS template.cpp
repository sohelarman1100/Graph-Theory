/// BFS
///complexity O(v+e)

#include<bits/stdc++.h>
using namespace std;
int vis[100005];
int dis[100005];
vector<int>graph[100005];
void make_graph(int u,int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}
void BFS(int start)
{
    queue<int>q;
    q.push(start);
    vis[start]=1;
    dis[start]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0 ; i<graph[u].size() ; i++)
        {
            int v=graph[u][i];
            if(!vis[v])
            {
                dis[v]=1+dis[u];
                q.push(v);
                vis[v]=1;
            }
        }
    }
}
int main()
{
    int n,e,i,u,v;
    cin>>n>>e;
    for(i=1 ; i<=e ; i++)
    {
        cin>>u>>v;
        make_graph(u,v);
    }
    BFS(1);
    for(i=1 ; i<=n ; i++)
        cout<<dis[i]<<" ";
    return 0;
}
/**
7 6
1 2
1 3
2 4
2 6
3 7
6 5
**/
