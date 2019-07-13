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
    ll ans=2020;
    ll l,r;
    cin>>l>>r;
    ll a,b;
    a = l%2019;
    b = (min(l+2018,r)) % 2019;
    if(b<a) b+=2019;
    for (int i = a; i <= b; i++)
    {
        for (int j = a; j < i; j++)
        {
            ll tmp = (i*j)%2019;
            ans=min(ans,tmp);
        }
    }
    cout<<ans<<endl;

    return 0;
}