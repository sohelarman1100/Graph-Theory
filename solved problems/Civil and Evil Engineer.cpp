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
    for(int i = 0; i<=n; i++)
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
            count++;
            s += e[i].w;
            if (count == n)
                break;
        }
    }
    return s;
}

int mst1(int n)
{
    initialize(n);
    int count = 0, s = 0;
    for (int i = (int)e.size()-1; i >=0; i--)
    {
        int u = root(e[i].u);
        int v = root(e[i].v);
        if (u != v)
        {
            pr[u] = v;   ///disjoint set union er union function er kaj korche
            count++;
            s += e[i].w;
            if (count == n)
                break;
        }
    }
    return s;
}

int main()
{
    int t,c;
    scanf("%d",&t);
    for(c=1; c<=t; c++)
    {
        int n, m;
        scanf("%d",&n);
        while(1)
        {
            int u, v, w;
            scanf("%d%d%d",&u,&v,&w);
            if(u==0 && v==0 && w==0)
                break;
            e.push_back(edge(u,v,w));
        }
        int minval=mst(n);
        int mxval=mst1(n);
        if((minval+mxval)%2!=0)
            printf("Case %d: %d/2\n",c,(minval+mxval));
        else
            printf("Case %d: %d\n",c,(minval+mxval)/2);
       e.clear();
    }
    return 0;
}


