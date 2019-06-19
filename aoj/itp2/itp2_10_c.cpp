#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
//#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int main(){
    bitset<64> bs(0);
    int q;
    cin>>q;
    for(int i = 0; i < q; i++)
    {
        int cmd,num;
        cin>>cmd;
        if(cmd==0)//test
        {
            cin>>num;
            cout<<bs[num]<<endl;
        }
        else if(cmd==1)//set
        {
            cin>>num;
            bs.set(num);
        }
        else if(cmd==2)//clear
        {
            cin>>num;
            bs.reset(num);
        }
        else if(cmd==3)//flip
        {
            cin>>num;
            bs.flip(num);
        }
        else if(cmd==4)//all
        {
            if(bs.all())
            {
                cout<<1<<endl;
            }
            else cout<<0<<endl;
        }
        else if(cmd==5)//any
        {
            if(bs.any())
            {
                cout<<1<<endl;
            }
            else cout<<0<<endl;
        }
        else if(cmd==6)//none
        {
            if(bs.none())
            {
                cout<<1<<endl;
            }
            else cout<<0<<endl;            
        }
        else if(cmd==7)//count
        {
            cout<<bs.count()<<endl;
        }
        else if(cmd==8)//val
        {
            cout<<bs.to_ullong()<<endl;
        }

    }
    
    return 0;
}