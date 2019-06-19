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
    int a[5];
    for(int i = 0; i < 5; i++)
    {
        cin>>a[i];
    }
    int mod=10;
    for(int i = 0; i < 5; i++)
    {
        int tmp = a[i]%10;
        if(tmp>0) mod=min(mod,tmp);
    }
    int ans = 0;
    for(int i = 0; i < 5; i++)
    {
        ans+=((a[i]+9)/10)*10;
    }
    ans=ans-10+mod;
    cout<<ans<<endl;
 
    return 0;
}