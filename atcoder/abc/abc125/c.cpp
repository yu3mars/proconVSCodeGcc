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
    int n;
    cin>>n;

    vector<ll> a(n),l(n),r(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    l[0]=a[0];
    for (int i = 1; i < n; i++)
    {
        l[i]=__gcd(l[i-1],a[i]);
    }
    r[n-1]=a[n-1];
    for (int i = n - 2; i >= 0; i--)
    {
        r[i]=__gcd(r[i+1],a[i]);
    }
    ll ans=max(r[1],l[n-2]);
    for (int i = 1; i < n-1; i++)
    {
        ll tmp = __gcd(l[i-1],r[i+1]);
        ans=max(ans,tmp);
    }
    
    cout<<ans<<endl;

    return 0;
}