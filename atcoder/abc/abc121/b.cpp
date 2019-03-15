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
    int n,m,c,ans=0;
    cin>>n>>m>>c;
    vector<int> a(m),b(m);
    for(int i = 0; i < m; i++)
    {
        cin>>b[i];
    }
    for(int ii = 0; ii < n; ii++)
    {
        int tmp=c;
        for(int i = 0; i < m; i++)
        {
            cin>>a[i];
            tmp+=a[i]*b[i];
        }
        if(tmp>0)ans++;
    }
    
    cout<<ans<<endl;
    return 0;
}