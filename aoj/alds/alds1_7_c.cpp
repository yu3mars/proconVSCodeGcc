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

void preParse(int u)
{
    if(u==NIL) return;
    cout<<" "<<u;
    preParse(t[u].left);
    preParse(t[u].right);
}
void inParse(int u)
{
    if(u==NIL) return;
    inParse(t[u].left);
    cout<<" "<<u;    
    inParse(t[u].right);
}
void postParse(int u)
{
    if(u==NIL) return;
    postParse(t[u].left);
    postParse(t[u].right);
    cout<<" "<<u;
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
    cout<<"Preorder"<<endl;
    preParse(root);
    cout<<endl;
    cout<<"Inorder"<<endl;
    inParse(root);
    cout<<endl;
    cout<<"Postorder"<<endl;
    postParse(root);
    cout<<endl;
    
    return 0;
}