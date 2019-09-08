#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


int main()
{
    int n;
    cin>>n;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        mp[a]++;
    }
    int ans=0;
    int cnt=0;
    for (auto i:mp)
    {
        if(i.second>cnt)
        {
            ans=i.first;
            cnt=i.second;
        }
    }
    cout<<ans<<" "<<cnt<<endl;
    
    return 0;
}