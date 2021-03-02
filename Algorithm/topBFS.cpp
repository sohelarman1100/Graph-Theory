///reference safayeter blog
///ekhane string niye kaj kora hoyeche tai protiti unique string er jonno value fixed kora legeche jodi node
///gulo int value hoy tahole ei value fixed er kaj kora lagbe na||
///complexity O(n*n)
#include<bits/stdc++.h>
using namespace std;

vector<int>graph[1005];
vector<int>ans;
int in_deg[1005] , node;
map<string,int>toint;
map<int,string>tostring;
void topBFS()
{
    queue<int>q;///priority queue use korle je node er jonno int value beshi se node queue te priority pabe
    ///mane to_int() use kore graph er protiti unique string er jonno je int value fixed kora hoyeche oi
    ///value jar beshi seti queue te priority pabe|||
    for(int i=1 ; i<=node ; i++)
    {
        if(in_deg[i] == 0)
            q.push(i);
    }
    while(!q.empty())
    {
        int u=q.front();
        ans.push_back(u);
        q.pop();
        for(int i=0 ; i<graph[u].size() ; i++)
        {
            int v=graph[u][i];
            in_deg[v]--;
            if(in_deg[v] == 0)
                q.push(v);
        }
    }
}
int main()
{
    int i,j,k,n,e,u,v,cnt=0;
    string s1,s2;
    cin>>e;
    for(i=1 ; i<=e ; i++)
    {
        cin>>s1>>s2;
        if(toint[s1] == 0)
        {
            toint[s1] = ++cnt;
            tostring[cnt] = s1;
        }
        if(toint[s2] == 0)
        {
            toint[s2] = ++cnt;
            tostring[cnt] = s2;
        }
        u=toint[s1];
        v=toint[s2];
        graph[u].push_back(v);
        in_deg[v]++;   ///calculating in degree of each vertex....jehetu egde (u,v) u er dik hote v er dike
        /// direction thik rekhe jay tar mane u theke ber howa edge v te enter korche tai v er indegree increment hocche||

    }

    node=cnt; ///jodi node er songkha bola na thake tahole node calculation e dorkar hole node=cnt nite hobe
    ///karon karon cnt er man protita unique node er jonno ek kore bare tar mone 5ti unique node thakle cnt er
    /// man 5 hobe mane graph e total 5 ti node ache|||

    topBFS();
    printf("Sorted order of all task : \n");
    for(i=0 ; i<ans.size() ; i++)
    {
        cout<<tostring[ans[i]]<<"\t";
    }
    printf("\n");
    return 0;
}
/**
8
Breakfast Office
Dress Office
Office Email
Office Dinner
Office Sports
Email Dinner
Email Sports
Dinner Sports
**/
