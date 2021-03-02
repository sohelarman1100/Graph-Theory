#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int u,v,w;
    edge(int _u,int _v,int _w)
    {
        u=_u;
        v=_v;
        w=_w;
    }
};

bool operator<(edge A, edge B)
{
    return A.w < B.w ;
}

int pr[100005],siz[100005];
vector<edge> e;

void initialize(int n)///protiti node ke tar par banano hobe ar tader size ke 1 kora hobe
{
    for(int i = 1; i<=n; i++)
    {
        pr[ i ] = i ;
        siz[i]=1;
    }
}

int root(int num)///protiti node er root khuje ber kora jabe
{
    if(pr[num]==num)
        return num;
    return root(pr[num]);
}

int mst(int n)
{
    sort(e.begin(), e.end());
    initialize(n);
    int count = 0, s = 0;
    for (int i = 0; i < (int)e.size(); i++)
    {
        int u = root(e[i].u);
        int v = root(e[i].v);
        if (u != v)
        {
            pr[u] = v;   ///disjoint set union er union function er kaj korche
            s += e[i].w;
        }
    }
    return s;
}

int main()
{
    int c,t;
    scanf("%d",&t);
    for(c=1; c<=t; c++)
    {
        int n, m,i,j,totsum=0,rt;
        scanf("%d",&n);
        int cnt[n+5];
        memset(cnt,0,sizeof(cnt));
        int ara[n+1][n+1];
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                scanf("%d",&ara[i][j]);
                totsum+=ara[i][j];
            }
        }
        for (i = 1; i <= n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(ara[i][j]!=0)
                    e.push_back(edge(i,j,ara[i][j]));
            }
        }
        int used=mst(n);
        for(i=1; i<=n; i++)
        {
            rt=root(i);
            cnt[rt]++;
        }
        if(cnt[rt]==n)
            printf("Case %d: %d\n",c,(totsum-used));
        else
            printf("Case %d: -1\n",c);
        e.clear();
    }
    return 0;
}

