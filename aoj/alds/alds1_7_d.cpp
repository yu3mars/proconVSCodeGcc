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

int n;
vector<int> pre,in,post;
int pos;

void rec(int l,int r)
{
    if(l>=r) return;
    int root=pre[pos];
    pos++;
    int m;
    for(int i = 0; i < n; i++)
    {
        if(in[i]==root)
        {
            m=i;
            break;
        }
    }
    rec(l,m);
    rec(m+1,r);
    post.push_back(root);
}


int main(){
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        int nn;
        cin>>nn;
        pre.push_back(nn);
    }
    for(int i = 0; i < n; i++)
    {
        int nn;
        cin>>nn;
        in.push_back(nn);
    }
    pos=0;
    rec(0,n);
    for(int i = 0; i < n; i++)
    {
        if(i>0) cout<<" ";
        cout<<post[i];
    }
    
    cout<<endl;
    
    return 0;
}