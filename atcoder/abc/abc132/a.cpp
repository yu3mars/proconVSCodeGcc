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
    int ls[26];
    int cnt=0;
    for (int i = 0; i < 26; i++)
    {
        ls[i]=0;
    }
    
    for (int i = 0; i < 4; i++)
    {
        ls[s[i]-'A']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if(ls[i]==2) cnt++;
    }
    
    if(cnt==2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}