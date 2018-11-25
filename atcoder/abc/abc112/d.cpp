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
    int n,m,ans=1;
    cin>>n>>m;
    
    for(int i = 1; i*i <= m; i++)
    {
        if(m%i==0)
        {
            int j = m/i;
            if(j>=n)
            {
                ans=max(ans,i);
            }
            if(i>=n)
            {
                ans=max(ans,j);
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}