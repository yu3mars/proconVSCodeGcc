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
    ll a,b,c,k;
    cin>>a>>b>>c>>k;
    ll ans=0;
    ans+=min(a,k);
    k-=min(a,k);
    k-=min(k,b);
    ans-=min(k,c);
    cout<<ans<<endl;
    
    return 0;
}