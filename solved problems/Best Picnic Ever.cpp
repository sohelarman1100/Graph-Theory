#include<bits/stdc++.h>
using namespace std;

int sz,m;
vector<int>graph[1005];
int vis[1005];
int cnt[1005];
void DFS(int start)
{
    if(vis[start])
        return;
    vis[start]=1;
    cnt[start]++;
    for(int i=0; i<graph[start].size(); i++)
    {
        int u=graph[start][i];
        if(!vis[u])
            DFS(u);
    }
}
int main()
{
    int p,t;
    scanf("%d",&t);
    for(p=1; p<=t; p++)
    {
        int i,j,u,v,k,n,m,a=0;
        for(i=0; i<1005; i++)
            graph[i].clear();
        memset(vis,0,sizeof(vis));
        memset(cnt,0,sizeof(cnt));
        scanf("%d%d%d",&k,&n,&m);
        int ara[k];
        for(i=0; i<k; i++)
            scanf("%d",&ara[i]);
        for(i=1; i<=m; i++)
        {
            cin>>u>>v;
            graph[u].push_back(v);
            //graph[v].push_back(u);
        }
        for(i=0; i<k; i++)
        {
            memset(vis,0,sizeof(vis));
            DFS(ara[i]);
        }
        for(i=1; i<=n; i++)
        {
            if(cnt[i]==k)
                a++;
        }
        printf("Case %d: %d\n",p,a);
    }
    return 0;
}
