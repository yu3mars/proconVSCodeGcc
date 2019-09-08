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
    cin>>n;
    vector<double> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    sort(all(v));
    double ans = v[0];
    for (int i = 1; i < n; i++)
    {
        ans=(ans+v[i])/2.0;
    }
    cout<<ans<<endl;

    return 0;
}