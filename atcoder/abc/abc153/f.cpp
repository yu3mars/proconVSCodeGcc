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
    ll n,d,a,ans=0;
    cin>>n>>d>>a;
    d*=2;
    vector<pll> xh(n);
    for (int i = 0; i < n; i++)
    {
        ll x,h;
        cin>>x>>h;
        h=(h+a-1)/a;
        xh[i]=make_pair(x,h);
    }
    sort(all(xh));
    vector<ll> imos(n+1);
    ll nowBomb=0;
    
    ll l=0,r=0;
    while (l<n)
    {
        r=max(l,r);
        while (r<n-1 && xh[r+1].first-xh[l].first<=d)
        {
            r++;
        }
        nowBomb+=imos[l];
        ll needBomb=xh[l].second-nowBomb;
        if(needBomb>0)
        {
            ans+=needBomb;
            nowBomb=xh[l].second;
            imos[r+1]-=needBomb;
        }
        l++;
    }
    
    cout<<ans<<endl;
    
    return 0;
}