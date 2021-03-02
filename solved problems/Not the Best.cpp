#include <bits/stdc++.h>
using namespace std;

#define inf 2147483647

vector<int>graph[100005],cost[100005];
int vis[100005],parent[100005];
int dist[100005],ara[100005],dist1[100005];
int n,e,mn,dist2[100005];
int numNodes, numEdges;

struct node
{
    int u;
    int cost;
    node(int _u, int _cost)
    {
        u = _u;
        cost = _cost;
    }
};
bool operator<(node A, node B)
{
    return A.cost>B.cost;
}

void dijstkra(int source)
{

    for(int i=1; i<=numNodes; i++)
    {
        dist[i]=inf;
    }

    priority_queue<node>q;
    q.push(node(source,0));
    dist[source] = 0;
    parent[source]=source;
    while(!q.empty())
    {
        node top = q.top();
        q.pop();
        int u=top.u;

        if(vis[u]==1)
            continue;
        vis[u]=1;
        for(int i=0; i<(int)graph[u].size(); i++)
        {
            int v=graph[u][i];
            if(dist[u] + cost[u][i] < dist[v])
            {
                dist[v]= dist[u] + cost[u][i];
                dist1[v]=dist[v];
                parent[v]=u;
                q.push(node(v, dist[v]));
            }
        }
    }
}

void dijstkra1(int source)
{

    for(int i=1; i<=numNodes; i++)
    {
        dist2[i]=inf;
    }

    priority_queue<node>q;
    q.push(node(source,0));
    dist2[source] = 0;
    dist[source]=inf;
    while(!q.empty())
    {
        node top = q.top();
        q.pop();
        int u=top.u;

        if(vis[u]==1)
            continue;
        vis[u]=1;
        for(int i=0; i<(int)graph[u].size(); i++)
        {
            int v=graph[u][i];
            if((dist2[u] + cost[u][i] > dist[v] && dist2[u] + cost[u][i] <= dist2[v]) || (dist1[u]+cost[u][i]>dist[v] && dist1[u]+cost[u][i]<dist2[v]) || (dist2[v]==dist[v] && dist2[u] + cost[u][i] > dist2[v]))
            {
                if(dist1[u]+cost[u][i]!=dist[v])
                    dist2[v]=min((dist2[u] + cost[u][i]),(dist1[u]+cost[u][i]));
                else
                    dist2[v]=dist2[u]+cost[u][i];
                q.push(node(v,dist2[v]));
            }
            else if(dist2[u]+cost[u][i]==dist[v] && dist2[v]==inf && v!=n)
            {
                dist2[v]=dist[v];
                q.push(node(v,dist2[v]));
            }
        }
    }
}

void minedge()
{
    for(int i=0; i<e; i++)
    {
        for(int j=0; j<graph[ara[i]].size(); j++)
        {
            if(cost[ara[i]][j]<mn)
            {
                mn=cost[ara[i]][j];
                //cout<<"mn="<<mn<<endl;
            }
        }
    }
}

int main()
{
    int j,t;
    scanf("%d",&t);
    for(j=1; j<=t; j++)
    {
        //cin>>numNodes>>numEdges;
        scanf("%d%d",&numNodes,&numEdges);
        mn=inf;
        e=0;
        for(int i=0; i<=numNodes; i++)
        {
            graph[i].clear();
            cost[i].clear();
            vis[i]=0;
            dist1[i]=0;
            ara[i]=0;
            parent[i]=0;
        }
        n=numNodes;
        for(int i=0; i<numEdges; i++)
        {
            int u, v, w;
            //cin>>u>>v>>w;
            scanf("%d%d%d",&u,&v,&w);
            graph[u].push_back(v);
            graph[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        dijstkra(1);//for minimum path of all nodes;
        for(int i=0; i<=numNodes; i++)
        {
            vis[i]=0;
        }
        dijstkra1(1);//for 2nd minimum path of all nodes;
        stack<int>path;
        path.push(n);
        while(path.top()!=1)
        {
            path.push(parent[path.top()]);
        }
        while(!path.empty())
        {
            ara[e++]=path.top();
            path.pop();
        }
        minedge();
        if(dist[n]==dist2[n])
             printf("Case %d: %d\n",j,dist[n]+(2*mn));
        else
            printf("Case %d: %d\n",j,min(dist2[n],dist[n]+(2*mn)));
    }
    return 0;
}

