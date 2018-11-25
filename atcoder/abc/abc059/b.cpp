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
    string a,b;
    cin>>a>>b;
    if(a==b)
    {
        cout<<"EQUAL"<<endl;
    }
    else if(a.size() > b.size())
    {
        cout<<"GREATER"<<endl;
    }
    else if(a.size() < b.size())
    {
        cout<<"LESS"<<endl;
    }
    else
    {
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i]>b[i])
            {
                cout<<"GREATER"<<endl;
                break;
            }
            else if(a[i]<b[i])
            {
                cout<<"LESS"<<endl;
                break;
            }
        }
    }
 
    return 0;
}