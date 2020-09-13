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
    int x,n;
    cin>>x>>n;
    unordered_set<int> p(n);
    for (int i = 0; i < n; i++)
    {
        int pp;
        cin>>pp;
        p.emplace(pp);
    }
    int ans;
    for (int i = 0; i < 110; i++)
    {
        int tmp;
        tmp=x-i;
        if(p.find(tmp)==p.end())
        {
            ans=tmp;
            break;
        }
        tmp=x+i;
        if(p.find(tmp)==p.end())
        {
            ans=tmp;
            break;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}