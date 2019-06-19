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
    int n;
    cin>>n;
    vector<tuple<ll,ll,string,ll,string>> v(n);
    for(int i = 0; i < n; i++)
    {
        ll a,b,d;
        string c,e;
        cin>>a>>b>>c>>d>>e;
        v[i]=make_tuple(a,b,c,d,e);
    }
    sort(all(v));
    for(int i = 0; i < n; i++)
    {
        cout<<get<0>(v[i])<<" "<<get<1>(v[i])
            <<" "<<get<2>(v[i])<<" "<<get<3>(v[i])
            <<" "<<get<4>(v[i])<<endl;
    }
    
    return 0;
}