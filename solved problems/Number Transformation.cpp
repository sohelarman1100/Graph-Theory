#include<bits/stdc++.h>
using namespace std;

int prime[1005];
int n=1005,k=0;
vector<int>graph[2005];
int vis[2005];
int dis[2005];

void seivePrime()
{
    int i,j,limit=sqrt(n*1)+2;
    int mark[n+1];
    memset(mark, 0,sizeof(mark));
    mark[1]=1;
    prime[k++]=2;
    for(i=4; i<=n; i+=2)
        mark[i]=1;
    for(i=3; i<=n; i+=2)
    {
        if(!mark[i])
        {
            prime[k++]=i;
            if(i<=limit)
            {
                for(j=i*i; j<=n; j+=i*2)
                    mark[j]=1;
            }
        }
    }

}

void graph_of_digit_and_primes_sum()
{
    for(int i=0; i<k; i++)
    {
        for(int j=prime[i]; j<=1000; j+=prime[i])
        {
            if(j!=prime[i])
                graph[j].push_back(j+prime[i]);
        }
    }
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

int main()
{
    seivePrime();
    graph_of_digit_and_primes_sum();
    int q,t;
    scanf("%d",&t);
    for(q=1; q<=t; q++)
    {
        memset(vis,0,sizeof(vis));
        memset(dis,0,sizeof(dis));
        int a,b;
        scanf("%d%d",&a,&b);
        BFS(a);
        if(vis[b]>0)
            printf("Case %d: %d\n",q,dis[b]);
        else
            printf("Case %d: -1\n",q);
    }
    return 0;
}
