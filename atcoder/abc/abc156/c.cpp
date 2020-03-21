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
    ll n,ans=__LONG_LONG_MAX__;
    cin>>n;
    vector<ll> x(n);
    for (int i = 0; i < n; i++)
    {
        cin>>x[i];
    }
    for (int i = 0; i < 101; i++)
    {
        ll tmp=0;
        for (int j = 0; j < n; j++)
        {
            tmp+=(i-x[j])*(i-x[j]);
        }
        ans=min(ans,tmp);
    }
    cout<<ans<<endl;
    
    return 0;
}