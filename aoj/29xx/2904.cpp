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
    int ans=0,pos=0;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i]=='R')
        {
            pos++;
            if(pos==4)
            {
                ans++;
                pos=0;
            }
        }
        else
        {
            pos--;
            if(pos==-4)
            {
                pos=0;
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}