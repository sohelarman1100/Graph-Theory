#include<bits/stdc++.h>
using namespace std;

vector<int>graph[1005];
int vis[1005];
int money[1005];
int avg=0,dif=0;

void DFS(int start)
{
    if(vis[start])
        return;
    vis[start]=1;
    for(int i=0; i<graph[start].size(); i++)
    {
        int u=graph[start][i];
        if(!vis[u])
        {
            if(money[start]>avg)
            {
                dif=money[start]-avg;
                money[start]=avg;
                money[u]=money[u]+dif;
            }
            DFS(u);
            if(money[u]>avg)
            {
                dif=money[u]-avg;
                money[u]=avg;
                money[start]=money[start]+dif;
            }
        }
    }
}
int main()
{
    int q,t;
    scanf("%d",&t);
    for(q=1; q<=t; q++)
    {
        int i,j,u,v,n,m,sum=0,tr=0;

        memset(vis,0,sizeof(vis));
        memset(money,0,sizeof(money));

        for(i=0; i<=1005; i++)
            graph[i].clear();

        scanf("%d%d",&n,&m);
        for(i=1; i<=n; i++)
        {
            cin>>money[i];
            sum+=money[i];
        }
        for(i=1; i<=m; i++)
        {
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        if(sum%n!=0)
            printf("Case %d: No\n",q);
        else
        {
            avg=sum/n;
            for(i=1; i<=n; i++)
            {
                if(!vis[i])
                    DFS(i);
            }

            memset(vis,0,sizeof(vis));

            for(i=1; i<=n; i++)
            {
                if(!vis[i])
                    DFS(i);
            }

            for(i=1; i<=n; i++)
            {
                if(money[i]!=avg)
                {
                    printf("Case %d: No\n",q);
                    tr++;
                    break;
                }
            }
            if(tr==0)
                printf("Case %d: Yes\n",q);
        }
    }
    return 0;
}

