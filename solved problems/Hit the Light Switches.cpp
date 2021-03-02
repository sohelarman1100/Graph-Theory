#include<bits/stdc++.h>
using namespace std;

vector<int>graph[10005];
int vis[10005];
stack<int>ans;

void topDFS(int start)
{
    vis[start]=1;
    for(int i=0 ; i<graph[start].size() ; i++)
    {
        int u=graph[start][i];
        if(!vis[u])
            topDFS(u);
    }
    ans.push(start);
}
void DFS(int start)
{
    vis[start]=1;
    for(int i=0 ; i<graph[start].size() ; i++)
    {
        int u=graph[start][i];
        if(!vis[u])
            DFS(u);
    }
}
int main()
{
    int t,q;
    scanf("%d",&t);
    for(q=1; q<=t; q++)
    {
        int i,j,k,u,v,e,cnt=0,n,m,res=0;

        memset(vis,0,sizeof(vis));
        for(i=0; i<10005; i++)
            graph[i].clear();

        scanf("%d%d",&n,&m);
        for(i=1 ; i<=m ; i++)
        {
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
        }
        for(i=1 ; i<=n ; i++)
        {
            if(!vis[i])
                topDFS(i);
        }

        vector<int>vec;

        while(!ans.empty())
        {
            int x=ans.top();
            ans.pop();
            vec.push_back(x);
        }
        memset(vis,0,sizeof(vis));
        for(i=0 ; i<vec.size() ; i++)
        {
            if(!vis[vec[i]])
            {
                DFS(vec[i]);
                res++;
            }
        }
        printf("Case %d: %d\n",q,res);
    }
    return 0;
}

