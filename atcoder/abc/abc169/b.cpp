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
    ll ans=1;    
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        if(a[i]==0) 
        {
            ans=0;
        }
    }
    if(ans>0)
    {
        for (int i = 0; i < n; i++)
        {
            //cout<<i<<" "<<ans<<" "<<a[i]<<endl;
            if(sqrt(ans)*sqrt(a[i])>1e9+10.0)
            {
                ans=-1;
                break;
            }
            ans*=a[i];
            if(ans>(ll)1e18)
            {
                ans=-1;
                break;
            }
        }
    }

    cout<<ans<<endl;
    
    return 0;
}