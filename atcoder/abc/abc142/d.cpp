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

vector< int64_t > divisor(int64_t n) {
  vector< int64_t > ret;
  for(int64_t i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

int main()
{
    ll a,b;
    cin>>a>>b;
    ll g = __gcd(a,b);
    auto di = divisor(g);
    sort(all(di));
    vector<ll> ans;
    ans.push_back(1);
    for (int i = 0; i < di.size(); i++)
    {
        ll now = di[i];
        bool ok = true;
        for (int j = 0; j < ans.size(); j++)
        {
            if(__gcd(now,ans[j])==1) continue;
            else
            {
                ok=false;
                break;
            }
        }
        if(ok)
        {
            ans.push_back(now);
        }        
    }
    
    cout<<ans.size()-1<<endl;
    return 0;
}