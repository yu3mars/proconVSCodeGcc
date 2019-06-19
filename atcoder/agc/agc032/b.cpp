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
int pairNum(int i)
{
    int ret;
    if(n%2==0)
    {
        ret = n-i+1;
    }
    else
    {
        ret = n-i;
    }
    return ret;
}

int main(){
    cin>>n;
    vector<int> a,b;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            if(j!=pairNum(i))
            {
                a.push_back(i);
                b.push_back(j);
            }
        }
    }
    cout<< a.size()<<endl;
    for(int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" "<<b[i]<<endl;
    }
    
    
    return 0;
}