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

int NIL =-1;
struct Node
{
    int parent, left,right;
};

Node t[110];
int n;
int d[110];
int h[110];




void setDepth(int u,int p)
{
    d[u]=p;
    if(t[u].right!=NIL)
    {
        setDepth(t[u].right,p+1);
    }
    if(t[u].left!=NIL)
    {
        setDepth(t[u].left,p+1);
    }
}

int setHeight(int u)
{
    int h1=0,h2=0;
    if(t[u].left!=NIL) 
    {
        h1=setHeight(t[u].left)+1;
    }
    if(t[u].right!=NIL) 
    {
        h2=setHeight(t[u].right)+1;
    }
    h[u]=max(h1,h2);
    return h[u];
}
int getSibling(int u)
{
    if(t[u].parent==NIL) return NIL;
    if(t[t[u].parent].left==u && t[t[u].parent].right!=NIL)
    {
        return t[t[u].parent].right;
    }
        if(t[t[u].parent].right==u && t[t[u].parent].left!=NIL)
    {
        return t[t[u].parent].left;
    }
    return NIL;
}
int getDegree(int u)
{
    int ret=0;
    if(t[u].left!=NIL) ret++;
    if(t[u].right!=NIL) ret++;
    return ret;
}
string getType(int u)
{
    string s;
    if(t[u].parent==NIL) s= "root";
    else if(t[u].left==NIL && t[u].right==NIL) s= "leaf";
    else s= "internal node";
    return s;
}

void print(int i)
{
    cout<<"node "<<i<<": parent = "<<t[i].parent<<
        ", sibling = "<<getSibling(i)<<
        ", degree = "<<getDegree(i)<<
        ", depth = "<<d[i]<<", height = "<<h[i]<<", "
        <<getType(i)<<endl;
}

int main(){
    int n;
    cin>>n;
    int root;
    for(int i = 0; i < n; i++)
    {
        t[i]=Node{NIL,NIL,NIL};
    }
    
    for(int i = 0; i < n; i++)
    {
        int id,l,r;
        cin>>id>>l>>r;
        t[id].left=l;
        t[id].right=r;
        if(l!=NIL) t[l].parent=id;
        if(r!=NIL) t[r].parent=id;
    }
    for(int i = 0; i < n; i++)
    {
        if(t[i].parent==NIL) root=i;
    }
    setDepth(root,0);
    setHeight(root);
    
    for(int i = 0; i < n; i++)
    {
        print(i);
    }
    
    return 0;
}