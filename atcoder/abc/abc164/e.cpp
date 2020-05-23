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

template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;


template< typename T >
vector< T > dijkstra(WeightedGraph< T > &g, int s) {
  const auto INF = numeric_limits< T >::max();
  vector< T > dist(g.size(), INF);

  using Pi = pair< T, int >;
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  dist[s] = 0;
  que.emplace(dist[s], s);
  while(!que.empty()) {
    T cost;
    int idx;
    tie(cost, idx) = que.top();
    que.pop();
    if(dist[idx] < cost) continue;
    for(auto &e : g[idx]) {
      auto next_cost = cost + e.cost;
      if(dist[e.to] <= next_cost) continue;
      dist[e.to] = next_cost;
      que.emplace(dist[e.to], e.to);
    }
  }
  return dist;
}

const ll MONEY_MAX=5050;
const ll CITY_MAX=50;

int main()
{
    ll n,m,s;
    cin>>n>>m>>s;
    if(s>MONEY_MAX) s=5010; // ippai okane attemo muda
    vector<ll> u(m),v(m),a(m),b(m);
    vector<ll> c(n),d(n);
    for (ll i = 0; i < m; i++)
    {
        cin>>u[i]>>v[i]>>a[i]>>b[i];
        u[i]--;
        v[i]--;
    }
    
    for (ll i = 0; i < n; i++)
    {
        cin>>c[i]>>d[i];
    }
    
    WeightedGraph< ll > g((MONEY_MAX+10)*CITY_MAX); // syojikin * 50 + cityNumber
    
    // tetsudou rosen
    for (ll roseni = 0; roseni < m; roseni++)
    {
        for (ll moneyi = a[roseni]; moneyi <= 5010; moneyi++)
        {
            ll from,to;
            from = moneyi*CITY_MAX+u[roseni];
            to = (moneyi-a[roseni])*CITY_MAX+v[roseni];
            g[from].emplace_back(to,b[roseni]);
            
            from = moneyi*CITY_MAX+v[roseni];
            to = (moneyi-a[roseni])*CITY_MAX+u[roseni];
            g[from].emplace_back(to,b[roseni]);
        }
    }
    
    
    // ryougae
    for (ll cityi = 0; cityi < n; cityi++)
    {
        for (ll moneyi = 0; moneyi < MONEY_MAX; moneyi++)
        {
            ll from = moneyi*CITY_MAX+cityi;
            ll to = (moneyi+c[cityi])*CITY_MAX+cityi;
            if(to>MONEY_MAX) to=5010; // ippai okane attemo muda
            g[from].emplace_back(to,d[cityi]);
        }
    }
    
    auto dist=dijkstra(g,s*CITY_MAX);
    for (ll cityi = 1; cityi < n; cityi++)
    {
        ll ans=__LONG_LONG_MAX__/3;
        for (ll i = cityi; i < (ll)dist.size(); i+=CITY_MAX)
        {
            ans=min(ans,dist[i]);
        }
        cout<<ans<<endl;
    }
    

    
    return 0;
}