#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};
ll mod = 1e9+7;

int main(){
    ll n,ans=1;
    cin>>n;
    string s;
    cin>>s;
    vector<ll> ls(26);
    for (int i = 0; i < n; i++)
    {
        ls[s[i]-'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        ans*=ls[i]+1;
        ans%=mod;
    }
    
    cout<<(ans-1+mod)%mod<<endl;
    return 0;
}