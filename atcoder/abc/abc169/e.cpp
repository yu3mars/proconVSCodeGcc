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
    ll n;
    cin>>n;
    vector<ll> a(n),b(n);
    vector<pll> p(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i]>>b[i];
        p[i]=make_pair(a[i],b[i]);
    }
    sort(all(a));
    sort(all(b));
    ll ans;
    if(n%2==1)//odd
    {
        ll l=a[n/2];
        ll r=b[n/2];
        ans=r-l+1;
    }
    else
    {
        ll l=a[n/2]+a[n/2-1];
        ll r=b[n/2]+b[n/2-1];
        ans=r-l+1;
    }
    cout<<ans<<endl;

    return 0;
}