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
    std::cout << std::fixed;
    std::cout << std::setprecision(10);
    int n,k;
    cin>>n>>k;
    double ans =0;
    for (int ni = 1; ni <= n; ni++)
    {
        int n2=1;
        while(ni*n2 < k)
        {
            n2*=2;
        }
        ans += 1/(double)(n * n2); 
    }
    cout<<ans<<endl;
    
    return 0;
}