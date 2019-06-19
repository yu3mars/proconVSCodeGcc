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
    char c;
    cin>>c;
    if(c=='A') cout<<'T'<<endl;
    if(c=='T') cout<<'A'<<endl;
    if(c=='C') cout<<'G'<<endl;
    if(c=='G') cout<<'C'<<endl;
 
    return 0;
}