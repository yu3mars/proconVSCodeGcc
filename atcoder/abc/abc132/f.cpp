#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

ll mod = 1e9+7;
ll dp[110][32000]; //sqrt(1e9)==31622.7

int main()
{
    ll n,k;
    cin>>n>>k;
    m0(dp);
    ll sqrtn = sqrt(n);
    for (ll i = 1; i <= sqrtn; i++)
    {
        dp[0][i]=1;
    }
    dp[0][sqrtn+1] = n-sqrtn;
    

    return 0;
}