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
    ll n,ans=0;
    cin>>n;
    vector<ll> a(n),b(n-1);
    for (int i = 0; i < n-1; i++)
    {
        cin>>b[i];
    }
    a[0]=b[0];
    a[n-1]=b[n-2];
    for (int i = 1; i < n-1; i++)
    {
        a[i]=min(b[i-1],b[i]);
    }
    for (int i = 0; i < n; i++)
    {
        ans+=a[i];
    }
    
    
    cout<<ans<<endl;

    return 0;
}