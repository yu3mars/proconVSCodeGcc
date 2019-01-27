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
    ll n,h,w,ans=0;
    cin>>n>>h>>w;
    vector<ll> a(n),b(n);
    
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        if(a[i]<=h && b[i]<=w) ans++;
    }
    
    
    cout<<ans<<endl;
    return 0;
}