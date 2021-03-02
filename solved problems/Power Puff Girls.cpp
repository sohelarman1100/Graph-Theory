/** Is a node discoverable or not ? **/

#include<bits/stdc++.h>
using namespace std;
const int fx[] = {+1,-1,+0,+0};
const int fy[] = {+0,+0,+1,-1};

char grid[22][22];
int row,col;
int dis[22][22],vis[22][22];

void BFS(int sx,int sy)
{
    int nx,ny;
    queue<pair<int,int> >q;
    q.push(make_pair(sx,sy));
    vis[sx][sy]=1;
    dis[sx][sy]=0;
    while(! q.empty())
    {
        pair<int,int> u = q.front();
        q.pop();
        for(int i=0 ; i<4 ; i++)
        {
            nx=u.first+fx[i];
            ny=u.second+fy[i];
            if(nx>=0 && nx<row && ny>=0 && ny<col && vis[nx][ny]==0 && grid[nx][ny]!='#' && grid[nx][ny]!='m')
            {
                vis[nx][ny]=1;
                dis[nx][ny]=1+dis[u.first][u.second];
                q.push(make_pair(nx,ny));
            }
        }
    }
}
int main()
{
    int t,q;
    cin>>t;
    for(q=1; q<=t; q++)
    {
        int i,j,ans,x,y,ax,ay,bx,by,cx,cy,hx,hy;
        vector<int>pos[3];
        int ara[3];
        //cout<<"Enter the number of row & column : ";
        cin>>row>>col;
        getchar();
        for(i=0 ; i<row ; i++)
        {
            for(j=0 ; j<col ; j++)
            {
                cin>>grid[i][j];
                if(grid[i][j]=='a')
                {
                    pos[0].push_back(i);
                    pos[0].push_back(j);
                }
                if(grid[i][j]=='b')
                {
                    pos[1].push_back(i);
                    pos[1].push_back(j);
                }
                if(grid[i][j]=='c')
                {
                    pos[2].push_back(i);
                    pos[2].push_back(j);
                }
                if(grid[i][j]=='h')
                {
                    hx=i;
                    hy=j;
                }
            }
        }
        for(i=0; i<3; i++)
        {
            BFS(pos[i][0],pos[i][1]);
            ara[i]=dis[hx][hy];
            for(j=0; j<22; j++)
            {
                memset(dis[j],0,sizeof(dis[j]));
                memset(vis[j],0,sizeof(vis[j]));
            }
        }
        sort(ara,ara+3);
        printf("Case %d: %d\n",q,ara[2]);
        for(i=0; i<22; i++)
            memset(grid[i],'0',sizeof(grid[i]));
    }
}

