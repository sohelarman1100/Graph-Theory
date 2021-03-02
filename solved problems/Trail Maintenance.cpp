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

int pr[205];
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
    pr[num]=root(pr[num]);
    return pr[num];
}

int mst(int n)
{
    sort(e.begin(), e.end());
    initialize(n);
    int cnt = 0, s = 0;
    vector<edge>temp;
    for (int i = 0; i < (int)e.size(); i++)
    {
        int u = root(e[i].u);
        int v = root(e[i].v);
        if (u != v)
        {
            pr[u] = v;   ///disjoint set union er union function er kaj korche
            s += e[i].w;
            temp.push_back(e[i]);
            cnt++;
            if(cnt==n-1)
                break;
        }
    }
    e.clear();
    e=temp;
    if(cnt==n-1)
        return s;
    return -1;
}

int main()
{
    int c,t;
    scanf("%d",&t);
    for(c=1; c<=t; c++)
    {
        int n, m,cnt=0;
        scanf("%d%d",&n,&m);
        int mark[n+2];
        memset(mark,0,sizeof(mark));
        printf("Case %d:\n",c);
        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            scanf("%d%d%d",&u,&v,&w);
            e.push_back(edge(u,v,w));
            printf("%d\n",mst(n));
        }
        e.clear();
    }
    return 0;
}

