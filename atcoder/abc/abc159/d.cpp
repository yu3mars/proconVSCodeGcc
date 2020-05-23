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


int main()
{
    ll n,sm=0;
    cin>>n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    unordered_map<ll,ll> mp;
    
    for (int i = 0; i < n; i++)
    {
        if(mp.find(a[i])==mp.end())
        {
            mp.insert(make_pair(a[i],1LL));
        }
        else
        {
            mp[a[i]]++;
        }
    }

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        ll tmp = it->second;
        sm+=tmp*(tmp-1)/2;
    }
    for (int i = 0; i < n; i++)
    {
        ll tmp = mp.at(a[i]);
        ll ans = sm- tmp*(tmp-1)/2 + (tmp-1)*(tmp-2)/2;
        cout<<ans<<endl;
    }
    
    
    
    return 0;
}