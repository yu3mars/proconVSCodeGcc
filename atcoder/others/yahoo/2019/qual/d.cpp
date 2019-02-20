#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

ll dp[200010][5]; //0 lhaji 1 start 2 end 3 rhaji 4 

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    for(int i = 0; i < 200010; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            dp[i][j]= LLONG_MAX/3;
        }        
    }
    for(int i = 0; i < 5; i++)
    {
        dp[0][0]=0;
    }
    for(int now = 0; now < n; now++)
    {
        ll dpmin = dp[now][0];
        dp[now+1][0] = dp[now][0] + a[now];
        ll haji;
        if(a[now]==0) haji=2;
        else haji = a[now]%2;
        dpmin=min(dpmin, dp[now][1]);
        dp[now+1][1] = dpmin+haji;
        ll mid;
        if(a[now]==0) mid=1;
        else mid = (a[now]+1)%2;
        dpmin=min(dpmin, dp[now][2]);
        dp[now+1][2] = dpmin+mid;
        dpmin=min(dpmin, dp[now][3]);
        dp[now+1][3] = dpmin+haji;
        dpmin=min(dpmin, dp[now][4]);
        dp[now+1][4] = dpmin+a[now];
    }

    ll ans = LLONG_MAX/3;
    for(int i = 0; i < 5; i++)
    {
        ans=min(ans,dp[n][i]);
    }
    cout<<ans<<endl;
    
    return 0;
}