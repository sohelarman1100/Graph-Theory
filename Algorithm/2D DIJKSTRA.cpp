///2D DIJKSTRA

#include <bits/stdc++.h>
using namespace std;
#define inf 2147483647
const int fx[]= {+1,-1,+0,+0};
const int fy[]= {+0,+0,+1,-1};

int grid[105][105];
int vis[105][105],cost[105][105],dist[105][105];
int n,e;
int row,clm;
struct node
{
    pair<int,int> u;
    int cost;
    node(pair<int,int> _u, int _cost) ///constructor
    {
        u = _u;
        cost = _cost;
    }
};
bool operator<(node A, node B)
{
    return A.cost>B.cost;
}

void dijkstra(pair<int,int> source)
{
    int nx,ny;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<clm; j++)
            dist[i][j]=inf;
    }

    priority_queue<node>q;
    q.push(node(source,grid[source.first][source.second]));
    dist[source.first][source.second] = grid[source.first][source.second];

    while(!q.empty())
    {
        node top = q.top();
        q.pop();
        pair<int,int> u=top.u;

        if(vis[u.first][u.second]==1)
            continue;
        vis[u.first][u.second]=1;
        for(int i=0; i<4; i++)
        {
            nx=u.first+fx[i];
            ny=u.second+fy[i];
            if(nx>=0 && nx<row && ny>=0 && ny<clm && dist[u.first][u.second]+grid[nx][ny]<dist[nx][ny])
            {
                dist[nx][ny] = dist[u.first][u.second] + grid[nx][ny];
                pair<int,int> v(nx,ny);
                q.push(node(v, dist[nx][ny]));
            }
        }
    }
}
int main()
{
    int i,j,k,l,m,n;
    cin>>row>>clm;
    for(i=0; i<row; i++)
    {
        for(j=0; j<clm; j++)
            cin>>grid[i][j];
    }
    pair<int,int>pr;
    cout<<"enter the cell number you want to start:"<<endl;
    cin>>pr.first>>pr.second;
    dijkstra(pr);
    cout<<"enter the cell number you want to reach:"<<endl;
    cin>>pr.first>>pr.second;
    cout<<dist[pr.first][pr.second]<<endl;
    return 0;
}

/*
5 5
31 100 65 12 18
10 13 47 157 6
100 113 174 11 33
88 124 41 20 140
99 32 111 41 20
*/
