#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int main(){
    ll s;
    cin>>s;
    ll x,y;
    x=((ll)1e9-s%((ll)1e9))%((ll)1e9);
    y=(x+s)/1e9;
    
    cout<<"0 0 "<<(ll)1e9<<" "<<1<<" "<<x<<" "<<y<<endl;
    return 0;
}