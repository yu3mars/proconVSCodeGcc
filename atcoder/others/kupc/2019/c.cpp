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

int main(){
    ll m,k;
    cin>>m>>k;
    ll cnt=1,ans=0,sum=0;
    while (sum<m)
    {
        sum+=k*cnt;
        cnt*=(k+2);
        
        ans++;
    }
    cout<<ans<<endl;
    
    return 0;
}