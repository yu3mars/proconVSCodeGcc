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
  int g;

public:
  UnionFind(int n) : p(n, -1) {g=n;}

  int root(int x) { return p[x] < 0 ? x : p[x] = root(p[x]); }

  bool same(int x, int y) { return root(x) == root(y); }

  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (p[y] < p[x]) std::swap(x, y);
    if (p[x] == p[y]) --p[x];
    p[y] = x;
    g--;
    return true;
  }
  int groups(){
      return g;
  }
};

int main(){
    int n;
    cin>>n;
    int ans=n;
    vector<ll> x(n),y(n);
    for (int i = 0; i < n; i++)
    {
        cin>>x[i]>>y[i];
    }
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < a; b++)
        {
            UnionFind uf = UnionFind(n);
            ll diffx = x[a]-x[b];
            ll diffy = y[a]-y[b];

            for (int p = 0; p < n; p++)
            {
                for (int q = 0; q < p; q++)
                {
                    if((x[p]-x[q]==diffx && y[p]-y[q]==diffy) || 
                    (x[p]-x[q]==-diffx && y[p]-y[q]==-diffy) )
                    {
                        uf.unite(p,q);
                    }
                }
                
            }
            ans=min(ans,uf.groups());
        }
        
    }
    
    
    cout<<ans<<endl;
    return 0;
}