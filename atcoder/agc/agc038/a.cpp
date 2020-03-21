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
    int h,w,a,b;
    cin>>h>>w>>a>>b;
    for (int hh = 0; hh < b; hh++)
    {
        for (int ww = 0; ww < a; ww++)
        {
            cout<<0;
        }
        for (int ww = a; ww < w; ww++)
        {
            cout<<1;
        }
        cout<<endl;
    }
    for (int hh = b; hh < h; hh++)
    {
        for (int ww = 0; ww < a; ww++)
        {
            cout<<1;
        }
        for (int ww = a; ww < w; ww++)
        {
            cout<<0;
        }
        cout<<endl;
    }
    
    return 0;
}