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
    ll a,b,n;
    cin>>a>>b>>n;
    ll x=min(n,b-1);
    ll ans=(a*x/b)-a*(x/b);
    cout<<ans<<endl;

    /*
    ll mx=0;
    for (int i = 0; i <= n; i++)
    {
        ll score = (a*i/b)-a*(i/b);
        //cout<<i<<"\t"<<score<<endl;
        mx=max(mx,score);
    }
    cout<<mx<<endl;
    */
    
    
    return 0;
}