#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using tsii = tuple<string, int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

ll mod =1e9+7;

int main()
{
    ll n,k,ans=0;
    cin>>n>>k;
    vector<ll> a(n), fi(n), al(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(a[i]>a[j]) 
            {
                al[i]++;
                if(i<j)
                {
                    fi[i]++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        ans+=fi[i]*k;
        ans%=mod;
        ll plus = ((k-1)*k/2)%mod;
        plus = (al[i]*plus)%mod;
        ans+=plus;
        ans%=mod;
    }
    cout<<ans<<endl;

    return 0;
}