#include<bits/stdc++.h>
using namespace std;

int sz,m,n,p=0,q,on,tw;
vector<int>graph[20005];
int vis[20005];

void DFS(int start,int k)
{
    vis[start]=0;
    for(int i=0; i<graph[start].size(); i++)
    {
        int u=graph[start][i];
        if(k==1 && vis[u]==1)
            tw++;
        if(k==2 && vis[u]==1)
            on++;
        if(vis[u]==1 && k==1)
            DFS(u,2);
        else if(vis[u]==1 && k==2)
            DFS(u,1);
    }
}

int main()
{
    int t;
    cin>>t;
    for(int a=1; a<=t; a++)
    {
        int i,j,u,v,k=0,l,mn=20005,mx=0;
        for(i=0; i<=20005; i++)
            graph[i].clear();
        on=0;
        tw=0;
        memset(vis,0,sizeof(vis));

        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>u>>v;
            if(min(u,v)<mn)
                mn=min(u,v);
            if(max(u,v)>mx)
                mx=max(u,v);
            /*if(u>v)
                swap(u,v);*/
            vis[u]=1;///je sokol node graph e ache segulor jonno vis[] er value 1 kora hoccche
            vis[v]=1;
            //if(u!=v && u>0 && v>0)
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(i=mn; i<=mx; i++)
        {
            if(vis[i]==1)
            {
                on=1;
                tw=0;
                DFS(i,1);
                //cout<<on<<" "<<tw<<endl;
                k+=max(on,tw);
            }
        }
        cout<<"Case "<<a<<": "<<k<<endl;
    }
    return 0;
}
