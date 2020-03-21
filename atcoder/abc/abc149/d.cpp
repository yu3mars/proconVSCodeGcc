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
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin>>a[i];
        a[i]/=2;
    }
    ll gcd=a[0];
    for (ll i = 0; i < n; i++)
    {
        gcd=__gcd(gcd,a[i]);
    }
    bool odd=true;
    for (ll i = 0; i < n; i++)
    {
        if((a[i]/gcd)%2==0)
        {
            odd=false;
        }
    }
    if(odd)
    {
        ll lcm=1;
        for (ll i = 0; i < n; i++)
        {
            lcm=lcm*(a[i]/__gcd(lcm, a[i]));
        }
        cout<<(m/lcm)/2+(m/lcm)%2<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
        
    return 0;
}