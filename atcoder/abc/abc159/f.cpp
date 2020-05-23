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

ll dp[3010][3010]; // bgn, val, cnt
ll mod = 998244353;

int main()
{
    ll n,s,ans=0;
    cin>>n>>s;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        dp[i][0]=1;
    }
    
    for (int bgn = 0; bgn < n; bgn++)
    {
        for (int now = bgn; bgn < n; now++)
        {
            for (int valBef = 0; valBef <= s; valBef++)
            {
                int valAft = valBef+a[now];
                if(valAft>s) break;

                if(dp[bgn][valBef]>0)
                {
                    dp[bgn][valAft]+=dp[bgn][valBef];
                    dp[bgn][valAft]%=mod;
                }
            }
        }

        for (int now = 0; now <= bgn; now++)
        {
            cout<<now<<"\t"<<now<<"\t"<<dp[now][s]<<endl;
            ans+=dp[now][s];
            ans%=mod;
        }        
    }
    
    cout<<ans<<endl;
    
    return 0;
}