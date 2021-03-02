#include<bits/stdc++.h>
using namespace std;

long long int invt,res,cnt,nfp,n;
vector<int>graph[100005];
int vis[100005];
void DFS(int start)
{
    if(vis[start])
        return;
    vis[start]=1;
    cnt++;
    for(int i=0; i<graph[start].size(); i++)
    {
        int u=graph[start][i];
        if(!vis[u])
        {
            res++;
            DFS(u);
        }
    }
    nfp+=(n-cnt);
}
int main()
{
    int q,t;
    scanf("%d",&t);
    for(q=1; q<=t; q++)
    {
        int i,j,u,v,m;
        res=cnt=nfp=0;
        memset(vis,0,sizeof(vis));
        for(i=0; i<100005; i++)
            graph[i].clear();
        scanf("%d",&n);
        for(i=1; i<n; i++)
        {
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        DFS(1);
        printf("Case %d: %lld %lld\n",q,res,nfp);
    }
    return 0;
}
