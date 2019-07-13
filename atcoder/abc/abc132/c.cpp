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
    ll n;
    cin>>n;
    vector<ll> d(n);
    for (int i = 0; i < n; i++)
    {
        cin>>d[i];
    }
    sort(all(d));
    ll ans = d[n/2]-d[n/2-1];
    cout<<ans<<endl;
    
    return 0;
}