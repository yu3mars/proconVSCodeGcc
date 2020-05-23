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

const int mod = 998244353;

template <int mod>
struct ModInt
{
    int x;

    ModInt() : x(0) {}

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt &operator+=(const ModInt &p)
    {
        if ((x += p.x) >= mod)
            x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt &p)
    {
        if ((x += mod - p.x) >= mod)
            x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &p)
    {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    ModInt &operator/=(const ModInt &p)
    {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }

    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt &p) const { return x == p.x; }

    bool operator!=(const ModInt &p) const { return x != p.x; }

    ModInt inverse() const
    {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0)
        {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const
    {
        ModInt ret(1), mul(x);
        while (n > 0)
        {
            if (n & 1)
                ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const ModInt &p)
    {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, ModInt &a)
    {
        int64_t t;
        is >> t;
        a = ModInt<mod>(t);
        return (is);
    }

    static int get_mod() { return mod; }
};

using modint = ModInt<mod>;

template <typename T>
struct Combination
{
    vector<T> _fact, _rfact, _inv;

    Combination(int sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz + 1)
    {
        _fact[0] = _rfact[sz] = _inv[0] = 1;
        for (int i = 1; i <= sz; i++)
            _fact[i] = _fact[i - 1] * i;
        _rfact[sz] /= _fact[sz];
        for (int i = sz - 1; i >= 0; i--)
            _rfact[i] = _rfact[i + 1] * (i + 1);
        for (int i = 1; i <= sz; i++)
            _inv[i] = _rfact[i] * _fact[i - 1];
    }

    inline T fact(int k) const { return _fact[k]; }

    inline T rfact(int k) const { return _rfact[k]; }

    inline T inv(int k) const { return _inv[k]; }

    T P(int n, int r) const
    {
        if (r < 0 || n < r)
            return 0;
        return fact(n) * rfact(n - r);
    }

    T C(int p, int q) const
    {
        if (q < 0 || p < q)
            return 0;
        return fact(p) * rfact(q) * rfact(p - q);
    }

    T H(int n, int r) const
    {
        if (n < 0 || r < 0)
            return (0);
        return r == 0 ? 1 : C(n + r - 1, r);
    }
};

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    if (m == 1)
    {
        if(k==n-1) cout<<1<<endl;
        else cout<<0<<endl;
    }
    else
    {
        Combination<modint> c(n);

        modint ans = 0;
        modint pow = m;
        for (int i = 0; i < n - 1; i++)
        {
            pow *= (m - 1);
        }

        for (ll i = 0; i <= k; i++)
        {
            ans += pow * c.C(n - 1, i);
            //ans%=mod;
            //cout<<i<<" "<<pow<<" "<<c.C(n-1,i)<<endl;
            pow /= (m - 1);
        }
        cout << ans.x << endl;
    }

    return 0;
}