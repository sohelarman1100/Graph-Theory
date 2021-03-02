#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define  ms(a,b)      memset(a,b,sizeof(a))
#define  gcd(a, b)    __gcd(a,b)A
#define  lcm(a, b)    ((a)*(b)/gcd(a,b))
#define  PI            acos(-1.0)
#define  min3(a,b,c)    min(a,min(b,c))
#define  min4(a,b,c,d)  min(d,min(a,min(b,c)))
#define  max3(a,b,c)    max(a,max(b,c))
#define  max4(a,b,c,d)  max(d,max(a,max(b,c)))
#define llmx        9223372036854775807
#define llmn       -9223372036854775808
#define intmx       2147483647
#define intmn       -2147483648
#define F           first
#define S           second
#define mod         1000000007

///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///King's move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///Knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///Knight's move



#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl

/*
int bigmod(int x,int n,int M)   ///x=given number...n=power of x
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return bigmod((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*bigmod((x*x)%M,(n-1)/2,M))%M;

}
*/

/*
vector<ll>::iterator it,it1;
 it1=vec.begin();       //vector vec er first element er address return kore;
 it=lower_bound(vec.begin(), vec.end(), x);  //sorted vector e x er leftmost position er add return kore;
 k=it-it1;   // x er leftmost position vector e joto number index e ache ta paowa jabe
it=upper_bound(vec.begin(), vec.end(), x);   //sorted vector e x er rightmost pos er porer add return kore
k=it-it1-1  //// x er rightmost position vector e joto number index e ache ta paowa jabe;
int k=upper_bound(ara, ara+n, x) -ara // ara er moddhe rightmost x koto number element ta paowa jabe
int k=lower_bound(ara, ara+n, x) -ara // ara er moddhe leftmost x koto number element ta paowa jabe
vector er jonno iterator create na kore array er moto kaj kora jay ei khetre upper_bound(vec.begin(),vec.end(),x ) - vec.begin minus korte hobe.
*/
/*
ll bin(ll ara[], ll n, ll k)
{
    ll l=0,h=n-1,mid,ans=0;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(ara[mid]>=k)
        {
            h=mid-1;
            ans=mid;
        }
        else
            l=mid+1;
    }
    return ans;
}
*/

/*
Int a;
cin>>a;
int mx = *max_element(all(s));// s er element gulo theke max element return korbe;
int mn = *min_element(all(s));

*/

/*
 ll way(pair<ll,ll> x, pair<ll,ll> y)    //pair er array ba vector er second element er boro theke choto akare
                                                            //pair guloke sort korbe
{
       return x.second>y.second;
}
*/

/*
ll way(ll x, ll y)    //boro theke choto akare sort kore
{
    return x>y;
}
*/

vector<ll>graph[30005],wt[30005];
ll vis[30005],n;

pair<ll,ll>dfs(ll now)
{
    pair<ll,ll>p;
    ll mx=0,mx2=0,tot=0;
    vis[now]=1ll;
    if(graph[now].size()==1 && vis[graph[now][0]]==1)
        return (mp(0,0));
    for(ll i=0; i<graph[now].size(); i++)
    {
        ll cld=graph[now][i];
        ll dst=wt[now][i];
        if(!vis[cld])
        {
            p=dfs(cld);
            if(p.first>tot)
                tot=p.first;
            if(p.second+dst>mx)
            {
                mx2=mx;
                mx=p.second+dst;
            }
            else if(p.second+dst>mx2)
                mx2=p.second+dst;
        }
    }
    if(mx+mx2>tot)
        tot=mx+mx2;
    return (mp(tot,mx));
}

int main()
{
    ll q;
    cin>>q;
    for(ll t=1; t<=q; t++)
    {
        ll u,v,i,j,k,l,w;
        cin>>n;
        for(i=1; i<=n-1; i++)
        {
            cin>>u>>v>>w;
            graph[u].pb(v);
            graph[v].pb(u);
            wt[u].pb(w);
            wt[v].pb(w);
        }
        pair<ll,ll>res=dfs(0);
        cout<<"Case "<<t<<": "<<res.first<<endl;
        for(i=0; i<=n; i++)
            vis[i]=0;

        for(i=0; i<=n; i++)
        {
            graph[i].clear();
            wt[i].clear();
        }
    }
    return 0;
}
//pow() fun use korle long long int er jonno calculation vul hoy

