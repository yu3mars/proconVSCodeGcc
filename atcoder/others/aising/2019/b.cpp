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
    ll n,a,b,ans=0;
    cin>>n>>a>>b;
    vector<ll> p(n);
    ll low=0,mid=0,high=0;
    for(int i = 0; i < n; i++)
    {
        cin>>p[i];
        if(p[i]<=a) low++;
        else if(b<p[i]) high++;
        else mid++;
    }
    ans = min(low,min(mid,high));

    cout<<ans<<endl;
    return 0;
}