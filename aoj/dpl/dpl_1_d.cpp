#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pic = pair<int, char>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    vector<int> lis;
    lis.push_back(a[0]);
    int length = 1;
    for(int i = 1; i < n; i++)
    {
        if(lis[length-1]<a[i])
        {
            lis.push_back(a[i]);
            length++;
        }
        else
        {
            *lower_bound(all(lis),a[i]) = a[i];
        }
    }
    cout<<length<<endl;
    
    return 0;
}