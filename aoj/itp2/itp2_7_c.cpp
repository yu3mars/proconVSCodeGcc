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
        else if(cmd==1)
        {
            auto pos = s.find(x);
            if(pos!=s.end()) cout<<1<<endl;
            else cout<<0<<endl;
        }
        else if(cmd==2)
        {
            s.erase(x);
        }
        else if(cmd==3)
        {
            int y;
            cin>>y;
            auto bg = s.lower_bound(x);
            auto en = s.upper_bound(y);
            for(auto i = bg; i != en; i++)
            {
                cout<<*i<<endl;
            }
            
        }
    }

    return 0;
}