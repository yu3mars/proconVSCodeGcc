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
    int a,b;
    cin>>a>>b;
    char s[100][100];
    
    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            s[i][j]='#';
            s[i+50][j]='.';
        }
    }
    int acnt=1,bcnt=1;
    
    for(int i = 0; i < 50; i+=2)
    {
        for(int j = 0; j < 100; j+=2)
        {
            if(acnt<a)
            {
                s[i][j]='.';
                acnt++;
            }
        }        
    }
    
    for(int i = 51; i < 100; i+=2)
    {
        for(int j = 0; j < 100; j+=2)
        {
            if(bcnt<b)
            {
                s[i][j]='#';
                bcnt++;
            }
        }        
    }
    
    cout<<"100 100"<<endl;
    for(int i = 0; i < 100; i++)
    {
        
        for(int j = 0; j < 100; j++)
        {
            cout<<s[i][j];
        }
        cout<<endl;
    }
    

    return 0;
}