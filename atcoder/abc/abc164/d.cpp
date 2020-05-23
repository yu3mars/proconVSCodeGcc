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
    string s;
    cin>>s;
    ll n=s.size();
    ll dp[2][2019];
    ll ans=0;
    m0(dp);
    for (ll si = 0; si < n; si++) //s[i];
    {
        ll nowi = s[si]-'0';
        dp[1][nowi]++;
        for (ll i = 0; i < 2019; i++)
        {
            ll tmp=(i*10+nowi)%2019;
            dp[1][tmp]+=dp[0][i];
        }
        ans+=dp[1][0];
        for (ll i = 0; i < 2019; i++)
        {
            dp[0][i]=dp[1][i];
            dp[1][i]=0;
        }
        
    }
    
    cout<<ans<<endl;
    
    return 0;
}