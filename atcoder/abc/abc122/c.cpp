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
    int n,qq;
    cin>>n>>qq;
    string s;
    cin>>s;
    vector<int> ls(n+1);
    ls[0]=0;
    for(int i = 0; i < n-1; i++)
    {
        if(s[i]=='A'&&s[i+1]=='C')
        {
            ls[i+1]=1;
        }
        else ls[i+1]=0;
        if(i>0)
        {
            ls[i+1]+=ls[i];
        }
    }
    for(int q = 0; q < qq; q++)
    {
        int l,r;
        cin>>l>>r;
        l--;r--;
        cout<<ls[r]-ls[l]<<endl;
    }
    
    
    return 0;
}