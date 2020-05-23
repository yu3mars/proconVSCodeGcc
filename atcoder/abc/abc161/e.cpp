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




int main()
{
    ll n,k,c;
    string s;
    cin>>n>>k>>c>>s;
    vector<ll> mae, ato, ans;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='x') continue;
        mae.push_back(i);
        if(mae.size()>=k) break;
        i+=c;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if(s[i]=='x') continue;
        ato.push_back(i);
        if(ato.size()>=k) break;
        i-=c;
    }
    reverse(all(ato));
    
    
    for (int i = 0; i < k; i++)
    {
        if(mae[i]==ato[i]) ans.push_back(mae[i]);
        //cout<<mae[i]<<"\t"<<ato[i]<<endl;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]+1<<endl;
    }
    
    
    return 0;
}