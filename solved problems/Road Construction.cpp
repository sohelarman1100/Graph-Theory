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
    int tc,t;
    scanf("%d",&t);
    for(tc=1; tc<=t; tc++)
    {
        map<string,int>toint;
        int n, m,cnt=0;
        string s1,s2;
        scanf("%d",&n);
        for (int i = 1; i <= n; i++)
        {
            int u, v, w;
            cin>>s1>>s2>>w;
            //scanf("%s %s%d",s1,s2,&w);
            if(toint[s1]==0)
                toint[s1]=++cnt;
            if(toint[s2]==0)
                toint[s2]=++cnt;
            u=toint[s1];
            v=toint[s2];
            e.push_back(edge(u,v,w));
        }
        int ara[cnt+1],rt;
        memset(ara,0,sizeof(ara));

        int mincost=mst(cnt);

        for(int i=1; i<=cnt; i++)
        {
            rt=root(i);
            ara[rt]++;
        }
        if(ara[rt]==cnt)
            printf("Case %d: %d\n",tc,mincost);
        else
            printf("Case %d: Impossible\n",tc);
        e.clear();
    }
    return 0;
}

