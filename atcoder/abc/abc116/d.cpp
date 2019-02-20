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
    ll n,k,x=0,ans=0;
    cin>>n>>k;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    ll bit=1;
    while(bit>0 && bit<=k){
        ll cnt =0;
        for(ll i = 0; i < n; i++)
        {
            if((a[i] & bit)>0)
            {
                cnt++;
            }
        }
        if(cnt*2<n)
        {
            x+=bit;
        }

        bit*=2;
    }

    //cout<<x<<endl;//

    if(x>k)
    {
        ll diff = x-k;
        ll bit2=1;
        while(bit2<diff) 
        {
            bit2*=2;
        }
        while(bit2<=x)
        {
            if((x&bit2)>0)
            {
                x-=bit2;
                break;
            }
            bit2*=2;
        }
    }

    for(ll i = 0; i < n; i++)
    {
        ans+=(x^a[i]);
    }

    cout<<ans<<endl;
    return 0;
}