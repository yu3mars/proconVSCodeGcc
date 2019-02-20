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
    ll n,ans=0;
    cin>>n;
    vector<ll> a(n),b(n),c(n);
    vector<tuple<ll,ll,ll>> v(n);
    
    for(int i = 0; i < n; i++)
    {
        cin>>a[i]>>b[i];
        c[i]=a[i]+b[i];
        v[i]=make_tuple(c[i],a[i],b[i]);
    }
    sort(all(v));
    reverse(all(v));    
    
    for(int i = 0; i < n; i++)
    {
        if(i%2==0)
        {
            ans+=get<1>(v[i]);
        }
        else
        {
            ans-=get<2>(v[i]);
        }
    }
    
    cout<<ans<<endl;
    return 0;
}