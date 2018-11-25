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
    int n,k,ans = 1e9;
    cin>>n>>k;
    vector<int> am,ap;
    
    for(int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        if(a==0) k--;
        else if(a>0) ap.push_back(a);
        else am.push_back(-a);
    }
    reverse(all(am));
    
    if(k==0)
    {
        ans=0;
    }
    else
    {
        for(int mi = 0; mi <= k; mi++)//
        {
            if(mi> am.size()) continue;
            int pi = k-mi;
            if(pi>ap.size()) continue;
            if(mi==0)
            {
                ans = min(ans,ap[pi-1]);
            }
            else if(mi==k)
            {
                ans = min(ans,am[mi-1]);
            }
            else
            {
                ans = min(ans,min(ap[pi-1]+am[mi-1]*2, ap[pi-1]*2+am[mi-1]));
            }
        }
    }
    
    cout<<ans<<endl;

    return 0;
}