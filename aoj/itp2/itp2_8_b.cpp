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
    map<string, int> m;

    int q;
    cin>>q;
    for(int i = 0; i < q; i++)
    {
        int cmd;
        string key;
        cin>>cmd>>key;
        if(cmd==0)
        {
            int x;
            cin>>x;
            m[key]=x;
        }
        else if(cmd==1)
        {
            cout<<m[key]<<endl;
        }
        else if(cmd==2)
        {
            m.erase(key);
        }
    }

    return 0;
}