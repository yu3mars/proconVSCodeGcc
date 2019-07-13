#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


namespace sub {
template <typename T>
constexpr typename std::enable_if<std::is_integral<T>::value, T>::type
inf_sub() {
  return std::numeric_limits<T>::max() / 2 - 1000;
}

template <typename T>
constexpr typename std::enable_if<std::is_floating_point<T>::value, T>::type
inf_sub() {
  return std::min(std::numeric_limits<T>::max() / 2 - 1000, T(1e50));
}
}  // namespace sub

template <typename T> constexpr T inf() {
  static_assert(std::is_arithmetic<T>::value, "T must be arithmetic value");
  return sub::inf_sub<T>();
}

template <typename T> constexpr T zero() {
  static_assert(std::is_arithmetic<T>::value, "T must be arithmetic value");
  return T(0);
}

const long double pi = acos(-1.0);

template <class edge_t> class graph_t {
  std::vector<std::vector<edge_t>> g;

public:
  using reference = std::vector<edge_t> &;
  using const_reference = const std::vector<edge_t> &;
  using iterator = typename std::vector<edge_t>::iterator;
  graph_t() : g(0) { ; }
  graph_t(int n) : g(n) { ; }
  int size() const { return g.size(); }
  void push_back(const std::vector<edge_t> &es) { g.push_back(es); }
  reference operator[](int x) { return g[x]; }
  const_reference operator[](int x) const { return g[x]; }
  iterator &begin() { return begin(g); }
  iterator &end() { return end(g); }
};

template <typename Cost> class WeightedEdge {
public:
  using cost_type = Cost;
  int to;
  cost_type cost;
  WeightedEdge(int, int t, cost_type c) : to(t), cost(c) { ; }
};

template <typename Cost> using WeightedGraph = graph_t<WeightedEdge<Cost>>;

template <typename Cost>
void add_edge(WeightedGraph<Cost> &g, int from, int to, Cost cost) {
  g[from].emplace_back(from, to, cost);
}

template <typename edge_t, typename cost_type = typename edge_t::cost_type>
std::vector<cost_type> dijkstra(const graph_t<edge_t> &g, int s) {
  std::vector<cost_type> d(g.size(), inf<cost_type>());
  d[s] = zero<cost_type>();
  using P = std::pair<cost_type, int>;
  std::priority_queue<P, std::vector<P>, std::greater<P>> que;
  que.push(P(zero<cost_type>(), s));
  while (!que.empty()) {
    cost_type dist = que.top().first;
    int v = que.top().second;
    que.pop();
    if (d[v] < dist) continue;
    for (const auto &e : g[v]) {
      if (d[e.to] <= d[v] + e.cost) continue;
      d[e.to] = d[v] + e.cost;
      que.push(P(d[e.to], e.to));
    }
  }
  return d;
}

int main() {
    int n,m;
    cin>>n>>m;
    int V;
    V = n*3;

    WeightedGraph<int> g(V);
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        u--;v--;
        add_edge(g,u,v+n,1);
        add_edge(g,u+n,v+n*2,1);
        add_edge(g,u+n*2,v,1);
    }
    
    int ss,tt;
    cin>>ss>>tt;
    ss--;
    tt--;
    auto res = dijkstra(g, ss);
    if (res[tt] == inf<int>())
    {
        cout<<-1<<endl;
    }
    else cout<<res[tt]/3<<endl;
    return 0;
}