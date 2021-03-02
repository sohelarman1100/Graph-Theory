///minimum spanning tree(kruskal)
///complexity eloge....e=no.of edge

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
            //cout<<pr[u]<<" "<<u<<endl;
            pr[u] = v; ///disjoint set union er union function er kaj korche
            //cout<<pr[u]<<" "<<u<<endl;
            count++;
            //cout<<e[i].u<<"  "<<e[i].v<<"  "<<e[i].w<<"  "<<pr[u]<<endl;
            s += e[i].w;
            if (count == n - 1) ///count er man n-1 holei sobgulo node edge diye connect hobe karon n
                /// sonkhok node connect korte n-1 edge holei chole jehetu ekhane cycle acceptable na and
                ///multiple edge o somvob na tai n-1 edge diyei n sonkhok node connect hoye jabe||
                break;
        }
    }
    return s;
}

int main()
{
    int n, m;
    cin >> n >> m;  ///n= no.of nodes......m= no.of edge
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back(edge(u,v,w));
    }
    cout << mst(n) << endl;
    cout<<pr[2]<<endl;
    return 0;
}

/*
5 8
1 2 1
1 5 3
2 5 2
2 3 6
2 4 4
4 5 5
4 3 8
5 3 7
*/
