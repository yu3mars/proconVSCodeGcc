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
    ll n,ans=0;
    cin>>n;
    vector<ll> x(n),l(n);
    for (int i = 0; i < n; i++)
    {
        cin>>x[i]>>l[i];
    }
    vector<pll> p(n);
    for (int i = 0; i < n; i++)
    {
        p[i]=make_pair(x[i]-l[i],x[i]+l[i]);
    }
    sort(all(p));
    ll now=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ll le=p[i].first;
        ll ri=p[i].second;
        if(now<=le)
        {
            now=ri;
            ans++;
        }
        else
        {
            now=min(now,ri);
        }
        
    }
    cout<<ans<<endl;
    
    return 0;
}