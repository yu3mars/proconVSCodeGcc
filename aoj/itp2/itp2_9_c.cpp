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
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int m;
    cin>>m;
    vector<int> b(m);
    for(int i = 0; i < m; i++)
    {
        cin>>b[i];
    }
    vector<int> ans;
    set_difference(all(a),all(b),back_inserter(ans));
    for(int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }
    
    return 0;
}