#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int need[10] = {100000,2,5,5,4,5,6,3,7,6};

int main(){
    int n,m,ans=0;
    cin>>n>>m;
    vector<int> a(m), amarils(m);
    for(int i = 0; i < m; i++)
    {
        cin>>a[i];

    }
    sort(all(a));

    string dp[10010];
    for(int i = 0; i < 10010; i++)
    {
        dp[i]="~";
    }
    dp[0]="";
    for(int used = 0; used < n; used++)
    {
        if(dp[used]=="~") continue;
        for(int num = 0; num < m; num++)
        {
            string nextstr = to_string(a[num]) + dp[used];
            int nextuse = need[a[num]];
            if(dp[used+nextuse]=="~" || 
            dp[used+nextuse].length() < nextstr.length() ||
            dp[used+nextuse] < nextstr)
            {
                dp[used+nextuse] = nextstr;
            }
        }
        
    }
    

    cout<<dp[n]<<endl;
    return 0;
}