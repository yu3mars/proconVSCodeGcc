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
    for(;;)
    {
        int n,l,r,ans=0;
        cin >>n>>l>>r;
        if(n==0) break;
        vector<int> a(n);
        
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        
        for(int year = l; year <= r; year++)
        {
            bool judged = false;
            for(int i = 0; i < n; i++)
            {
                if(year%a[i]==0)
                {
                    if(i%2==0)
                    {
                        ans++;
                    }
                    judged=true;
                    break;
                }
            }
            if(judged==false)
            {
                if(n%2==0) ans++;
            }
        }
        
        cout<<ans<<endl;
    }
    return 0;
}