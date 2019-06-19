#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using tsii = tuple<string, int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


int main()
{
    int n,ans=1e9+7;
    cin>>n;
    vector<int> w(n),imos(n+1);
    imos[0]=0;
    for (int i = 0; i < n; i++)
    {
        cin>>w[i];
        imos[i+1]=imos[i]+w[i];
    }
    for (int i = 1; i < n; i++)
    {
        int tmp = abs(imos[i] - (imos[n]-imos[i]));
        ans=min(ans,tmp);
    }
    
    cout<<ans<<endl;
    return 0;
}