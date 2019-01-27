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
    string s;
    string key = "keyence";
    
    cin>>s;

    int befcnt=0,aftcnt=0;
    
    for(int i = 0; i < 7; i++)
    {
        if(s[i]==key[i])
        {
            befcnt++;
        }
        else
        {
            break;
        }
    }
    
    for(int i = 0; i < 7; i++)
    {
        if(s[s.length()-i-1]==key[6-i])
        {
            aftcnt++;
        }
        else
        {
            break;
        }
    }
    
    

    if(befcnt+aftcnt>=7)
    {
        cout<<"YES"<<endl;
    }
    else 
    {
        cout<<"NO"<<endl;
    }
    return 0;
}