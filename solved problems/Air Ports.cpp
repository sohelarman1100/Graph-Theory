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

int pr[100005];
vector<edge> e;

void initialize(int n)///protiti node ke tar par banano hobe ar tader size ke 1 kora hobe
{
    for(int i = 1; i<=n; i++)
    {
        pr[ i ] = i ;
    }
}

int root(int num)///protiti node er root khuje ber kora jabe
{
    if(pr[num]==num)
        return num;
    return root(pr[num]);
}

int mst(int n,int A)
{
    sort(e.begin(), e.end());
    int mark[n+2];
    memset(mark,0,sizeof(mark));
    initialize(n);
    int count = 0, s = 0;
    for (int i = 0; i < (int)e.size(); i++)
    {
        int u = root(e[i].u);
        int v = root(e[i].v);
        if (u != v && e[i].w<A)
        {
            mark[u]=1;
            mark[v]=1;
            pr[u] = v;   ///disjoint set union er union function er kaj korche
            s += e[i].w;
        }
        else if(e[i].w>=A)
            break;
    }
    return s;
}

int main()
{
    int c,t;
    scanf("%d",&t);
    for(c=1; c<=t; c++)
    {
        int n, m,A;

        scanf("%d%d%d",&n,&m,&A);
        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            scanf("%d%d%d",&u,&v,&w);
            e.push_back(edge(u,v,w));
        }
        int s=mst(n,A);
        int rt,cnt[n+2];
        set<int>st;
        memset(cnt,0,sizeof(cnt));
        for(int i=1; i<=n; i++)
        {
                rt=root(i);
                st.insert(rt);
        }
        long long int ans=s+(st.size()*A);
        printf("Case %d: %lld %d\n",c,ans,st.size());
        e.clear();
    }
    return 0;
}

