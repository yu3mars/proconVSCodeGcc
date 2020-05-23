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
    std::cout << std::fixed;
    std::cout << std::setprecision(12);
    double a,b,h,m;
    cin>>a>>b>>h>>m;
    double deg = abs(2*M_PI*(h/12-11*m/720));//rad
    double ans = sqrt(pow(a*sin(deg),2)+pow(b-a*cos(deg),2));
    cout<<ans<<endl;
    
    return 0;
}