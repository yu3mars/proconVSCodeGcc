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
    cin>>n;
    vector<int> c(n-1),s(n-1),f(n-1);
    
    for(int i = 0; i < n-1; i++)
    {
        cin>>c[i]>>s[i]>>f[i];
    }
    
    for(int bgnstn = 0; bgnstn < n-1; bgnstn++)
    {
        int nowstn=bgnstn;
        int tim =0;
        
        while(nowstn<n-1){
            if(tim<=s[nowstn])
            {
                tim=s[nowstn];
            }
            else if(tim%f[nowstn]!=0)
            {
                tim=(tim/f[nowstn]+1)*f[nowstn];
            }
            tim+=c[nowstn];
            nowstn++;
        }
        cout<<tim<<endl;
    }

    cout<<0<<endl;//n
    return 0;
}