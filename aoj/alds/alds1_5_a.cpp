#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int n;
vector<int> a;

bool solve(int i, int m)
{
    if(m==0) return true;
    if(i>=n) return false;
    return solve(i+1,m) | solve(i+1,m-a[i]);
}

int main(){
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        int aa;
        cin>>aa;
        a.push_back(aa);
    }
    int qq;
    cin>>qq;
    for(int i = 0; i < qq; i++)
    {
        int q;
        cin>>q;
        if(solve(0,q))
        {
            cout<<"yes"<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }
        
    }
    
    return 0;
}