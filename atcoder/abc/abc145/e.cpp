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
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n),f(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>f[i];
    }
    sort(all(a));
    sort(all(f));
    reverse(all(f));
    
    ll l=0,r=1e18;
    while(l<r)
    {
        ll mid=(l+r)/2;
        ll cnt=0;
        for (int i = 0; i < n; i++)
        {
            ll atmp = (mid)/f[i];
            cnt+=max(0LL,a[i]-atmp);
        }
        if(cnt<=k)
        {
            r=mid;
        }
        else 
        {
            l=mid+1;
        }
    }
    cout<<l<<endl;

    return 0;
}