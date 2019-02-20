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
    int n;
    cin>>n;
    vector<int> a(n);
    int mina = 1e9+7;
    int nowi=-1;
    int nexta = 1e9+8;
    int nexti=-1;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        if(a[i]<mina)
        {
            mina=a[i];
            nowi=i;
        }
    }
    bool koushin = true;
    while(koushin){
        koushin=false;
        for(int i = 0; i < n; i++)
        {
            if(i==nowi) continue;
            a[i]%=mina;
            if(a[i]>0 && a[i]<nexta)
            {
                nexta=a[i];
                nexti=i;
                koushin=true;
            }
        }
        if(koushin)
        {
            nowi = nexti;
            mina=nexta;
        }   
    }
    cout<<mina<<endl;

    return 0;
}