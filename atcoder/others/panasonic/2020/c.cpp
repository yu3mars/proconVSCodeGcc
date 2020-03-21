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
    ll a,b,c;
    cin>>a>>b>>c;
    bool ok=true;
    if(c-a-b<=0) ok=false;
    if((c-a-b)*(c-a-b)<=4*a*b) ok=false;
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
    return 0;
}