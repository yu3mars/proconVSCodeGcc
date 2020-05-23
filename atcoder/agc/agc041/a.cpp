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
    ll n,a,b,ans;
    cin>>n>>a>>b;
    if((b-a)%2==0)
    {
        ans=(b-a)/2;
    }
    else
    {
        ll tmp1=(a+b-1)/2;
        ll tmp2=((n-a)+(n-b)+1)/2;
        ans=min(tmp1,tmp2);
    }
    

    cout<<ans<<endl;
    
    return 0;
}