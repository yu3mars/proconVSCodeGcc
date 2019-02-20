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
    int n,m,ans=0;
    cin>>n>>m;
    vector<int> x(m),d(m-1);
    
    for(int i = 0; i < m; i++)
    {
        cin>>x[i];
    }
    if(n>=m)
    {
        ans = 0;
    }
    else
    {
        sort(all(x));
        for(int i = 0; i < m-1; i++)
        {
            d[i]=x[i+1]-x[i];
        }
        sort(all(d));
        reverse(all(d));
        ans = x[m-1] - x[0];
        for(int i = 0; i < n-1; i++)
        {
            ans-=d[i];
        }

    }
    

    cout<<ans<<endl;

    return 0;
}