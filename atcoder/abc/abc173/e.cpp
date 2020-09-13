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

using modint = ModInt<(int)(1e9 + 7)>;

int main()
{
    int zero=0;
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(all(a));
    ll pcnt = 0, zcnt = 0, mcnt = 0;
    vector<ll> vp, vz, vm;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            mcnt++;
            vm.push_back(a[i]);
        }
        else if (a[i] == 0)
        {
            zcnt++;
            vz.push_back(a[i]);
        }
        else
        {
            pcnt++;
            vp.push_back(a[i]);
        }
    }

    modint ans = 1;
    if (n - k < zcnt)
    {
        ans = 0;
    }
    else
    {
        ll noSelect = n - k - zcnt; //0 igai de erabanai yatsu
        //cout << noSelect << endl;//
        if (noSelect == 0)
        {
            // zenbu kaketemo plus
            if (mcnt % 2 == 0)
            {
                for (int i = 0; i < n; i++)
                {
                    if (a[i] != 0)
                    {
                        ans *= a[i];
                    }
                }
            }
            // zenbu kakeruto minus
            else
            {
                if (zcnt > 0)
                {
                    ans = 0;
                }
                else
                {
                    for (int i = 0; i < n; i++)
                    {
                        ans *= a[i];
                    }
                }
            }
        }
        else //noselect>0
        {
            if (pcnt == 0)
            {
                if (k % 2 == 0)
                {
                    for (int i = 0; i < k; i++)
                    {
                        ans *= vm[i];
                    }
                }
                else
                {
                    if (zcnt > 0)
                    {
                        ans = 0;
                    }
                    else
                    {
                        for (int i = 0; i < k; i++)
                        {
                            ans *= vm[mcnt - 1 - i];
                        }
                    }
                }
            }
            else
            {
                int mpos = 0, ppos = 0;
                if (k % 2 == 1)
                {
                    ans *= vp[ppos];
                    ppos++;
                    k--;
                }
                for (int i = 0; i < k; i += 2)
                {
                    if (ppos + 2 > pcnt)
                    {
                        ans *= vm[mpos];
                        ans *= vm[mpos + 1];
                        mpos += 2;
                    }
                    else if (mpos + 2 > mcnt)
                    {
                        ans *= vm[ppos];
                        ans *= vm[ppos + 1];
                        ppos += 2;
                    }
                    else
                    {
                        if (vm[ppos] * vm[ppos + 1] >= vm[mpos] * vm[mpos])
                        {
                            ans *= vm[ppos];
                            ans *= vm[ppos + 1];
                            ppos += 2;
                        }
                        else
                        {
                            ans *= vm[mpos];
                            ans *= vm[mpos + 1];
                            mpos += 2;
                        }
                    }
                }
            }
        }
    }

    cout << ans.x << endl;
    return 0;
}