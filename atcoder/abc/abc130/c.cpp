#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};
ll mod=1e9+7;
ll dp[100010];
bool ok[100010];

int main()
{
    double w,h,x,y;
    cin>>w>>h>>x>>y;

    std::cout << std::fixed;
    std::cout << std::setprecision(10) << w*h/2<<" ";

    if(x*2==w && y*2==h) cout<<1<<endl;
    else cout<<0<<endl;
    return 0;
}