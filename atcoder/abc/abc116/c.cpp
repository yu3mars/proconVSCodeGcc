#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int h[110];



int main(){
    int n,ans=0;
    cin>>n;
    for(int i = 0; i < 110; i++)
    {
        h[i]=0;
    }
    
    for(int i = 0; i < n; i++)
    {
        cin>>h[i];
    }
    while(true){
        bool cont = false;
        bool end=true;
        for(int i = 0; i < n; i++)
        {
            if(cont)
            {
                if(h[i]==0)
                {
                    cont=false;
                }
                else
                {
                    h[i]--;
                }                
            }
            else
            {
                if(h[i]>0)
                {
                    ans++;
                    cont=true;
                    end=false;
                    h[i]--;
                }
            }            
        }
        if(end)
        {
            break;
        }
    }
    

    cout<<ans<<endl;

    return 0;
}