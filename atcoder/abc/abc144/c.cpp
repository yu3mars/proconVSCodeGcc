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
    ll ans=n-1;
    for (ll i = 1; i <= sqrt(n); i++)
    {
        if(n%i==0)
        {
            ll j=n/i;
            ans=min(ans,i+j-2);
        }
    }
    cout<<ans<<endl;
    
    return 0;
}