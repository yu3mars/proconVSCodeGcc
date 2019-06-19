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
        else//print
        {
            print();
        }
        
    }
    
    return 0;
}