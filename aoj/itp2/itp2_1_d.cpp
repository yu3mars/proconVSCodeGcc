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
    vector<int> v[1010];
    
    for(int ii = 0; ii < qq; ii++)
    {
        int cmd,t,x;
        cin>>cmd>>t;
        if(cmd==0)
        {
            cin>>x;
            v[t].push_back(x);
        }
        else if (cmd==1)
        {
            
            for(int i = 0; i < v[t].size(); i++)
            {
                cout<<v[t][i];
                if(i<v[t].size()-1)
                {
                    cout<<" ";
                }
            }
            cout<<endl;
        }
        else
        {
            if(v[t].size()>0)
            {
                v[t].clear();
            }
        }
    }
    

    return 0;
}