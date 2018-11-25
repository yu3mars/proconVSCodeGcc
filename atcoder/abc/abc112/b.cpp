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
    int n,t;
    cin>>n>>t;
    int ans=10000;
    
    for(int i = 0; i < n; i++)
    {
        int c,tt;
        cin>>c>>tt;
        if(tt<=t)
        {
            ans=min(ans,c);
        }
    }
    if(ans==10000) cout<<"TLE"<<endl;
    else cout<<ans<<endl;
 
    return 0;
}