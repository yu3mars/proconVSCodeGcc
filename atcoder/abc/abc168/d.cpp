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
vector< T > dijkstra(WeightedGraph< T > &g, int s) {//kaizou shimasita
  const auto INF = numeric_limits< T >::max();
  vector< T > dist(g.size(), INF);
  vector< T > from(g.size(), INF);  

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
      
      from[e.to]=e.src;
    }
  }
  return from;
  //return dist;
}

int main()
{
    int n,m;
    cin>>n>>m;
    WeightedGraph< int > g(n);
    vector<int> a(m),b(m);
    for (int i = 0; i < m; i++)
    {
        cin>>a[i]>>b[i];
        a[i]--;
        b[i]--;
    }
    for (int i = 0; i < m; i++)
    {
        g[a[i]].emplace_back(a[i],b[i],1);
        g[b[i]].emplace_back(b[i],a[i],1);
    }
    vector<int> di = dijkstra(g,0);
    
    cout<<"Yes"<<endl;
    for (int i = 1; i < n; i++)
    {
        cout<<di[i]+1<<endl;
    }
    
    
    
    return 0;
}