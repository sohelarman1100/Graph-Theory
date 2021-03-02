#include<bits/stdc++.h>
using namespace std;
vector<int>vec;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root;
struct node* temp1;

void insrt(int value)
{
    struct node* nwnode=(struct node*)malloc(sizeof(struct node));
    nwnode->data=value;
    nwnode->left=NULL;
    nwnode->right=NULL;
    if(root==NULL)
    {
        root=nwnode;
    }
    else
    {
        struct node* temp=root;
        while(1)
        {
            if(nwnode->data <= temp->data)///condition true hole left e jabe
            {
                if(temp->left==NULL)
                {
                    temp->left=nwnode;
                    break;
                }
                else
                {
                    temp=temp->left;
                }
            }
            else
            {
                if(temp->right==NULL)
                {
                    temp->right=nwnode;
                    break;
                }
                else
                {
                    temp=temp->right;
                }
            }
        }
    }
}

void postorder(struct node* r)
{
    if(r==NULL)
        return;
    postorder(r->left);
    postorder(r->right);
    vec.push_back(r->data);
}

int main()
{
   root=NULL;
   int i,j,k,l,n;
   cin>>n;         ///number of node
   for(i=1; i<=n; i++)
   {
       cin>>k;
       insrt(k);
   }
   postorder(root);   ///left sub-tree-> right sub-tree-> root
   for(i=0; i<vec.size(); i++)
       cout<<vec[i]<<" ";
   cout<<endl;
   return 0;
}
