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
    int n;
    ll ans=0;
    cin>>n;
    vector<ll> x(n),diff(n-1);
    
    for(int i = 0; i < n; i++)
    {
        cin>>x[i];
    }
    sort(all(x));
    
    for(int i = n-1; i >= 0; i--)
    {
        x[i]-=x[0];
    }
    
    for(int i = 0; i < n-1; i++)
    {
        diff[i]=x[i+1]-x[i];
    }
    
    
    for(int i = 0; i < n-1; i++)
    {
        ans+=diff[i]*(i+1)*(n-i-1);
    }
    
    
    cout<<ans<<endl;

    return 0;
}