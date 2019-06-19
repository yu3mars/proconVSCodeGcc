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
    int qq;
    cin>>qq;
    list<int> ls;
    auto it=ls.begin();
    
    for(int ii = 0; ii < qq; ii++)
    {
        int cmd;
        cin>>cmd;
        if(cmd==0)//insert
        {
            int x;
            cin>>x;
            it=ls.insert(it,x);
        }
        else if(cmd==1)//move
        {
            int d;
            cin>>d;
            if(d>=0)
            {
                for(int i = 0; i < d; i++)
                {
                    it++;
                }                
            }
            else
            {
                for(int i = 0; i < abs(d); i++)
                {
                    it--;
                }
                
            }
            
        }
        else//erase
        {
            it=ls.erase(it);
        }
    }
    for(auto it2 = ls.begin(); it2 != ls.end(); it2++)
    {
        cout<<(*it2)<<endl;
    }
    
    return 0;
}