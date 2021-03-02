///SEGMENT TREE

///reference youtube channel loveextends code;

#include<bits/stdc++.h>
using namespace std;

#define mx 100001
int arr[mx];
int tree[mx * 4];///array arr er element gula sob somoy tree er leaf node hisebe thakbe mane eder kono
///child thakbe na..
void init(int node, int b, int e)
{
    if (b == e) {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = tree[Left] + tree[Right];
}
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2;
}
void update(int node, int b, int e, int i, int newvalue)///i num index newvalue diye update hobe mane
/// i num index e newvalue rakha hobe||
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
}
int main()
{
    int n,i,j,k,l,m,x,y;
    cout<<"enter the length of the array:"<<endl;
    cin >> n;
    cout<<"enter the elements of array:"<<endl;
    for(i=1; i<=n; i++)
        cin>>arr[i];

    init(1, 1, n);///init function array er element gulo use kore tree create korbe....tree[] er index
    /// always 1 thekei hobe mane root 1 num index e thakbe ar arr[] er ind jodi question onujai 0 theke
    ///kora lage tahole init e root er jonno perameter hisebe b(begining) and e(ending) er value 0 and n-1
    ///pathate hobe

    cout<<"enter the index range you want to query:"<<endl;
    cin>>x>>y;
    cout << query(1, 1, n, x, y) << endl;/// arr[] er x theke y number position er sum dibe query function
    cout<<"enter the index number you want to update:"<<endl;
    cin>>k;
    cout<<"enter the value you want to put in k'th position of arr[]:"<<endl;
    cin>>l;
    update(1, 1, n, k, l);
    cout<<"enter the index range you want to query after update arr[]:"<<endl;
    cin>>x>>y;
    cout << query(1, 1, n, x, y) << endl;
    return 0;
}
