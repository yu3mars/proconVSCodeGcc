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
    ll n,m,sum=0;
    cin>>n>>m;
    vector<ll> a(m);
    for (int i = 0; i < m; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(n>=sum) cout<<n-sum<<endl;
    else cout<<-1<<endl;
    
    return 0;
}