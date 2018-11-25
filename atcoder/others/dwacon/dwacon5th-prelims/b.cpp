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
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n),imos(n+1),ls;
    imos[0]=0;
    for(ll i = 0; i < n; i++)
    {
        cin>>a[i];
        imos[i+1]=imos[i]+a[i];
    }
    
    for(ll r = 1; r <= n; r++)
    {
        for(ll l = 0; l < r; l++)
        {
            ls.push_back(imos[r]-imos[l]);
        }    
    }
    ll ans=0;

    
    for(int bitsft = 41; bitsft >= 0; bitsft--)
    {
        ll bit=(1LL<<bitsft);
        ll cnt=0;
        ll tmp=ans+bit;
        for(int i = 0; i < ls.size(); i++)
        {
            if((tmp & ls[i])==tmp) cnt++;
        }
        if(cnt>=k) ans=tmp;
    }
    

    cout<<ans<<endl;

    return 0;
}