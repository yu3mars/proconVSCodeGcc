#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int main(){
    int ans=100000;
    string s;
    cin>>s;
    
    for(int i = 0; i < s.size()-2; i++)
    {
        string ss = s.substr(i,3);
        int n = stoi(ss);
        ans=min(ans,abs(n-753));
    }
    

    cout<<ans<<endl;
    return 0;
}