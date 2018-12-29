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
    deque<int> deq;
    
    for(int ii = 0; ii < qq; ii++)
    {
        int cmd;
        cin>>cmd;
        if(cmd==0)
        {
            int d,x;
            cin>>d>>x;
            if(d==0)
            {
                deq.push_front(x);
            }
            else
            {
                deq.push_back(x);
            }
        }
        else if(cmd==1)
        {
            int p;
            cin>>p;
            cout<<deq[p]<<endl;
        }
        else
        {
            int d;
            cin>>d;
            if(d==0)
            {
                deq.pop_front();
            }
            else
            {
                deq.pop_back();
            }
        }
    }
    

    return 0;
}