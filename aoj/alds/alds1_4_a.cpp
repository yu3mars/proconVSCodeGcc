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
    vector<int> s(n);
    for(int i = 0; i < n; i++)
    {
        cin>>s[i];
    }
    int q;
    cin>>q;
    vector<int> t(q);
    for(int i = 0; i < q; i++)
    {
        cin>>t[i];
    }
    
    int ans =0;
    for(int ti = 0; ti < q; ti++)
    {
        for(int si = 0; si < n; si++)
        {
            if(s[si]==t[ti])
            {
                ans++;
                break;
            }
        }
        
    }
    cout<<ans<<endl;

    return 0;
}