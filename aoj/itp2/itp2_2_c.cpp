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
    
    vector<priority_queue<int>> pq(n);
    
    for(int q = 0; q < qq; q++)
    {
        
        int com,t,x;
        cin>>com>>t;
        
        if(com==0)//insert
        {
            int x;
            cin>>x;
            pq[t].push(x);
        }
        
        else if(com==1)//top
        {
            if(pq[t].empty()==false)
            {
                cout<<pq[t].top()<<endl;
            }

        }
        else//pop
        {
            if(pq[t].empty()==false)
            {
                pq[t].pop();
            }
        }
    }
    
    
    return 0;
}