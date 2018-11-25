#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int main()
{
    int n,x,ans;
    cin>>n>>x;
    ans=n;
    vector<int> m(n);
    
    for(int i = 0; i < n; i++)
    {
        cin>>m[i];
        x-=m[i];
    }
    sort(all(m));
    ans += x/m[0];

    cout <<ans<<endl;

    return 0;
}