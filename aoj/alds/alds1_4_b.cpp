#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

bool binarySearch(vector<int> v, int key)
{
    int lb=0;
    int ub=v.size();
    while(lb<ub){
        int mid = (lb+ub)/2;
        if(v[mid]==key) return true;
        else
        {
            if(key<v[mid])
            {
                ub=mid;
            }
            else
            {
                lb=mid+1;
            }
            
        }
        
    }
    
    return false;
}

int main(){
    int n,q,ans=0;
    cin>>n;
    vector<int> s(n);
    for(int i = 0; i < n; i++)
    {
        cin>>s[i];
    }
    cin>>q;
    vector<int> t(q);
    for(int i = 0; i < q; i++)
    {
        cin>>t[i];
        if(binarySearch(s,t[i])) ans++;
    }
    
    cout<<ans<<endl;
    
    return 0;
}