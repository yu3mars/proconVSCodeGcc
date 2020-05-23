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
    ll n;
    cin>>n;
    vector<ll> a(n),s(n+1);
    s[0]=0;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        s[i+1]=s[i]+a[i];
    }
    ll sm=s[n];
    ll ans=__LONG_LONG_MAX__;
    for (int i = 0; i < n; i++)
    {
        ans=min(ans,abs(2*s[i]-sm));
    }
    cout<<ans<<endl;
    
    return 0;
}