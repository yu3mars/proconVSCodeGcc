#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using tsii = tuple<string, int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


int main()
{
    ll n,x,ans=1;
    cin>>n>>x;
    vector<ll> l(n);
    for (int i = 0; i < n; i++)
    {
        cin>>l[i];
    }
    ll now =0;
    for (int i = 0; i < n; i++)
    {
        now+=l[i];
        if(now<=x) ans++;
    }
    
    
    cout<<ans<<endl;
    return 0;
}