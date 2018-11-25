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
    int n,ans=0;
    double t,a;
    cin >> n>>t>>a;
    double diff = 1e9;
    
    
    for(int i = 0; i < n; i++)
    {
        double h;
        cin >> h;
        double temp = t - h * 0.006;
        if(abs(a - temp) < diff)
        {
            ans = i+1;
            diff = abs(a-temp);
        }
    }
    

    cout << ans<<endl;

    return 0;
}