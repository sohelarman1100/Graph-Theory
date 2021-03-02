/// DSU

///reference hackerearth
///complexity O(n)

#include<bits/stdc++.h>
using namespace std;

int par[100005],siz[100005];

void initialize(int n)///protiti node ke tar par banano hobe ar tader size ke 1 kora hobe
{
    for(int i = 1; i<=n; i++)
    {
        par[ i ] = i ;
        siz[ i ] = 1;
    }
}

int root(int num)///protiti node er root khuje ber kora jabe
{
    if(par[num]==num)
        return num;
    par[num]=root(par[num]);
    return par[num];
}

void _union(int A,int B)///node guloke union kora hobe
{
    int root_A = root(A);
    int root_B = root(B);
    if(root_A!=root_B)
    {
        if(siz[root_A] < siz[root_B ])
        {
            par[root_A] = par[root_B];
            siz[root_B] += siz[root_A];
        }
        else
        {
            par[root_B] = par[root_A];
            siz[root_A] += siz[root_B];
        }
    }
}

/*bool _find(int A,int B)///duita node kono path diye connected kina ta ber korbe
{
    if( root(A)==root(B) )       ///if A and B have the same root, it means that they are connected.
        return true;
    else
        return false;
}*/

int main()
{
    int i,j,k,l,m,n,x,y;
    cin>>n>>m; ///n=no of node.....m= no. of edge
    initialize(n);
    for(i=1; i<=m; i++)
    {
        cin>>x>>y;
        //if(_find(x,y)==false)
        _union(x,y);
    }
    cout<<"enter the node number you want to know it's root and size:"<<endl;
    cin>>k;
    int rt=root(k);
    cout<<siz[k]<<" "<<par[k]<<" "<<endl;
    return 0;
}

/*
5 4
1 2
3 4
5 3
1 3
*/
