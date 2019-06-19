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
    ll n;
    cin>>n;
    ll a[5];
    ll mi = LLONG_MAX;
    for(int i = 0; i < 5; i++)
    {
        cin>>a[i];
        mi = min(mi,a[i]);
    }
    ll ans = (n+mi-1)/mi + 4;
    cout<<ans<<endl;

    return 0;
}