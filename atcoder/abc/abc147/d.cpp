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

ll mod=1e9+7;

int main()
{
    ll n,ans=0;
    cin>>n;
    vector<ll> a(n);
    ll cnt0[64],cnt1[64];
    m0(cnt0);
    m0(cnt1);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 62; j++)
        {
            ll bi=(a[i]>>j);
            if((bi&1)==0)
            {
                cnt0[j]++;
            }
            else
            {
                cnt1[j]++;
            }
        }
    }
    for (int i = 0; i < 62; i++)
    {
        ans+=((1LL<<i)%mod)*((cnt0[i]*cnt1[i])%mod);
        ans%=mod;
    }
    cout<<ans<<endl;
    
    return 0;
}