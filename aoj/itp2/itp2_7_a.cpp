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
    set<int> s;

    int q;
    cin>>q;
    for(int i = 0; i < q; i++)
    {
        int cmd, x;
        cin>>cmd>>x;
        if(cmd==0)
        {
            s.insert(x);
            cout<<s.size()<<endl;
        }
        else
        {
            auto pos = s.find(x);
            if(pos!=s.end()) cout<<1<<endl;
            else cout<<0<<endl;
        }
        
    }

    return 0;
}