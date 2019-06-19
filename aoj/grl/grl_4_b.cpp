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

const int MAX = 10010;
const ll INF = __LONG_LONG_MAX__/3;

int n;
vector<int> G[MAX];
vector<int> ans;
bool visited[MAX];
int indeg[MAX];

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            indeg[v]--;
            if(indeg[v]==0 && visited[v]==false)
            {
                visited[v]=true;
                q.push(v);
            }
        }
    }
}

int main(){
    int e;
    cin>>n>>e;
    for(int i = 0; i < e; i++)
    {
        int s,t;
        cin>>s>>t;
        G[s].push_back(t);
        indeg[t]++;
    }
    
    for(int i = 0; i < n; i++)
    {
        if(indeg[i]==0 && visited[i]==false)
        {
            bfs(i);
        }
    }
    for(int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }
    

    return 0;
}