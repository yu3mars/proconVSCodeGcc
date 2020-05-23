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
    string lows,mids,highs;
    int lowi=0,midi,highi=n-1;
    cout<<0<<endl;;
    cin>>lows;
    if(lows=="Vacant")
    {
        return 0; 
    }
    cout<<n-1<<endl;;
    cin>>highs;
    if(highs=="Vacant")
    {
        return 0;
    }
    while (mids!="Vacant")
    {
        midi=(lowi+highi)/2;
        cout<<midi<<endl;;
        cin>>mids;
        if(((midi-lowi)%2==0 && mids!=lows) || ((midi-lowi)%2==1 && mids==lows))
        {
            highi=midi;
            highs=mids;
        }
        else
        {
            lowi=midi;
            lows=mids;
        }        
    }
    

    return 0;
}