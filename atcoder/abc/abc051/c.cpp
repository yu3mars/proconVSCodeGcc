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
    int sx,sy,tx,ty;
    cin >>sx>>sy>>tx>>ty;
    string ans="";
    int dx = tx-sx;
    int dy = ty-sy;

    for(int i = 0; i < dy; i++)
    {
        ans+='U';
    }
    for(int i = 0; i < dx; i++)
    {
        ans+='R';
    }
    for(int i = 0; i < dy; i++)
    {
        ans+='D';
    }
    for(int i = 0; i < dx; i++)
    {
        ans+='L';
    }

    //2syuume
    ans+='L';
    for(int i = 0; i < dy+1; i++)
    {
        ans+='U';
    }
    for(int i = 0; i < dx+1; i++)
    {
        ans+='R';
    }
    ans+='D';
    ans+='R';
    for(int i = 0; i < dy+1; i++)
    {
        ans+='D';
    }
    for(int i = 0; i < dx+1; i++)
    {
        ans+='L';
    }
    ans+='U';

    cout <<ans<<endl;
 
    return 0;
}