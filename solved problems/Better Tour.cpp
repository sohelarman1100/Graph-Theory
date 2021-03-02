#include<bits/stdc++.h>
using namespace std;
#define inf 2147483647
int vis[50005];
int dis[50005],parent[50005];
vector<int>graph[50005];
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
    parent[start]=start;
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
                parent[v]=u;
                q.push(v);
                vis[v]=1;
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
        int n,e,i,u,v,mx=0;
        cin>>n;

        for(i=0; i<50005; i++)
        {
            graph[i].clear();
            vis[i]=0;
            dis[i]=0;
            parent[i]=0;
        }

        int ara[n];
        for(i=0; i<n; i++)
        {
            scanf("%d",&ara[i]);
            if(ara[i]>mx)
                mx=ara[i];
        }
        for(i=0 ; i<n-1 ; i++)
        {
            make_graph(ara[i],ara[i+1]);
        }
        for(i=0; i<n; i++)
        {
            sort(graph[ara[i]].begin(),graph[ara[i]].end());
        }
        BFS(ara[0]);
        stack<int>st;
        st.push(ara[n-1]);
        while(st.top()!=ara[0])
        {
            st.push(parent[st.top()]);
        }
        //cout<<"p="<<parent[ara[n-1]]<<endl;
        printf("Case %d:\n",q);
        printf("%d",st.top());
        st.pop();
        while(!st.empty())
        {
            printf(" %d",st.top());
            st.pop();
        }
        printf("\n");
    }
    return 0;
}

