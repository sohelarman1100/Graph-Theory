#include<bits/stdc++.h>
using namespace std;
int vis[105];
int dis[105];
int dis1[105];
vector<int>graph[105];
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
void BFS1(int start)
{
    queue<int>q;
    q.push(start);
    vis[start]=1;
    dis1[start]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0 ; i<graph[u].size() ; i++)
        {
            int v=graph[u][i];
            if(!vis[v])
            {
                dis1[v]=1+dis1[u];
                q.push(v);
                vis[v]=1;
            }
        }
    }
}
int main()
{
    int l,t;
    scanf("%d",&t);
    for(l=1; l<=t; l++)
    {
        int n,e,i,u,v,r,s,d;

        for(i=0; i<105; i++)
            graph[i].clear();
        memset(vis,0,sizeof(vis));
        memset(dis,0,sizeof(dis));
        memset(dis1,0,sizeof(dis1));

        scanf("%d%d",&n,&r);
        for(i=1 ; i<=r ; i++)
        {
            scanf("%d%d",&u,&v);
            make_graph(u,v);
        }
        scanf("%d%d",&s,&d);
        BFS(s);
        memset(vis,0,sizeof(vis));
        BFS1(d);
        int ara[n];
        for(i=0; i<n; i++)
        {
            //cout<<dis[i]<<"  "<<dis1[i]<<endl;
            ara[i]=dis[i]+dis1[i];
        }
        sort(ara,ara+n);
        printf("Case %d: %d\n",l,ara[n-1]);
    }
    return 0;
}

