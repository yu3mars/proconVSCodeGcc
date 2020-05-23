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
    int n=s.size();
    vector<int> c(3);
    for (int i = 0; i < n; i++)
    {
        c[s[i]-'a']++;
    }
    sort(all(c));
    if(c[2]-c[0]>1) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    
    return 0;
}