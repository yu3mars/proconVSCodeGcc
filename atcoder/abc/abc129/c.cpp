#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};
ll mod=1e9+7;
ll dp[100010];
bool ok[100010];

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> a(m);
    for (int i = 0; i < 100010; i++)
    {
        ok[i]=true;
    }
    
    for (int i = 0; i < m; i++)
    {
        cin>>a[i];
        ok[a[i]]=false;
    }
    m0(dp);
    dp[0]=1;
    for (int i = 0; i < n; i++)
    {
        if(ok[i+1]==true)
        {
            dp[i+1]+=dp[i];
            dp[i+1]%=mod;
        }
        if(ok[i+2]==true)
        {
            dp[i+2]+=dp[i];
            dp[i+2]%=mod;
        }
    }
    cout<<dp[n]<<endl;
    
    return 0;
}