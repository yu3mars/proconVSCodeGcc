#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

ll mod = 1e9+7;


int main()
{
    ll n;
    cin>>n;
    ll ans=0;
    ll pw[100010];
    pw[0]=0;
    for(int i = 1; i < 100010; i++)
    {
        pw[i]=1;
        for(int j = 0; j < 10; j++)
        {
            pw[i]*=i;
            pw[i]%=mod;
        }
        
    }
    
    
    for(int p = 1; p <= n; p++)//p=max of p
    {
        for(int q = 1; q <= (n/p); q++)//q = max of q
        {
            ll pls = (pw[p]-pw[p-1]+mod)%mod;
            ll qls = (pw[q]-pw[q-1]+mod)%mod;
            ans+=(pls*qls);
            ans%=mod;
        }    
    }
    while(ans<0)
    {
        ans+=mod;
    }
    ans%=mod;

    cout<<ans<<endl;

    return 0;
}