#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define all(x) (x).begin(), (x).end()
#define m0(x) memset(x, 0, sizeof(x))

int dx4[4] = {1, 0, -1, 0}, dy4[4] = {0, 1, 0, -1};

map<int64_t, int> prime_factor(int64_t n)
{
    map<int64_t, int> ret;
    for (int64_t i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            ret[i]++;
            n /= i;
        }
    }
    if (n != 1)
        ret[n] = 1;
    return ret;
}

int main()
{
    ll n, p, ans = 1;
    cin >> n >> p;

    for (auto pf : prime_factor(p))
    {
        ll f=pf.first;
        ll s=pf.second;
        ll cnt=s/n;
        ans*=pow(f,cnt);
    }
    cout << ans << endl;
    return 0;
}