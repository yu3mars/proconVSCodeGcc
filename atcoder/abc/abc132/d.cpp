#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pic = pair<int, char>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

ll mod = 1e9+7;

vector<ll> fac(2010); //n!(mod mod)
vector<ll> ifac(2010); //k!^{mod-2} (mod mod)

ll mpow(ll x, ll n){
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % mod;
        x = x*x % mod;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a, ll b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % mod;
    return tmp * fac[a] % mod;
}

int main(){
    fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 0; i<2005; i++){
        fac[i+1] = fac[i]*(i+1) % mod; // n!(mod M)
        ifac[i+1] = ifac[i]*mpow(i+1, mod-2) % mod; // k!^{M-2} (mod M)
    }

    ll n,k;
    cin>>n>>k;
    for (ll ope = 1; ope <= k; ope++)
    {
        ll bkouho = ope;
        ll rkouho = ope-1;
        ll bamari = k-ope;
        ll aamari = (n-k) - (ope-1);
        if(bamari<0 || aamari<0)
        {
            cout<<0<<endl;
            continue;
        }
        ll bcmb = max(1LL,comb(bamari + ope-1, ope-1)%mod);
        ll acmb = max(1LL, comb(aamari+ope, ope)%mod);
        ll ans = acmb*bcmb;
        ans%=mod;
        //cout<<acmb<<" "<<bcmb<<endl;
        cout<<ans<<endl;
    }
    
    return 0;
}