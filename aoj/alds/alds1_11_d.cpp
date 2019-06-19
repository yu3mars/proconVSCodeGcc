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

int NIL=-1;
vector<int> ls[100010];
int color[100010];
int n,m;

void bfs(int s, int c)
{
    color[s]=c;
    queue<int> q;
    q.push(s);
    while(q.empty()==false){
        int u = q.front();
        q.pop();
        for(int vi = 0; vi < ls[u].size(); vi++)
        {
            int v=ls[u][vi];
            if(color[v]==NIL)
            {
                color[v]=c;
                q.push(v);
            }
        }
    }
    
}

int main(){
    m0(ls);
    m0(color);
    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        color[i]=NIL;
    }
    

    for(int i = 0; i < m; i++)
    {
        int from,to;
        cin>>from>>to;
        ls[from].push_back(to);
        ls[to].push_back(from);
    }
    
    int col=1;
    for(int i = 0; i < n; i++)
    {
        if(color[i]==NIL)
        {
            bfs(i,col);
            col++;
        }    
    }

    int q;
    cin>>q;
    for(int qq = 0; qq < q; qq++)
    {
        int s,t;
        cin>>s>>t;
        if(color[s]==color[t])
        {
            cout<<"yes"<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }
    }
    
    return 0;
}