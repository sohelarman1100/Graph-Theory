#include<bits/stdc++.h>
using namespace std;

vector<int>graph[20005];
int vis[20005];
int ind_num=0;
stack<int>ans;
vector<pair<int,int> >vec;
map<string, int>toint;
//map<int, string>tostring;
map<int,int> pos;

void topDFS(int start)
{
    vis[start]=1;
    for(int i=0 ; i<graph[start].size() ; i++)
    {
        int u=graph[start][i];
        if(!vis[u])
            topDFS(u);
    }
    ans.push(start);
}

int main()
{
    int q,t;
    scanf("%d",&t);
    for(q=1; q<=t; q++)
    {
        int i,j,k,u,v,e,cnt=0,no=0;;
        string s1,s2;
        cin>>e;
        for(i=1 ; i<=e ; i++)
        {
            cin>>s1>>s2;
            if(toint[s1] == 0)
                toint[s1] = ++cnt;
            if(toint[s2] == 0)
                toint[s2] = ++cnt;
            u=toint[s1];
            v=toint[s2];
            pair<int,int>x(u,v);
            vec.push_back(x);
            graph[u].push_back(v);
        }
        for(i=1 ; i<=cnt ; i++)
        {
            if(!vis[i])
                topDFS(i);
        }
        while(!ans.empty())
        {
            int x=ans.top();
            ans.pop();
            pos[x]=++ind_num;
        }
        for(i=0; i<vec.size(); i++)
        {
            if(pos[vec[i].first]>pos[vec[i].second])
                no++;
        }
        if(no>0)
            printf("Case %d: No\n",q);
        else
            printf("Case %d: Yes\n",q);

        pos.clear();
        toint.clear();
        vec.clear();
        memset(vis,0,sizeof(vis));
        for(i=0; i<20005; i++)
            graph[i].clear();
    }
    return 0;
}

