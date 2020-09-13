#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


int main()
{
    int ans=0;
    int n;
    for (int i = 0; i < 5; i++)
    {
        cin>>n;
        if(n==0)
        {
            ans=i+1;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}