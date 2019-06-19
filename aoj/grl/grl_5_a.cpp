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

const int MAX = 100010;
const ll INF = __INT_MAX__/3;

class Edge{
    public:
        int t,w;
        Edge(){}
        Edge(int t, int w):t(t),w(w){}
};

int n, d[MAX];
vector<Edge> G[MAX];

void bfs(int s){
    for(int i = 0; i < n; i++)
    {
        d[i]=INF;
    }
    queue<int> q;
    q.push(s);
    d[s]=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < G[u].size(); i++)
        {
            Edge e = G[u][i];
            if(d[e.t]==INF)
            {
                d[e.t]=d[u]+e.w;
                q.push(e.t);
            }
        }
    }
}

void solve(){
    bfs(0);
    int tgt=0;
    for(int i = 0; i < n; i++)
    {
        if(d[i]==INF) continue;
        if(d[tgt]<d[i]) 
        {
            tgt=i;
        }
    }
    bfs(tgt);
    int maxv=0;
    for(int i = 0; i < n; i++)
    {
        if(d[i]==INF) continue;
        if(maxv<d[i]) maxv=d[i];
    }
    cout<<maxv<<endl;
}

int main(){
    int e;
    cin>>n;
    for(int i = 0; i < n-1; i++)
    {
        int s,t,w;
        cin>>s>>t>>w;
        G[s].push_back(Edge(t,w));
        G[t].push_back(Edge(s,w));
    }
    solve();

    return 0;
}