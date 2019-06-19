#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

ll mod=1e9+7;
ll dp1[100010],dp2[100010];


int main()
{
    string l;
    cin>>l;
    m0(dp1);//kakutei
    m0(dp2);//mikakutei
    dp2[0]=1;
    for (int i = 0; i < l.size(); i++)
    {
        if(l[i]=='0')
        {
            dp1[i+1]=dp1[i]*3;
            dp2[i+1]=dp2[i];

        }
        else //1
        {
            dp1[i+1]=dp1[i]*3+dp2[i];
            dp2[i+1]=dp2[i]*2;
        }
        dp1[i+1]%=mod;
        dp2[i+1]%=mod;
    }
    cout<<(dp1[l.size()]+dp2[l.size()])%mod<<endl;

    return 0;
}