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

ll dp[10010];

int main(){
    ll n,m,ww;
    cin>>n>>m>>ww;
    vector<ll> wtmp(n), vtmp(n), a(m),b(m);
    for (int i = 0; i < n; i++)
    {
        cin>>wtmp[i]>>vtmp[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin>>a[i]>>b[i];
        a[i]--;
        b[i]--;
    }
    
    vector<ll> w(n), v(n);
    UnionFind uf(n);
    for (int i = 0; i < m; i++)
    {
        uf.unite(a[i],b[i]);
    }
    for (int i = 0; i < n; i++)
    {
        w[uf.root(i)]+=wtmp[i];
        v[uf.root(i)]+=vtmp[i];
    }
    
    m0(dp);
    ll dplen=10010;
    for (ll item = 0; item < n; item++)
    {
        for (int omosa = dplen - 1; omosa >= 0; omosa--)
        {
            if(omosa>=w[item])
            {
                dp[omosa]=max(dp[omosa], dp[omosa-w[item]]+v[item]);
            }
        }
    }
    ll ans=0;
    for (ll i = 0; i <= ww; i++)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    
    return 0;
}