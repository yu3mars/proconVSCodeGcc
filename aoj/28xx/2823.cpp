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
        int n,m,ans =0;;
        cin >>n>>m;
        if(n==0) break;
        int ls[110];
        m0(ls);
        
        for(int i = 0; i < n; i++)
        {
            int d,v;
            cin>>d>>v;
            d--;
            ls[d]=max(ls[d],v);
        }
        
        for(int i = 0; i < m; i++)
        {
            ans+=ls[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}