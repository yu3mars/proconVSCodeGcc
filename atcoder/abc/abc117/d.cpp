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
    ll bitcnt[50];
    for(int i = 0; i < 50; i++)
    {
        bitcnt[i]=0;
    }
    

    for(ll i = 0; i < n; i++)
    {
        cin>>a[i];
        for(ll j = 0; j < 50; j++)
        {
            if(((1L<<j)&a[i])>0)  //j=0 -> 1 no keta
            {
                bitcnt[j]++;
            }
        }        
    }
    for(int i = 50 - 1; i >= 0; i--)
    {
        if((bitcnt[i]<n-bitcnt[i]) && (x|(1LL<<i))<=k)
        {
            x|=(1LL<<i);
        }
    }
    for(ll i = 0; i < n; i++)
    {
        ans+=(x^a[i]);
    }

    cout<<ans<<endl;
    return 0;
}