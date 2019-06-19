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

int main(){
    ll n;
    cin>>n;
    ll ans=n;
    vector<ll> a(3), b(3);
    for (int i = 0; i < 3; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cin>>b[i];
    }

    vector<pll> p(3);
    for (int i = 0; i < 3; i++)
    {
        p[i]=make_pair(a[i],b[i]);
    }
    sort(all(p));
    reverse(all(p));
    for (int i = 0; i < 3; i++)
    {
        a[i]=p[i].first;
        b[i]=p[i].second;
    }
    
    for (ll x = 0; x*a[0] <= n; x++)
    {
        for (ll y = 0; x*a[0]+y*a[1] <= n; y++)
        {
            ll z = (n -x*a[0] - y*a[1])/a[2];
            ll tmp=n;
            tmp+=x*(b[0]-a[0]) + y*(b[1]-a[1]);
            ans=max(ans,tmp);
            tmp+=z*(b[2]-a[2]);
            ans=max(ans,tmp);
            if(a[1]>b[1]) break;
        }
        if(a[0]>b[0]) break;
    }
    n=ans;

        
    for (int i = 0; i < 3; i++)
    {
        p[i]=make_pair(b[i],a[i]);
    }
    sort(all(p));
    reverse(all(p));
    for (int i = 0; i < 3; i++)
    {
        b[i]=p[i].first;
        a[i]=p[i].second;
    }

    for (ll x = 0; x*b[0] <= n; x++)
    {
        for (ll y = 0; x*b[0]+y*b[1] <= n; y++)
        {
            ll z = (n -x*b[0] - y*b[1])/b[2];
            ll tmp=n;
            tmp+=x*(a[0]-b[0]) + y*(a[1]-b[1]);
            ans=max(ans,tmp);
            tmp+=z*(a[2]-b[2]);
            ans=max(ans,tmp);
            if(a[1]<b[1]) break;

        }
        if(a[0]<b[0]) break;
    }
    
    cout<<ans<<endl;
    return 0;
}