#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


int main()
{
    ll n;
    int ans=1e9;
    cin>>n;

    
    for(ll i = 1; i*i <= n; i++)
    {
        if(n%i!=0) continue;
        ll x = i;
        ll y = n/x;
        int xcnt=0,ycnt=0;
        
        while(x>0){
            x/=10;
            xcnt++;
        }
        while(y>0){
            y/=10;
            ycnt++;
        }
        ans=min(ans, max(xcnt,ycnt));
    }
    
    

    cout<<ans<<endl;

    return 0;
}