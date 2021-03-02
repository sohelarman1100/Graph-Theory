///SEGMENT TREE WITH LAZY

///reference youtube channel loveextends code;
///jokhon ekta range er value update kora lage tokhon lazy prop diye seg tree kaj kore ar jokhon ek sathe
/// shudhu ekta index er value update kora lage tokhon normal seg tree diye kaj korlei hoy

#include<bits/stdc++.h>
using namespace std;

#define mx 100001
int arr[mx];
struct info
{
    long long int prop,sum;
};

struct info tree[mx * 4];

void init(int node, int b, int e)///tree create kora hobe ei function diye
{
    if (b == e)
    {
        tree[node].sum = arr[b];
        tree[node].prop=0;///initially sob index er propagate value 0 rakha hocche
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
    tree[node].prop=0;///initially sob index er propagate value 0 rakha hocche
}
int query(int node, int b, int e, int i, int j, int carry)
{
    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j)
        return tree[node].sum + carry * (e - b + 1);
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j, carry + tree[node].prop);
    int p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}
void update(int node, int b, int e, int i, int j, long long int x)///i theke j ei range jei node er moddhe
///porbe shei node x diye update hobe
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j)
    {
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x;
        return;
    }
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
}
int main()
{
    int n,i,j,k,l,m,x,y,p;
    cout<<"enter the length of the array:"<<endl;
    cin >> n;
    cout<<"enter the elements of array:"<<endl;
    for(i=1; i<=n; i++)
        cin>>arr[i];

    init(1, 1, n);///init function array er element gulo use kore tree create korbe

    cout<<"enter the index range you want to query:"<<endl;
    cin>>x>>y;
    cout << query(1, 1, n, x, y,0) << endl;/// arr[] er x theke y number position er sum dibe query function
    cout<<"enter the index range you want to update:"<<endl;
    cin>>k>>l;
    cout<<"enter the value you want to add with all the index of given range of array arr[]:"<<endl;
    cin>>p;
    update(1, 1, n, k,l, p);
    cout<<"enter the index range you want to query after update arr[]:"<<endl;
    cin>>x>>y;
    cout << query(1, 1, n, x, y,0) << endl;///carry er initial value 0 hobe tai last perameter e last
    /// argument 0 deya hoyeche|||
    return 0;
}
