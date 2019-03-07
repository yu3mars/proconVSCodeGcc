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
    int ans=0;
    string s;
    cin>>s;
    stack<char> st;
    for(int i = 0; i < s.size(); i++)
    {
        if(st.size()==0 || st.top()==s[i])
        {
            st.push(s[i]);
        }
        else
        {
            ans+=2;
            st.pop();
        }
        
    }
    

    cout<<ans<<endl;

    return 0;
}