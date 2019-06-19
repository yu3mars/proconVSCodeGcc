#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

class UnionFind {
  std::vector<int> p;

public:
  UnionFind(int n) : p(n, -1) {}

  int root(int x) { return p[x] < 0 ? x : p[x] = root(p[x]); }

  bool same(int x, int y) { return root(x) == root(y); }

  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (p[y] < p[x]) std::swap(x, y);
    if (p[x] == p[y]) --p[x];
    p[y] = x;
    return true;
  }
};

int main()
{
    ll n,m;
    cin>>n>>m;
    UnionFind uf = UnionFind(n);
    for (int i = 0; i < m; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        x--;
        y--;
        uf.unite(x,y);
    }
    unordered_set<ll> us;
    for (int i = 0; i < n; i++)
    {
        us.emplace(uf.root(i));
    }
    cout<<us.size()<<endl;    

    return 0;
}