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
    int q;
    vector<int> v;
    cin>>q;
    
    for(int ii = 0; ii < q; ii++)
    {
        int cmd,x;
        cin>>cmd;
        if(cmd==0)
        {
            cin>>x;
            v.push_back(x);
        }
        else if(cmd==1)
        {
            cin>>x;
            cout<<v[x]<<endl;
        }
        else
        {
            v.pop_back();
        }
    }
    

    return 0;
}