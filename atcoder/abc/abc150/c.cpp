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

vector< bool > prime_table(int n) {
    vector< bool > prime(n + 1, true);
    if(n >= 0) prime[0] = false;
    if(n >= 1) prime[1] = false;
    for(int i = 2; i * i <= n; i++) {
        if(!prime[i]) continue;
        for(int j = i + i; j <= n; j += i) {
        prime[j] = false;
        }
    }
    return prime;
}

int main()
{
    int x;
    cin>>x;
    auto pt=prime_table(100050);
    for (int i = x; i < 100050; i++)
    {
        if(pt[i]==true)
        {
            cout<<i;
            break;
        }
    }
    
    
    return 0;
}