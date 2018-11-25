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
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(n),c(m),d(m);
    
    for(int i = 0; i < n; i++)
    {
        cin>>a[i]>>b[i];
    }
    
    for(int i = 0; i < m; i++)
    {
        cin>>c[i]>>d[i];
    }
    
    
    for(int i = 0; i < n; i++)
    {
        int ans = 100;
        int dist = 1e9;

        for(int j = 0; j < m; j++)
        {
            int tmp = abs(a[i]-c[j]) + abs(b[i]-d[j]);
            if(dist>tmp)
            {
                dist=tmp;
                ans=j;
            }
        }
        cout<<ans+1<<endl;
    }
    


    return 0;
}