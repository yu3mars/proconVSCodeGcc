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
        int t,d,l,ans =0;;
        cin >>t>>d>>l;
        if(t==0) break;
        int imos[200010];
        m0(imos);
        
        for(int i = 0; i < t; i++)
        {
            int x;
            cin >> x;
            if(x>=l)
            {
                imos[i]++;
                imos[i+d]--;
            }
        }
        int cnt=0;
        for(int i = 0; i < t; i++)
        {
            if(cnt>0) ans++;
            cnt+=imos[i];
        }
        
        cout<<ans<<endl;
    }
    return 0;
}