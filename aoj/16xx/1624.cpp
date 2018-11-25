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
    for(;;)
    {
        int n,ans=0;
        cin >>n;
        if(n==0) break;
        vector<double> a(n);
        double ave = 0;
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
            ave+=a[i];
        }
        ave/=n;
        
        for(int i = 0; i < n; i++)
        {
            if(a[i]<=ave) ans++;
        }
        cout<<ans<<endl;

    }
    return 0;
}