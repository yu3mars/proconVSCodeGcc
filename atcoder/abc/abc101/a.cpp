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
    string s;
    cin >>s;
    int ans = 0;
    
    for(int i = 0; i < 4; i++)
    {
        if(s[i]=='+') ans++;
        else ans--;
    }
    cout << ans << endl;
    
    return 0;
}