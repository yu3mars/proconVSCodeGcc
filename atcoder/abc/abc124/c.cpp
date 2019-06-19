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
    string s;
    cin>>s;
    int bgn0=0,bgn1=0;
    for(int i = 0; i < s.size(); i++)
    {
        if(i%2==0) //0,2,4,...
        {
            if(s[i]=='0') bgn1++;
            else bgn0++;
        }
        else
        {
            if(s[i]=='1') bgn1++;
            else bgn0++;
        }
    }
    cout<<min(bgn0,bgn1)<<endl;

    return 0;
}