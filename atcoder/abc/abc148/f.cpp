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

int main()
{
    int n,u,v;
    cin>>n>>u>>v;
    u--;
    v--;
    WeightedGraph<int> g(n);
    for (int i = 0; i < n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        add_edge(g,a,b,1);
        add_edge(g,b,a,1);
    }
    auto taka=dijkstra(g,u);
    auto aoki=dijkstra(g,v);
    for (int i = 0; i < n; i++)
    {
        //cout<<i<<"\t"<<taka[i]<<"\t"<<aoki[i]<<endl;//
    }
    
    int pos=-1,score=0;
    for (int i = 0; i < n; i++)
    {
        if(i==u) continue;
        if(taka[i]<aoki[i])
        {
            int tmpScore=taka[i]+max(0,aoki[i]-taka[i]-1);
            if(score<tmpScore)
            {
                pos=i;
                score=tmpScore;
            }
        }
    }
    if(pos==-1)
    {
        score=1e9+7;
        for (int i = 0; i < n; i++)
        {
            if(i==u) continue;
            if(taka[i]==aoki[i])
            {
                score=min(score, taka[i]);
            }
        }
        if(score==1e9+7) score=0;
    }
    int TAdist=taka[v];
    if(TAdist%2==0)
    {
        score=max(score,taka[v]-1);
    }
    else
    {
        score=max(score,taka[v]-1);
    }
    
    //cout<<taka[v]<<endl;//
    //cout<<pos<<endl;//
    cout<<score<<endl;
    
    return 0;
}