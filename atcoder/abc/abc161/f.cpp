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

vector< ll > divisor(ll n) {
  vector< ll > ret;
  for(ll i = 1; i * i <= n; i++) {
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
    ll n;
    cin>>n;
    vector<ll> ndiv=divisor(n), n1div=divisor(n-1);

    ll ans=n1div.size()-1;
    
    for (int i = 1; i < ndiv.size(); i++)
    {

        ll kouho = ndiv[i];
        ll tmp=n;
        while (kouho<=tmp)
        {
            if(tmp%kouho==0) tmp/=kouho;
            else tmp %= kouho;
        }
        if(tmp==1) ans++;
    }
    

    cout<<ans<<endl;
    
    return 0;
}