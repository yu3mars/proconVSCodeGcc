#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pic = pair<int, char>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ll en=0;
    ll su =0;
    ll ans=0;
    for (int bg = 0; bg < n; bg++)
    {
        su+=a[bg];
        if(su>=k)
        {
            ans+=n-bg;
        }
        while(su>=k)
        {
            su-=a[en];
            en++;
            if(su>=k)
            {
                ans+=n-bg;
            }
        }
    }
    

    cout<<ans<<endl;
    return 0;
}