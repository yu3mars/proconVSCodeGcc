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
    
    list<int> ls[1010];
    
    for(int q = 0; q < qq; q++)
    {
        
        int com,s,t,x;
        cin>>com;
        
        if(com==0)//insert
        {
            cin>>t>>x;
            ls[t].push_back(x);
        }
        
        else if(com==1)//dump
        {
            cin>>t;
            for(auto i = ls[t].begin(); i != ls[t].end(); i++)
            {
                if(i!=ls[t].begin()) cout<<" ";
                cout<<*i;
            }
            cout<<endl;
        }
        else//splice
        {
            cin>>s>>t;
            ls[t].splice(ls[t].end(),ls[s]);
        }
    }
    
    
    return 0;
}