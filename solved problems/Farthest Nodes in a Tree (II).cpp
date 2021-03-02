#include<bits/stdc++.h>
using namespace std;

int sz,m;
vector<int>graph[30005];
int vis[30005];
int mx1,mx2,mx;
int start2;
int val[30005];
vector<int>dis[30005];
vector<int>dis1[30005];

void DFS(int start)
{
    vector<int>vec;
    if(vis[start])
        return;
    vis[start]=1;
    for(int i=0; i<graph[start].size(); i++)
    {
        int u=graph[start][i];
        if(!vis[u])
        {
            if(graph[u].size()>1)
            {
                DFS(u);
                int s=dis[u].size();
                vec.push_back(dis[u][s-1]+dis[start][i]);
                //cout<<"u= "<<u<<"dis[start][i]="<<dis[start][i]<<" i= "<<i<<"  vec[i]= "<<vec[i]<<" dis[u][s-1]= "<<dis[u][s-1]<<endl;
            }


            if(graph[u].size()==1)
            {
                int k=dis[u][0];
                vec.push_back(k);
                vis[u]=1;
            }
        }

        if(i==graph[start].size()-1)
        {
            if(vec.size()>1)
            {
                sort(vec.begin(),vec.end());
                int p=vec.size();
                dis[start].push_back(vec[p-1]);
            }
            else
            {
                dis[start].push_back(vec[0]);
            }
        }
    }
    if(start==0)
    {
        int y=vec.size();
        if(y==1)
            mx1=vec[y-1];
        else
        {
            mx1=vec[y-1];
            mx2=vec[y-2];
        }
    }
}

void DFS1(int start,int dist)
{
    if(vis[start])
        return;
    vis[start]=1;
    if(dist>mx1)
    {
        mx1=dist;
        start2=start;
    }
    for(int i=0; i<graph[start].size(); i++)
    {
        int u=graph[start][i];
        //dist+=dis[start][u];
        if(!vis[u])
        {
            val[u]=dist+dis[start][i];
            DFS1(u,(dist+dis[start][i]));
        }
    }
}

void DFS2(int start,int dist)
{
    if(vis[start])
        return;
    vis[start]=1;
    if(dist>mx)
        mx=dist;
    for(int i=0; i<graph[start].size(); i++)
    {
        int u=graph[start][i];
        if(!vis[u] && u!=0)
        {

            val[u]=max((val[u]+mx2),(dist+dis1[start][i]));
            DFS2(u,(dist+dis1[start][i]));
        }
    }
}

int main()
{
    int t,q;
    scanf("%d",&t);
    for(q=1; q<=t; q++)
    {
        int i,j,u,v,w;
        //printf("Enter the number of node:");
        //cin>>sz;
        //printf("Enter the number of edge:");
        scanf("%d",&m);
        for(i=1; i<m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            graph[u].push_back(v); ///u number vertex theke kon kon vertex e jaowa jay ta grapg[u] vector e store hocce
            graph[v].push_back(u);
            dis[u].push_back(w);
            dis[v].push_back(w);
            dis1[u].push_back(w);
            dis1[v].push_back(w);
        }
        val[0]=0;
        DFS1(0,0);
        memset(vis,0,sizeof(vis));
        mx1=mx2=0;
        DFS(0);
        memset(vis,0,sizeof(vis));
        DFS2(start2,0);
        val[start2]=max((mx1+mx2),mx);
        printf("Case %d:\n",q);
        for(i=0; i<m; i++)
        {
            if(!vis[i])
                printf("%d\n",val[i]+mx1);
            else
                printf("%d\n",val[i]);
        }

        memset(vis,0,sizeof(vis));
        memset(val,0,sizeof(val));
        m=sz=mx1=mx2=0;

        for(i=0; i<30005; i++)
        {
            graph[i].clear();
            dis[i].clear();
            dis1[i].clear();
        }
    }
    return 0;
}
