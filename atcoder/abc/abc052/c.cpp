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
    int n;
    ll ans = 1;
    ll cnt[1010];
    cin>>n;
    m0(cnt);
    cnt[1]=1;
    
    for(int i = 2; i <= n; i++)
    {
        int tmp=i;
        int div = 2;
        while(tmp>1){
            if(tmp%div==0)
            {
                tmp/=div;
                cnt[div]++;
            }
            else
            {
                div++;
            }
        }
    }
    
    for(int i = 2; i <= n; i++)
    {
        ans*=(cnt[i]+1);
        ans%=(ll)(1e9+7);
    }
    

    cout<<ans<<endl;

    return 0;
}