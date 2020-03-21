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
    std::cout << std::setprecision(8);
    double a,b,x;
    cin>>a>>b>>x;
    if(a*a*b<=x*2)
    {
        double v = a*a*b-x;
        double tan = v*2/a/a/a;
        double theta = atan(tan);
        cout<<theta*180/M_PI<<endl;
    }
    else
    {
        double tan=a*b*b/2/x;
        double theta = atan(tan);
        cout<<theta*180/M_PI<<endl;
    }
        
    return 0;
}