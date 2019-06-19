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
    int n;
    string s;
    cin>>n>>s;
    //..## ni suru
    vector<int> b(n+1),w(n+1);
    for (int i = 0; i < n; i++)
    {
        b[i+1]=b[i];
        w[i+1]=w[i];
        if(s[i]=='.') w[i+1]++;
        else b[i+1]++;
    }
    int ans = n;
    for (int i = 0; i <= n; i++)
    {
        int tmp = b[i]+ (w[n]-w[i]);
        ans=min(ans,tmp);
    }
    
    cout<<ans<<endl;
    return 0;
}