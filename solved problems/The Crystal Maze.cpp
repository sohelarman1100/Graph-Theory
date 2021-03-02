/** Is a node discoverable or not ? **/

#include<bits/stdc++.h>
using namespace std;
const int fx[] = {+1,-1,+0,+0};
const int fy[] = {+0,+0,+1,-1};

char grid[505][505];
int row,col,cnt=0;
int dis[505][505],vis[505][505];
vector<pair<int,int> >vec;
vector<pair<int,int> >vec1;

void BFS(int sx,int sy)
{
    int nx,ny;
    queue<pair<int,int> >q;
    q.push(make_pair(sx,sy));
    vis[sx][sy]=1;
    vec1.push_back(make_pair(sx,sy));
    //dis[sx][sy]=0;
    while(! q.empty())
    {
        pair<int,int> u = q.front();
        q.pop();
        for(int i=0 ; i<4 ; i++)
        {
            nx=u.first+fx[i];
            ny=u.second+fy[i];
            if(nx>0 && nx<=row && ny>0 && ny<=col && vis[nx][ny]==0 && grid[nx][ny]!='#')
            {
                if(grid[nx][ny]=='C')
                    cnt++;
                if(grid[nx][ny]=='.')
                    vec1.push_back(make_pair(nx,ny));
                vis[nx][ny]=1;
                q.push(make_pair(nx,ny));
            }
        }
    }
}
int main()
{
    int t,q;
    scanf("%d",&t);
    for(q=1; q<=t; q++)
    {
        int i,j,ans,x,y,ax,ay,bx,by,cx,cy,hx,hy,Q;
        //int ara[3];
        //char c;
        //vector<int>val;
        scanf("%d%d%d",&row,&col,&Q);
        getchar();
        for(i=1 ; i<=row ; i++)
        {
            for(j=1 ; j<=col ; j++)
            {
                cin>>grid[i][j];
                if(grid[i][j]=='.')
                {
                    vec.push_back(make_pair(i,j));
                }
            }
        }
        //cout<<vec.size()<<endl;
        for(i=0; i<vec.size(); i++)
        {
            pair<int,int>p=vec[i];
            if(vis[p.first][p.second]==0)
            {
                BFS(p.first,p.second);
                for(j=0; j<vec1.size(); j++)
                {
                    pair<int,int> p1=vec1[j];
                    dis[p1.first][p1.second]=cnt;
                }
                cnt=0;
                vec1.clear();
            }
        }
        vector<pair<int,int> >start;
        for(i=1; i<=Q; i++)
        {
            scanf("%d%d",&ax,&ay);
            start.push_back(make_pair(ax,ay));
            /*BFS(ax,ay);
            //val.push_back(cnt);
            //cnt=0;
            for(j=0; j<505; j++)
                memset(vis[j],0,sizeof(vis[j]));*/
        }
        printf("Case %d:\n",q);
        for(i=0; i<start.size(); i++)
        {
            pair<int,int> p3=start[i];
            printf("%d\n",dis[p3.first][p3.second]);
        }
        for(i=0; i<505; i++)
        {
            memset(grid[i],'0',sizeof(grid[i]));
            memset(dis[i],0,sizeof(dis[i]));
            memset(vis[i],0,sizeof(vis[i]));
        }
        vec.clear();
    }
    return 0;
}

