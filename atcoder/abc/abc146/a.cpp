#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


int main()
{
    string s;
    cin>>s;
    if(s=="SUN") cout<<7<<endl;
    if(s=="MON") cout<<6<<endl;
    if(s=="TUE") cout<<5<<endl;
    if(s=="WED") cout<<4<<endl;
    if(s=="THU") cout<<3<<endl;
    if(s=="FRI") cout<<2<<endl;
    if(s=="SAT") cout<<1<<endl;
    
    return 0;
}