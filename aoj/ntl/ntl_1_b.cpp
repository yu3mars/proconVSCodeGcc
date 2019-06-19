#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

const ll MOD = 1e9+7;

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

int main()
{
    ll n,m;
    cin>>n>>m;

    cout<<power(n,m,MOD)<<endl;
 
    return 0;
}