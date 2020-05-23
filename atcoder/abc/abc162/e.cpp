#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


template <int M, bool IsPrime = false> class Modulo {
  int n;
  static typename std::enable_if<IsPrime, ll>::type inv(ll a, ll p) {
    return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
  }

public:
  Modulo() : n(0) { ; }
  Modulo(int m) : n(m) {
    if (n >= M)
      n %= M;
    else if (n < 0)
      n = (n % M + M) % M;
  }
  Modulo(ll m) {
    if (m >= M)
      m %= M;
    else if (m < 0)
      m = (m % M + M) % M;
    n = m;
  }
  explicit operator int() const { return n; }
  explicit operator ll() const { return n; }
  bool operator==(const Modulo &a) const { return n == a.n; }
  Modulo &operator+=(const Modulo &a) {
    n += a.n;
    if (n >= M) n -= M;
    return *this;
  }
  Modulo &operator-=(const Modulo &a) {
    n -= a.n;
    if (n < 0) n += M;
    return *this;
  }
  Modulo &operator*=(const Modulo &a) {
    n = (ll(n) * a.n) % M;
    return *this;
  }
  Modulo operator+(const Modulo &a) const {
    Modulo res = *this;
    return res += a;
  }
  Modulo operator-(const Modulo &a) const {
    Modulo res = *this;
    return res -= a;
  }
  Modulo operator-() const { return Modulo(0) - *this; }
  Modulo operator*(const Modulo &a) const {
    Modulo res = *this;
    return res *= a;
  }

  Modulo operator^(ll m) const {
    if (m == 0) return Modulo(1);
    const Modulo a = *this;
    Modulo res = (a * a) ^ (m / 2);
    return m % 2 ? res * a : res;
  }
  typename std::enable_if<IsPrime, Modulo>::type
  operator/(const Modulo &a) const {
    return *this * inv(ll(a), M);
  }
  typename std::enable_if<IsPrime, Modulo>::type operator/=(const Modulo &a) {
    return *this *= inv(ll(a), M);
  }

  friend bool is_zero(const Modulo &x) { return int(x) == 0; }
  friend int abs(const Modulo &x) { return int(x); }

  static Modulo fact(int n, bool sw = true) {
    static std::vector<Modulo> v1 = { 1 }, v2 = { 1 };
    if (n >= (int)v1.size()) {
      const int from = v1.size(), to = n + 1024;
      v1.reserve(to);
      v2.reserve(to);
      for (int i = from; i < to; ++i) {
        v1.push_back(v1.back() * Modulo<M, true>(i));
        v2.push_back(v2.back() / Modulo<M, true>(i));
      }
    }
    return sw ? v1[n] : v2[n];
  }
  static Modulo comb(int a, int b) {
    if (b < 0 || b > a) return 0;
    return Modulo::fact(a, true) * Modulo::fact(b, false) *
           Modulo::fact(a - b, false);
  }
};

using Mod = Modulo<(int)1e9+7,true>;


ll myPow(ll x, ll n, ll m){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return myPow(x * x % m, n / 2, m);
  else
    return x * myPow(x, n - 1, m) % m;
}

int main()
{
    ll n,k;
    cin>>n>>k;
    Mod dp[100010];
    Mod ans=0;

    for (ll i = k; i > 0; i--)
    {
        ll cnt= (k/i);
        dp[i]=myPow(cnt,n,1e9+7);
        for (int j = i*2; j <= k; j+=i)
        {
            dp[i]-=dp[j];
        }
    }
    
    for (ll i = 0; i <= k; i++)
    {
        ans+=dp[i]*i;
        //cout<<i<<"\t"<<(int)dp[i]<<endl;
    }
    
    cout<<(int)ans<<endl;
    
    return 0;
}