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
    string s;
    cin>>s;
    int ans=-1;
    
    for(int tmpans = 1; tmpans < (s.size())/2; tmpans++)
    {
        bool ok = true;
        
        for(int i = 0; i < tmpans; i++)
        {
            if(s[i]!= s[i+tmpans])
            {
                ok = false;
                break;
            }
        }
        if(ok) ans=tmpans;
    }
    
    cout<<ans*2<<endl;

    return 0;
}