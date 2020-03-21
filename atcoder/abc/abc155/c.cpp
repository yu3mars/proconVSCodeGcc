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
    int n,mx=0;
    cin>>n;
    vector<string> s(n),ans;
    unordered_map<string,int> mp;
    for (int i = 0; i < n; i++)
    {
        cin>>s[i];
        if(mp.find(s[i])==mp.end())
        {
            mp.emplace(s[i],1);
        }
        else
        {
            mp[s[i]]++;
        }
    }
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        mx=max(mx,i->second);
    }
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        if(i->second==mx)
        {
            ans.push_back(i->first);
        }
    }
    sort(all(ans));
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }
        
    return 0;
}