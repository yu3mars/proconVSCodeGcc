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
    int mcnt;
    cin>>mcnt;
//    vector<bitset<64>> m;
    bitset<64> m[10];
    for(int i = 0; i < mcnt; i++)
    {
        int k;
        cin>>k;

        for(int j = 0; j < k; j++)
        {
            int b;
            cin>>b;
            m[i].set(b);
        }
    }
    
    int q;
    cin>>q;
    for(int i = 0; i < q; i++)
    {
        int cmd,num;
        cin>>cmd>>num;
        if(cmd==0)//test
        {
            cout<<bs[num]<<endl;
        }
        else if(cmd==1)//set
        {
            bs |=m[num];
        }
        else if(cmd==2)//clear
        {
            bs &=(~m[num]);
        }
        else if(cmd==3)//flip
        {
            bs ^=m[num];
        }
        else if(cmd==4)//all
        {
            if((bs & m[num])==m[num])
            {
                cout<<1<<endl;
            }
            else cout<<0<<endl;
        }
        else if(cmd==5)//any
        {
            if((bs & m[num])!=0)
            {
                cout<<1<<endl;
            }
            else cout<<0<<endl;
        }
        else if(cmd==6)//none
        {
            if((bs & m[num])==0)
            {
                cout<<1<<endl;
            }
            else cout<<0<<endl;            
        }
        else if(cmd==7)//count
        {
            cout<<(bs & m[num]).count()<<endl;
        }
        else if(cmd==8)//val
        {
            cout<<(bs & m[num]).to_ullong()<<endl;
        }
    }
    
    return 0;
}