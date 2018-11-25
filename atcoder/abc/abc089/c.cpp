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
    int n;
    ll ans=0,ls[5];
    cin >>n;
    m0(ls);
    string m = "MARCH";
    
    for(int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        char c = s[0];
        
        for(int j = 0; j < 5; j++)
        {
            if(c==m[j])
            {
                ls[j]++;
            }
        }
    }
    
    for(int i = 0; i < 5; i++)
    {
        
        for(int j = 0; j < i; j++)
        {
            
            for(int k = 0; k < j; k++)
            {
                ans+=ls[i]*ls[j]*ls[k];
            }
            
        }
        
    }
    

    cout <<ans<<endl;
 
    return 0;
}