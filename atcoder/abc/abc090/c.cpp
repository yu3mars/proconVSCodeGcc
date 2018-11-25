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
    ll n,m,ans=0;
    cin>>n>>m;
    if(n>m) swap(n,m);
    if(n==1)
    {
        if(m==1) ans=1;
        else ans=m-2;
    }
    else if(n==2)
    {
        ans=0;
    }
    else
    {
        ans=(n-2)*(m-2);
    }

    cout<<ans<<endl;

    return 0;
}