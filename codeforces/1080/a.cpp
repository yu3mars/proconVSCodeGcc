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
    ll n,k;
    cin>>n>>k;
    ll sheet[3] = {n*2,n*5,n*8};
    ll ans=0;
    
    for(int i = 0; i < 3; i++)
    {
        ans+=sheet[i]/k;
        if(sheet[i]%k>0) ans++;
    }
    cout<<ans<<endl;

    return 0;
}