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
    int n,x,y;
    cin>>n>>x>>y;
    x--;
    y--;

    vector<int> ans(n);
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < j; i++)//i<j
        {
            int d = min(j-i,abs(i-x)+abs(j-y)+1);
            ans[d]++;
        }
    }

    for (int i = 1; i < n; i++)
    {
        cout<<ans[i]<<endl;
    }
        
    return 0;
}