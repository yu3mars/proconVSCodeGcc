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
  vector<int> s;

public:
  UnionFind(int n) : p(n, -1), s(n,1) {}

  int root(int x) { return p[x] < 0 ? x : p[x] = root(p[x]); }

  int size(int x) { return s[root(x)];}

  bool same(int x, int y) { return root(x) == root(y); }

  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (p[y] < p[x]) std::swap(x, y);
    s[x] = size(x) + size(y);
    if (p[x] == p[y]) --p[x];
    p[y] = x;

    return true;
  }
};

int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll> a(m), b(m), ans(m);
    
    for(int i = 0; i < m; i++)
    {
        cin>>a[m-i-1]>>b[m-i-1];
    }
    for(int i = 0; i < m; i++)
    {
        a[i]--;
        b[i]--;
    }
    UnionFind uf(n);
    ans[0]=n*(n-1)/2;
    for(int i = 0; i < m-1; i++)
    {
        
        if(uf.same(a[i],b[i]))
        {
            ans[i+1]=ans[i];
        }
        
        else
        {
            ans[i+1]=ans[i]-uf.size(a[i])*uf.size(b[i]);
            uf.unite(a[i],b[i]);
        }
        
    }
    

    for(int i = m - 1; i >= 0; i--)
    {
        cout<<ans[i]<<endl;
    }
    
    
    return 0;
}