#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

bool is4(int n)
{
    int ls[4] = {4,6,9,11};
    
    for(int i = 0; i < 4; i++)
    {
        if(n==ls[i]) return true;
    }
    return false;
}

int main()
{
    int x,y;
    cin >> x >> y;
    if(x==2||y==2)
    {
        cout << "No"<<endl;
    }
    else if(is4(x) == is4(y))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No"<<endl;
    }
 
    return 0;
}