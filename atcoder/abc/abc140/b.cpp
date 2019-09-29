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
    int n,ans=0,before=-2;
    cin>>n;
    vector<int> a(n),b(n),c(n-1);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    for (int i = 0; i < n-1; i++)
    {
        cin>>c[i];
    }
    for (int i = 0; i < n; i++)
    {
        int now=a[i];
        ans+=b[now];
        if(now==before+1)
        {
            ans+=c[before];
        }
        before=now;
    }
    
    cout<<ans<<endl;
    return 0;
}