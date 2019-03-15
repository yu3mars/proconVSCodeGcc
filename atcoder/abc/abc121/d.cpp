#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

ll calc(ll a)
{
    ll ret=0;
    ll tmp=a%4;
    if(tmp==0) ret=a;
    else if(tmp==1) ret=1;
    else if(tmp==2) ret=1^a;
    else if(tmp==3) ret=0;
    
    return ret;
}

int main()
{
    ll a,b,ans;
    cin>>a>>b;
    ans=calc(a-1)^calc(b);
    cout<<ans<<endl;
    return 0;
}