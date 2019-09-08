#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using tsii = tuple<string, int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


int main()
{
    cout << std::fixed;
    cout << std::setprecision(7);
    int n;
    cin>>n;
    vector<double> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    double bunbo = 0;
    for (int i = 0; i < n; i++)
    {
        bunbo += 1.0/a[i];
    }
    cout<<1.0/bunbo<<endl;

    return 0;
}