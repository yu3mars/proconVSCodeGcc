#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

ll power(ll x, ll n, ll m) //x^n mod m
{
    if(n==0) return 1;
    ll ret = power(x, n/2, m);
    if(n%2==0) 
    {
        ret = (ret*ret) % m;
    }
    else
    {
        ret = (((ret*ret)%m) *x)%m;
    }
    return ret;
}

int main(){
    ll n,ans=1,mx=0;
    ll mod = 998244353;
    cin>>n;
    vector<ll> d(n),ls(n);
    for (int i = 0; i < n; i++)
    {
        cin>>d[i];
        ls[d[i]]++;
        mx=max(mx,d[i]);
    }
    if(d[0]!=0 || ls[0]!=1)
    {
        ans=0;
    }
    else
    {
        for (ll i = 1; i <= mx; i++)
        {
            ans*=(power(ls[i-1],ls[i],mod));
            ans%=mod;
        }
    
    }
    
    cout<<ans<<endl;
    return 0;
}