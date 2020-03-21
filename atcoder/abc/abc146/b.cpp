#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


int main()
{
    int n;
    string s;
    cin>>n>>s;
    for(int i=0;i<s.size();i++)
    {
        char c=s[i];
        int cnt=(s[i]-'A'+n)%26;
        s[i]='A'+cnt;
    }
    cout<<s<<endl;
    
    return 0;
}