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
    ll a,b,x;
    cin>>a>>b>>x;
    ll ans=0;
    for (ll keta = 1; keta <= 10; keta++)
    {
        ll tmp=(x-b*keta)/a;
        ll mx=1;
        for (ll ki = 0; ki < keta; ki++)
        {
            mx*=10;
        }
        mx--;

        mx=min(mx,(ll)1e9);
        //cout<<keta<<"\t"<<tmp<<"\t"<<mx<<endl;
        tmp=min(tmp,mx);
        ans=max(ans,tmp);
    }
    
    cout<<ans<<endl;
    
    return 0;
}