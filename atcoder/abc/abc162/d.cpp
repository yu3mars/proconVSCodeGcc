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
    ll n, ans = 0;
    string s;
    cin >> n >> s;
    unordered_set<ll> mp[3]; //r,g,b
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R')
            mp[0].insert(i);
        if (s[i] == 'G')
            mp[1].insert(i);
        if (s[i] == 'B')
            mp[2].insert(i);
    }

    if (mp[0].size() > mp[2].size())
        swap(mp[0], mp[2]);
    if (mp[1].size() > mp[2].size())
        swap(mp[1], mp[2]);

    for (auto it0 = mp[0].begin(); it0 != mp[0].end(); it0++)
    {
        for (auto it1 = mp[1].begin(); it1 != mp[1].end(); it1++)
        {
            ll n0 = *it0;
            ll n1 = *it1;

            if (n0 > n1)
                swap(n0, n1); //n0<n1

            ans += mp[2].size();
            ll n2;
            n2 = 2 * n0 - n1;
            if (n2 >= 0 && mp[2].find(n2) != mp[2].end()) //n2,n0,n1
            {
                ans--;
            }
            n2 = 2 * n1 - n0;
            if (n2 < n && mp[2].find(n2) != mp[2].end()) //n0,n1,n2
            {
                ans--;
            }
            if ((n1 - n0) % 2 == 0)
            {
                n2 = (n1 + n0) / 2;
                if (mp[2].find(n2) != mp[2].end()) //n0,n1,n2
                {
                    ans--;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}