#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int main()
{
    int l,k;
    ll ans=0;
    cin>>l>>k;
    ll dp[120][2]; //black, white
    m0(dp);
    dp[0][1]=1;
    for(int i = 0; i < l; i++)
    {
        dp[i+1][1]+=dp[i][0];
        dp[i+k][0]+=dp[i][1];
        dp[i+1][0]+=dp[i][1];
    }
    
    for(int i = 1; i <= l; i++)
    {
        ans+=dp[i][0];
    }
    cout<<ans<<endl;

    return 0;
}