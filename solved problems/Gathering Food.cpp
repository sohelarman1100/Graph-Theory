#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll xd[]= {1,-1,0,0};
ll yd[]= {0,0,1,-1};
char grid[15][15];
ll vis[15][15];
pair<ll,ll>alp[26];
ll dis[15][15];
ll row,col,crx,cry,cnt=0,d=0;
char cchar;

void srch(ll x, ll y)
{
    ll nx,ny,px,py;
    queue<pair<ll,ll> >q;
    q.push(make_pair(x,y));
    vis[x][y]=1;
    dis[x][y]=0;
    while(! q.empty())
    {
        pair<int,int> u = q.front();
        vis[u.first][u.second]=1;
        q.pop();
        for(int i=0 ; i<4 ; i++)
        {
            nx=u.first+xd[i];
            ny=u.second+yd[i];

            if(nx>=0 && nx<row && ny>=0 && ny<row && vis[nx][ny]==0 && grid[nx][ny]!='#')
            {
                if(grid[nx][ny]==cchar+1)
                {
                    cnt++;
                    d+=dis[u.first][u.second]+1;
                    return;
                }
                else if(grid[nx][ny]=='.')
                {
                    vis[nx][ny]=1;
                    dis[nx][ny]=dis[u.first][u.second]+1;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
}


int main()
{
    ll q;
    cin>>q;
    for(ll t=1; t<=q; t++)
    {
        ll i,j,k,l,m,n;
        cnt=d=0;
        char mx='A';
        cin>>row;
        for(i=0; i<row; i++)
        {
            for(j=0; j<row; j++)
            {
                cin>>grid[i][j];
                if(grid[i][j]>='A' && grid[i][j]<='Z')
                {
                    if(grid[i][j]>=mx)
                        mx=grid[i][j];
                    alp[grid[i][j]-65]=make_pair(i,j);
                }
            }
        }


       /* for(i=0; i<=mx-65; i++)
        {
            cout<<alp[i].first<<"  "<<alp[i].second<<endl;
        }*/
        for(i=0; i<=mx-65; i++)
        {
            crx=alp[i].first;
            cry=alp[i].second;
            cchar=i+65;
            grid[crx][cry]='.';
            srch(crx,cry);
            memset(vis,0,sizeof(vis));
            memset(dis,0,sizeof(dis));
        }
        cout<<"Case "<<t<<": ";
        if(cnt==mx-65)
            cout<<d<<endl;
        else
            cout<<"Impossible"<<endl;
    }
    return 0;
}
