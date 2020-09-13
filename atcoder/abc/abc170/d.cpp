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
    ll n,ans=0;
    cin>>n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    /*
    sort(all(a));
    for (int i = 0; i < n; i++)
    {
        //cout<<i<<" "<<a[i]<<endl;//
        bool ok=true;
        if(i==0 && n>1 && a[i]==a[i+1])
        {
            ok=false;
        }
        for (int j = 0; j < i; j++)
        {
            if(a[i]%a[j]==0)
            {
                //cout<<"false "<<a[j]<<endl;//
                ok=false;
                break;
            }
        }
        if(ok) ans++;
    }
    */

    unordered_map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        if(mp.find(a[i])==mp.end())
        {
            mp.emplace(make_pair(a[i],1LL));
        }
        else
        {
            mp[a[i]]++;
        }        
    }
    for (int i = 0; i < n; i++)
    {
        bool ok=true;
        auto div=divisor(a[i]);
        for (int j = 0; j < div.size(); j++)
        {
            if(mp.find(div[j])!=mp.end())
            {
                if(div[j]!=a[i])
                {
                    ok=false;
                    break;
                }
                else
                {
                    if(mp[div[j]]>1)
                    {
                        ok=false;
                        break;
                    }
                }
                
            }
        }
        if(ok) ans++;
    }
    
    
    cout<<ans<<endl;
    return 0;
}