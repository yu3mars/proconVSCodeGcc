#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

std::vector<int> eratosthenes(int M) {
  std::vector<int> res(M, 0);
  res[0] = -1;
  res[1] = -1;
  for (int i = 2; i * i < M; ++i) {
    if (res[i] == 0) {
      for (int j = i * i; j < M; j += i) {
        if (res[j] == 0) res[j] = i;
      }
    }
  }
  return res;
}


int main()
{
    const int n = 100010;
    vector<int> prime_factor = eratosthenes(n);
    vector<int> similar(n);
    vector<int> cnt(n);
    cnt[0]=0;
    
    for(int i = 0; i < n; i++)
    {
        if(prime_factor[i]==0 && prime_factor[(i+1)/2]==0)
        {
            similar[i]=1;
        }
        else
        {
            similar[i]=0;
        }
    }


    

    for(int i = 1; i < 100010; i++)
    {
        cnt[i]=cnt[i-1];
        if(similar[i]==1)
        {
            cnt[i]++;
        }
    }

        
    int q;
    cin>>q;
    for(int i = 0; i < q; i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<cnt[r]-cnt[l-1]<<endl;
    }
    
    return 0;
}