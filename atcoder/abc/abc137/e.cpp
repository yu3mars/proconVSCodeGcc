#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

struct Edge {
    ll to, cost;
};
typedef vector<vector<Edge> > AdjList;  // 隣接リストの型
AdjList graph;

const ll INF = 1e15;

vector<ll> dist;
vector<ll> pre;


bool bellman_ford(ll n, ll s){
    dist = vector<ll>(n,INF);
    pre = vector<ll>(n,-1);
    dist[s] = 0;
    for(ll i=0;i<n;i++){
        for(ll v=0;v<n;v++){
            for(ll k=0;k<graph[v].size();k++){
                Edge e = graph[v][k];
                if(dist[v] != INF && dist[e.to] > dist[v] + e.cost){
                    dist[e.to] = dist[v] + e.cost;
                    pre[e.to] = v;
                    if(i == n-1)
                    {
                        //cout<< "from:"<<v<<"\tto:"<<e.to<<endl;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool checkPath(ll to)
{
    unordered_set<ll> se;
    for (; to != -1; to=pre[to])
    {
        if(se.find(to)!=se.end()) return false;
        se.insert(to);
    }
    return true;
}

vector<ll> getPath(ll to)
{
    vector<ll> path;
    for (; to != -1; to=pre[to])
    {
        path.push_back(to);
    }
    reverse(all(path));
    return path;
}

int main(void){
    ll n,m,p;
    cin>>n>>m>>p;

    graph = AdjList(n);

    for(ll i=0;i<m;i++){
        ll from, to, cost;
        cin >> from >> to >> cost;
        from--;
        to--;
        cost-=p;
        graph[from].push_back((Edge){to,-cost});
    }

    bool hasNega = bellman_ford(n,0);
    //cout<<hasNega<<endl;

    if(checkPath(n-1)==true)
    {
        cout<<max(0LL, -dist[n-1])<<endl;
        /*
        for (ll i = 1; i < n; i++){
        if(dist[i] != INF){
            //cout << i << " " << dist[i] << endl;
        }
        }

        for (int i = 0; i < pre.size(); i++)
        {
            //cout<<"pre:"<<i<<":"<<pre[i]<<endl;
        }
        

        auto path = getPath(n-1);
        cout<<"path: ";
        for (int i = 0; i < path.size(); i++)
        {
            cout<<path[i]<<" ";
        }
        cout<<endl;
        */
    }
    else
    {
        cout<<-1<<endl;
    }
    

    
    return 0;
}
