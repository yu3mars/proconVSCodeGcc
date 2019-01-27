#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int main(){
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n),x(q),odd(n+10),even(n+10),imos(n+10);
    
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for(int i = 0; i < q; i++)
    {
        cin>>x[i];
    }
    
    
    for(int i = 0; i < n; i++)
    {
        odd[i+1]=odd[i];
        even[i+1]=even[i];
        imos[i+1]=imos[i]+a[i];
        if(i%2==0)odd[i+i]+=a[i];
        else even[i+1]+=a[i];
    }


    for(int i = 0; i < q; i++)
    {
        cin>>x[i];
        ll ans=0;

        ll low=0;
        ll high=n;
        while(high-low>1)
        {
            ll mid = low+high/2;
            
        }

        cout<<ans<<endl;
    }
    
    
    return 0;
}