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
    int n,m;
    ll ans=0;
    cin>>n>>m;
    vector<ll> x(n),y(n),z(n),v(n);
    
    for(int i = 0; i < n; i++)
    {
        cin>>x[i]>>y[i]>>z[i];
    }
    
    for(int bitcnt = 0; bitcnt < (1<<3); bitcnt++)
    {
        for(int i = 0; i < n; i++)
        {
            ll val=0;
            if((bitcnt & 1)==1) val+=x[i];
            else val -=x[i];

            if(((bitcnt>>1) & 1)==1) val+=y[i];
            else val -=y[i];

            if(((bitcnt>>2) & 1)==1) val+=z[i];
            else val -=z[i];

            v[i]=val;
        }
        sort(all(v));
        reverse(all(v));
        ll tmp=0;
        
        for(int i = 0; i < m; i++)
        {
            tmp+=v[i];
        }
        ans=max(ans,tmp);
    }
    
    cout<<ans<<endl;

    return 0;
}