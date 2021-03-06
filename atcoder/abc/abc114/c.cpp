#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

ll n;
int dfs(ll x, bool b3,bool b5, bool b7){
    if(x>n) return 0;
    int ret=0;
    if(b3&&b5&&b7) ret++;
    ret += dfs(x*10+3,true,b5,b7);
    ret += dfs(x*10+5,b3,true,b7);
    ret += dfs(x*10+7,b3,b5,true);
    return ret;
}

int main(){
    cin>>n;
    ll ans = dfs(0,false,false,false);
    cout<<ans<<endl;
    return 0;
}