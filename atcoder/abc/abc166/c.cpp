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
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
    vector<bool> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = true;
    }
    for (int i = 0; i < m; i++)
    {
        if (h[a[i]] <= h[b[i]])
        {
            v[a[i]] = false;
        }
        if (h[a[i]] >= h[b[i]])
        {
            v[b[i]] = false;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == true)
        {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}