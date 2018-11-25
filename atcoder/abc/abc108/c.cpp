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
    ll n,k;
    cin>>n>>k;
    if(n<k)
    {
        if(k%2==0 &&k/2<=n)
        {
            cout<<1<<endl;
        }
        else cout<<0<<endl;
    }
    else
    {
        ll ans=pow(n/k,3);
        if(k%2==0)
        {
            ll p = n - k/2;
            ans+= pow((p/k+1),3);
        }
        cout<<ans<<endl;
    }
    return 0;
}