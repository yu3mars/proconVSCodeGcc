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
    ll a,b,c,d,ans=0;
    cin>>a>>b>>c>>d;
    ll lc = c / __gcd(c,d) * d;
    ans = (b - b/c - b/d + b/lc) - 
        ((a-1) - (a-1)/c - (a-1)/d + (a-1)/lc);
    
    cout<<ans<<endl;
    return 0;
}