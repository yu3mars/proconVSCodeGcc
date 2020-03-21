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
    ll n,k,ans=0;
    cin>>n>>k;
    vector<ll> h(n);
    for (int i = 0; i < n; i++)
    {
        cin>>h[i];
    }
    sort(all(h));
    for (int i = 0; i < n-k; i++)
    {
        ans+=h[i];
    }
    
    cout<<ans<<endl;

    return 0;
}