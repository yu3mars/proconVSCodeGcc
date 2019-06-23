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
    bool ok=true;
    ll n,now=0;
    cin>>n;
    vector<pll> v(n);   //b,a
    for(int i = 0; i < n; i++)
    {
        ll a,b;
        cin>>a>>b;
        v[i]=make_pair(b,a);
    }
    sort(all(v));
    for(int i = 0; i < n; i++)
    {
        now+=v[i].second;
        if(now>v[i].first)
        {
            ok=false;
            break;
        }
    }
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}