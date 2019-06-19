#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int main(){
    int r,g,b,n;
    cin>>r>>g>>b>>n;
    int ans=0;
    for(int rr = 0; rr <= n; rr+=r)
    {
        for(int gg = 0; gg + rr <= n; gg+=g)
        {
            int bb=n-rr-gg;
            if(bb%b!=0) continue;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}