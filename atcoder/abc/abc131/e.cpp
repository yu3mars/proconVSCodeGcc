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
    int n,k;
    cin>>n>>k;
    if(k>(n-1)*(n-2)/2)
    {
        cout<<-1<<endl;
    }
    else
    {
        int m = n*(n-1)/2-k;
        cout<<m<<endl;
        vector<pii> v;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j < i; j++)
            {
                v.push_back(make_pair(j,i));                
            }
        }
        sort(all(v));
        for(int i = 0; i < m; i++)
        {
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }
        
    }
    
    return 0;
}