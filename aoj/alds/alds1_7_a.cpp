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

Node t[100010];
int n;
int d[100010];


void print(int i)
{
    cout<<"node "<<i<<": parent = "<<t[i].parent<<", depth = "<<d[i];
    if(d[i]==0) cout<<", root, [";
    else if(t[i].left!=NIL) cout<<", internal node, [";
    else cout<<", leaf, [";
    int c;
    for(int j = 0, c=t[i].left; c!=NIL ; j++, c=t[c].right)
    {
        if(j>0) cout<<", ";
        cout<<c;
    }
    cout<<"]"<<endl;
}

void setDepth(int u,int p)
{
    d[u]=p;
    if(t[u].right!=NIL)
    {
        setDepth(t[u].right,p);
    }
    if(t[u].left!=NIL)
    {
        setDepth(t[u].left,p+1);
    }
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
        int id,k,bros=NIL;
        cin>>id>>k;
        for(int j = 0; j < k; j++)
        {
            int c;
            cin>>c;
            if(j==0) t[id].left=c;
            else
            {
                t[bros].right=c;
            }
            t[c].parent=id;
            bros=c;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(t[i].parent==NIL) root=i;
    }
    setDepth(root,0);
    
    for(int i = 0; i < n; i++)
    {
        print(i);
    }
    
    return 0;
}