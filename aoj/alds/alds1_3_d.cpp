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
    string s;
    cin>>s;
    stack<int> s1;// \ begin
    stack<pii> s2;// \, menseki
    int ans =0;
    
    for(int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if(c=='\\')
        {
            s1.push(i);
        }
        else if(c=='/')
        {
            if(s1.size()>0)
            {
                int bgn = s1.top();
                s1.pop();
                int men = i-bgn;
                ans+=men;
                while(s2.size()>0)
                {
                    pii s2top = s2.top();
                    if(s2top.first>bgn)
                    {
                        men+=s2top.second;
                        s2.pop();
                    }
                    else break;
                }
                s2.push(make_pair(bgn,men));
            }
        }
    }
    cout<<ans<<endl;
    vector<int> v;
    while(s2.size()>0)
    {
        v.push_back(s2.top().second);
        s2.pop();
    }
    reverse(all(v));
    cout<<v.size();
    
    for(int i = 0; i < v.size(); i++)
    {
        cout<<" "<<v[i];
    }
    
    cout<<endl;

    return 0;
}