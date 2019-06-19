#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pic = pair<int, char>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

struct Node
{
    int key;
    Node *parent,*left,*right;
};

Node *root,*NIL;

void insert(int k)
{
    Node *y=NIL;    //parent of x
    Node *x=root;   //root
    Node *z=(Node *)malloc(sizeof(Node));
    z->key=k;
    z->left=NIL;
    z->right=NIL;
    while(x!=NIL){
        y=x;
        if(z->key < x->key)
        {
            x=x->left;
        }
        else
        {
            x=x->right;
        }        
    }
    z->parent=y;
    if(y==NIL)
    {
        root=z;
    }
    else
    {
        if(z->key < y->key)
        {
            y->left=z;
        }
        else
        {
            y->right=z;
        }  
    }
}

Node *find(int k)
{
    bool ret;
    Node *u=root;
    while(u!=NIL &&u->key!=k){
        if(k < u->key)
        {
            u=u->left;
        }
        else
        {
            u=u->right;
        }
        
    }
    return u;
}

void inorder(Node *u)
{
    if(u==NIL)return;
    inorder(u->left);
    cout<<" "<<u->key;
    inorder(u->right);
}

void preorder(Node *u)
{
    if(u==NIL)return;
    cout<<" "<<u->key;
    preorder(u->left);
    preorder(u->right);
}

void print()
{
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
}

Node *getMinimum(Node *z)
{
    while(z->left!=NIL){
        z=z->left;    
    }
    return z;
}

Node *getSuccessor(Node *z)
{
    if(z->right!=NIL)
    {
        return getMinimum(z->right);
    }
    Node *y = z->parent;
    while(y!=NIL && z==y->right){
        z=y;
        y=y->parent;
    }
    return y;
} 

void deleteNode(Node *z)
{
    Node *x;//child of y
    Node *y;//delete pos
    if(z->left==NIL||z->right==NIL)
    {
        y=z;
    }
    else 
    {
        y=getSuccessor(z);
    }
    if(y->left!=NIL)
    {
        x=y->left;
    }
    else
    {
        x=y->right;
    }
    
    if(x!=NIL)
    {
        x->parent=y->parent;
    }

    if(y->parent==NIL)
    {
        root = x;
    }
    else if(y==y->parent->left)
    {
        y->parent->left=x;
    }
    else
    {
        y->parent->right=x;
    }
    
    if(y!=z)
    {
        z->key=y->key;
    }
    free(y);
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        string ss;

        cin>>ss;
        if(ss=="insert")//insert
        {
            int nn;
            cin>>nn;
            insert(nn);
        }
        else if(ss=="find")
        {
            int nn;
            cin>>nn;
            if(find(nn)!=NIL)
            {
                cout<<"yes"<<endl;
            }
            else
            {
                cout<<"no"<<endl;
            }
            
        }
        else if(ss=="delete")
        {
            int nn;
            cin>>nn;
            deleteNode(find(nn));
        }
        else//print
        {
            print();
        }
        
    }
    
    return 0;
}