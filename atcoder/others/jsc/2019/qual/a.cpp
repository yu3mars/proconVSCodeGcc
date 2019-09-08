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
    int mm,dd;
    cin>>mm>>dd;
    int ans=0;
    for (int m = 1; m <= mm; m++)
    {
        for (int d = 1; d <= dd; d++)
        {
            int d1 = d%10;
            int d10 = d/10;
            if(d1>=2 && d10>=2 && d1*d10==m)
            {
                ans++;
            }
        }
        
    }
    
    cout<<ans<<endl;

    return 0;
}