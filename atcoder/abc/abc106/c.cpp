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
    int k;
    char ans='1';
    cin>>s>>k;
    
    for(int i = 0; i < min((int)s.size(), k); i++)
    {
        if(s[i]!='1')
        {
            ans=s[i];
            break;
        }
    }
    

    cout<<ans<<endl;

    return 0;
}