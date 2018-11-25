#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int main()
{
    int n, ans=0;
    string s;
    cin >>n>>s;
    
    for(int i = 0; i < n; i++)
    {
        bool x[26],y[26];
        
        for(int iii = 0; iii < 26; iii++)
        {
            x[iii]=false;
            y[iii]=false;
        }
        
        for(int xx = 0; xx < i; xx++)
        {
            x[s[xx]-'a']=true;
        }
        
        for(int yy = i; yy < n; yy++)
        {
            y[s[yy]-'a']=true;
        }
        
        int tmp =0;
        
        for(int j = 0; j < 26; j++)
        {
            if(x[j]&&y[j]) tmp++;
        }
        
        ans=max(ans,tmp);
    }
    cout << ans << endl;

    return 0;
}