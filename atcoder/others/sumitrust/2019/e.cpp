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

ll mod=1000000007;

int main()
{
    ll n,ans=1;
    cin>>n;
    vector<ll> a(n);
    vector<ll> c(n+1);    //color
    for (ll i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    c[0]=3;
    
    for (ll i = 0; i < n; i++)
    {
        ans=(ans*c[a[i]])%mod;
        c[a[i]]--;
        c[a[i]+1]++;

    }
    cout<<ans<<endl;
    
    return 0;
}