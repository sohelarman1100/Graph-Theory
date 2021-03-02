#include<bits/stdc++.h>
using namespace std;

int sz,m,mx=0,p;
vector<int>graph[105];
int vis[105];
vector<int>dis[105];
int cst[101][3];
int node[101][3];
int cnt1=0,cnt2=1,cnt3=1,cost=0;

void DFS(int start)
{
    if(vis[start])
        return;
    vis[start]=1;
    for(int i=0; i<graph[start].size(); i++)
    {
        int u=graph[start][i];
        cost+=dis[start][i];
        if(graph[u].size()==0)
        {
            node[cnt1][cnt2++]=u;
            cst[cnt1][cnt3++]=cost;
            cost=0;
        }
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
        int i,j,u,v,d,a,b,c;
        //memset(dis,0,sizeof(dis));
        cnt1=0,cnt2=1,cnt3=1;
        for(i=0; i<101; i++)
        {
            memset(cst[i],0,sizeof(cst[i]));
            memset(node[i],0,sizeof(node[i]));
        }
        memset(vis,0,sizeof(vis));
        for(i=0; i<105; i++)
        {
            graph[i].clear();
            dis[i].clear();
        }
        scanf("%d",&m);
        //dis is the array where cost are stored
        for(i=1; i<=m; i++)
        {
            cin>>u>>v>>d;
            graph[u].push_back(v);
            dis[u].push_back(d);
        }
        for(i=1; i<=m; i++)
        {
            if(vis[i]==0 && graph[i].size()==2)
            {
                cnt1++;
                cnt2=1;
                cnt3=1;
                p=i;
                DFS(p);
            }
        }
        int path[101][3];
        for(i=0; i<101; i++)
            memset(path[i],0,sizeof(path[i]));
        path[1][1]=1;
        path[1][2]=2;
        int crnt=node[1][1];
        node[1][1]=-1;
        node[1][2]=-1;
        int colour=1;
        int brk=0;
        for(j=1; j<=cnt1; j++)
        {
            if(node[j][1]==crnt && node[j][1]!=-1 && node[j][2]!=-1)
            {
                node[j][1]=-1;
                crnt=node[j][2];
                node[j][2]=-1;
                path[j][2]=colour;
                path[j][1]=2;
                j=0;
                brk++;
            }
            if(node[j][2]==crnt && node[j][1]!=-1 && node[j][2]!=-1)
            {
                node[j][2]=-1;
                crnt=node[j][1];
                node[j][1]=-1;
                path[j][1]=colour;
                path[j][2]=2;
                j=0;
                brk++;
            }
            if(brk==cnt1)
                break;
        }
        int cst1=0,cst2=0;
        for(i=1; i<=cnt1; i++)
        {
            for(j=1; j<=2; j++)
            {
                if(path[i][j]==1)
                    cst1+=cst[i][j];
                if(path[i][j]==2)
                    cst2+=cst[i][j];
            }
        }
        int x=min(cst1,cst2);
        printf("Case %d: %d\n",q,x);
    }
    return 0;
}
