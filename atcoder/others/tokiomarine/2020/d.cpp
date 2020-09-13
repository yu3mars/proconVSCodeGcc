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
    ll n;
    cin>>n;
    vector<ll> v(n+1), w(n+1);
    for (ll i = 1; i <= n; i++)
    {
        cin>>v[i]>>w[i];
    }
    ll qq;
    cin>>qq;
    vector<ll> uq(qq),lq(qq);
    for (ll i = 0; i < qq; i++)
    {
        cin>>uq[i]>>lq[i];
    }
    for (ll q = 0; q < qq; q++)
    {
        ll u=uq[q];
        ll l=lq[q];
        vector<ll> dp(l+1);
        unordered_set<ll> s;
        s.emplace(0);
        
        while (u>0)
        {
            unordered_set<ll> nexts;
            for(ll i : s)
            {
                if(i+w[u]<=l)
                {
                    dp[i+w[u]]=max(dp[i+w[u]], dp[i]+v[u]);
                    nexts.emplace(i+w[u]);
                }
            }
            for(ll i: nexts)
            {
                s.emplace(i);
            }
            u/=2;
        }
        ll ans=0;
        for (ll i = 0; i <= l; i++)
        {
            ans=max(ans,dp[i]);
        }
        cout<<ans<<endl;
    }
    
    return 0;
}