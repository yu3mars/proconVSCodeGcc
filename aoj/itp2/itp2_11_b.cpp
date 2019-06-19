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
    int n;
    cin>>n;
    int k;
    cin>>k;
    int mask=0;
    for(int i = 0; i < k; i++)
    {
        int b;
        cin>>b;
        mask+=(1<<b);
    }
    
    for(int i = 0; i < (1<<n); i++)
    {
        if((i&mask)==mask)
        {
            cout<<i<<":";
            for(int j = 0; j < n; j++)
            {
                if((i>>j)&1!=0)
                {
                    cout<<" "<<j;;
                }
            }
            
            cout<<endl;
        }
    }
    

    return 0;
}