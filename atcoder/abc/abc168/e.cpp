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

using modint = ModInt<(int)1e9 + 7>;

struct HashPair
{

    static size_t m_hash_pair_random;

    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {

        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        size_t seed = 0;
        seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= m_hash_pair_random + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};

size_t HashPair::m_hash_pair_random = (size_t)random_device()();

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    vector<pll> ab(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        if (a[i] == 0 && b[i] == 0)
        {
            continue;
        }
        else if (a[i] == 0)
        {
            b[i] = 1;
        }
        else if (b[i] == 0)
        {
            a[i] = 1;
        }
        else
        {
            //abs(a[i])<=abs(b[i]);
            ll gcd = __gcd(a[i], b[i]);
            a[i] /= gcd;
            b[i] /= gcd;
            if (a[i] < 0)
            {
                a[i] *= -1;
                b[i] *= -1;
            }
            ab[i] = make_pair(a[i], b[i]);
        }
    }

    unordered_map<pll, int, HashPair> mp;
    unordered_map<pll, bool, HashPair> mpUsed;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(ab[i]) == mp.end())
        {
            mp.emplace(ab[i], 1);
            mpUsed.emplace(ab[i], false);
        }
        else
        {
            mp[ab[i]] += 1;
        }
    }
    modint ans = 1;
    modint zeroans = 0;
    bool hasNonZero=false;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        pll nowab = it->first;
        //cout << nowab.first << " " << nowab.second << " " << mpUsed[nowab] << endl; //
        if (mpUsed[nowab] == true)
        {
            continue;
        }
        mpUsed[nowab] = true;

        if (nowab.first == 0 && nowab.second == 0) //(a,b)==(0,0)
        {
            zeroans = it->second;
        }
        else //(a,b)!=(0,0)
        {
            hasNonZero=true;
            modint cnt = 1;
            pll twin;
            if (nowab.second > 0)
            {
                twin = make_pair(nowab.second, -1 * nowab.first);

            }
            else
            {
                twin = make_pair(-1 * nowab.second, nowab.first);

            }
            //cout <<"twin"<<" "<< twin.first << " " << twin.second << " " << mpUsed[twin] << endl; //

            if (mp.find(twin) == mp.end()) //NG no aite ha inai
            {
                cnt = modint(2).pow((int)(it->second));
            }
            else
            {
                mpUsed[twin] = true;
                cnt = modint(2).pow((int)(it->second)) + modint(2).pow((int)(mp[twin])) - 1;
            }
            ans *= cnt;
        }
    }
    if(hasNonZero==true)
    {
        ans += zeroans;
        ans -= 1;
    }
    else
    {
        ans=zeroans;
    }

    cout << ans.x << endl;

    return 0;
}
