#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

//75 = 1*75,3*25,5*15,3*5*5

int cnt[110];
int calc(int num)
{
    int ret=0;
    for(int i = 0; i < 100; i++)
    {
        if(cnt[i]+1>=num) ret++;
    }
    return ret;
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < 110; i++)
    {
        cnt[i]=0;
    }
    
    for(int now = 2; now <= n; now++)
    {
        int tmp=now;
        for(int div = 2; div <= n; div++)
        {
            while(tmp%div==0){
                cnt[div]++;
                tmp/=div;
            }
        }
    }
    int ans = calc(75) +
        (calc(3)-1)*calc(25) + calc(15)*(calc(5)-1) +
        calc(5)*(calc(5)-1)*(calc(3)-2)/2;
    cout<<ans<<endl;

    return 0;
}