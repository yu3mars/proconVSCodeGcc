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
    int n,d;
    cin>>d>>n;
    int ans = n;
    if(n==100) ans=101;
    
    for(int i = 0; i < d; i++)
    {
        ans*=100;
    }

    cout<<ans<<endl;

    return 0;
}