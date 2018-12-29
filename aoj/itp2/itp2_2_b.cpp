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
    int n,qq;
    cin>>n>>qq;
    queue<int> q[1010];
    
    for(int ii = 0; ii < qq; ii++)
    {
        int cmd,t,x;
        cin>>cmd>>t;
        if(cmd==0)
        {
            cin>>x;
            q[t].push(x);
        }
        else if (cmd==1)
        {
            if(q[t].size()>0)
            {
                cout<<q[t].front()<<endl;
            }
        }
        else
        {
            if(q[t].size()>0)
            {
                q[t].pop();
            }
        }
    }
    

    return 0;
}