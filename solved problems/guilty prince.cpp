#include<bits/stdc++.h>
using namespace std;

int sz,m,h,w;
vector <int> ara[100];
vector<int>graph[100005];
int vis[100005];
void DFS(int start)
{
    vis[start]=-1;
    for(int i=0;i<graph[start].size();i++)
    {
        int u=graph[start][i];
        if(!vis[u])
            DFS(u);
    }
}
int main()
{
    int i,j,u,v,w,h,m,n,k,l;
    cin>>w;
    cin>>h;
    //int ara[h][w];
    for(i=0;i<h;i++)
    {
        for(j=0; j<w; j++)
        {
            char c;
            cin>>c;
            if(c=='.')
                ara.push_back(1);
            else if(c=='#')
                ara.push_back(0);
            else if(c=='@')
            {
                ara.push_back(1);
                l=i;
                k=j;
            }
        }
    }
    DFS(ara[l][k]);
    for(i=1;i<=sz;i++)
        printf("%d ",vis[i]);
    return 0;
}
