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
    ll n,m,ans=0;
    cin>>n>>m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(all(a));
    reverse(all(a));

    vector<pll> p(m);
    for (int i = 0; i < m; i++)
    {
        ll b,c;
        cin>>b>>c;
        p[i]=make_pair(c,b);
    }
    sort(all(p));
    reverse(all(p));
    ll ai=0,pi=0,cnt=0;
    while(cnt<n)
    {
        if(a[ai]>=p[pi].first)
        {
            ans+=a[ai];
            cnt++;
            ai++;
        }
        else
        {
            ll ninzu = min(p[pi].second, n-cnt);
            ans+=p[pi].first * ninzu;
            cnt+=ninzu;
            pi++;
        }
    }
    cout<<ans<<endl;
    return 0;
}