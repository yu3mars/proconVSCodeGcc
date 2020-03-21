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

ll inf=__LONG_LONG_MAX__/3;

int main()
{
    ll h,n,ans=inf;
    cin>>h>>n;
    vector<ll> a(n),b(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i]>>b[i];
    }
    vector<ll> dp(50000);
    for (int i = 1; i < 50000; i++)
    {
        dp[i]=inf;
    }
    for (ll waza = 0; waza < n; waza++)
    {
        for (ll nowPlace = 0; nowPlace < h; nowPlace++)
        {
            dp[nowPlace+a[waza]]=min(dp[nowPlace+a[waza]], dp[nowPlace]+b[waza]);
            if(nowPlace+a[waza]>=h)
            {
                ans=min(ans,dp[nowPlace+a[waza]]);
            }
        }
    }
    cout<<ans<<endl;
    
    return 0;
}