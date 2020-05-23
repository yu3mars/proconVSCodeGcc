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
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    vector<ll> p(n),m(n);
    for (int i = 0; i < n; i++)
    {
        if(i+a[i]<n)
        {
            p[i+a[i]]++;
        }
        if(0<=i-a[i])
        {
            m[i-a[i]]++;
        }
    }
    ll ans=0;
    for (int i = 0; i < n; i++)
    {
        ans+=p[i]*m[i];
    }
    cout<<ans<<endl;
    
    return 0;
}