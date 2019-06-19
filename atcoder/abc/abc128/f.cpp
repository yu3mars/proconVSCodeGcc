#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


int main()
{
    int m,k;
    cin>>m>>k;
    int p = pow(2,m);
    if(k>=p)
    {
        cout<<-1<<endl;
    }
    else if(m == 0)
    {
        cout<<"0 0"<<endl;
    }
    else if (m==1)
    {
        if(k==0) cout<<"0 0 1 1"<<endl;
        else cout<<-1<<endl;
    }
    else
    {    
        cout<<k;
        for (int i = 0; i < p; i++)
        {
            if(i==k) continue;
            cout<<" "<<i;
        }
        cout<<" "<<k;
        for (int i = p - 1; i >= 0; i--)
        {
            if(i==k) continue;
            cout<<" "<<i;
        }
        cout<<endl;
    }    

    return 0;
}