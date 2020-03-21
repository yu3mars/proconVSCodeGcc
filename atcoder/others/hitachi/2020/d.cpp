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


int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(m),b(m),c(k),d(k);
    for (int i = 0; i < m; i++)
    {
        cin>>a[i]>>b[i];
        a[i]--;
        b[i]--;
    }
    for (int i = 0; i < k; i++)
    {
        cin>>c[i]>>d[i];
        c[i]--;
        d[i]--;
    }
    
    vector<int> ans(n),ufRoot(n);
    UnionFind uf(n);
    vector<unordered_set<int>> frie(n);
    for (int i = 0; i < m; i++)
    {
        uf.unite(a[i],b[i]);
        frie[a[i]].emplace(b[i]);
        frie[b[i]].emplace(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        ufRoot[uf.root(i)]++;
    }
    
    vector<unordered_set<int>> block(n);
    for (int i = 0; i < k; i++)
    {
        if(uf.root(c[i])==uf.root(d[i]))
        {
            block[c[i]].emplace(d[i]);
            block[d[i]].emplace(c[i]);
        }

    }
    for (int i = 0; i < n; i++)
    {
        cout<<ufRoot[uf.root(i)]-frie[i].size()-block[i].size()-1;
        if(i==n-1) cout<<endl;
        else cout<<" ";
    }
    
    
    return 0;
}