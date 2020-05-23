#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define all(x) (x).begin(), (x).end()
#define m0(x) memset(x, 0, sizeof(x))

int dx4[4] = {1, 0, -1, 0}, dy4[4] = {0, 1, 0, -1};

int main()
{
    ll limit=1e6;
    vector<ll> v(10);
    for (ll i = 0; i < limit; i++)
    {
        string s = to_string(i);
        for (int j = 0; j < s.size(); j++)
        {
            v[s[j] - '0']+=limit-i;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        cout << i << " " << v[i] << endl;
    }

    return 0;
}