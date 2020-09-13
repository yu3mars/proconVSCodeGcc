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


int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(n+1),b(m+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    for (int i = 1; i <= m; i++)
    {
        cin>>b[i];
        b[i]+=b[i-1];
    }
    ll ans=0;
    ll ai=0,bi=0;
    for (int i = 0; i <= n; i++)
    {
        if(a[i]<=k)
        {
            ai=i;
        }
        else break;
    }
    ans=max(ans,ai);
    for (int i = 0; i <= m; i++)
    {
        if(b[i]>k) break;
        while (ai>0 && a[ai]+b[i]>k)
        {
            ai--;
        }
        ans=max(ans,ai+i);
    }
    

    cout<<ans<<endl;
    return 0;
}