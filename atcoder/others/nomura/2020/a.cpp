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
    int h1,m1,h2,m2,k;
    cin>>h1>>m1>>h2>>m2>>k;
    int ans=(h2-h1)*60+(m2-m1);
    if(ans<0)
    {
        ans+=24*60;
    }
    ans-=k;
    cout<<ans<<endl;
    
    return 0;
}