#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define all(x) (x).begin(), (x).end()
#define m0(x) memset(x, 0, sizeof(x))

int dx4[4] = {1, 0, -1, 0}, dy4[4] = {0, 1, 0, -1};

template< typename T >
vector< vector< T > > binomial_table(int N) {
  vector< vector< T > > mat(N + 1, vector< T >(N + 1));
  for(int i = 0; i <= N; i++) {
    for(int j = 0; j <= i; j++) {
      if(j == 0 || j == i) mat[i][j] = 1;
      else mat[i][j] = mat[i - 1][j - 1] + mat[i - 1][j];
    }
  }
  return mat;
}

class GoogleCodeJam
{
public:
    string case_prefix;
    void exec()
    {
        std::cout << std::fixed;
        std::cout << std::setprecision(10);
        
        ll w,h,l,u,r,d;
        cin>>w>>h>>l>>u>>r>>d;
        double ans=0;
        if(w>300||h>300) return;//

        auto bt = binomial_table<ll>(700);
        vector<double> n2(701);
        n2[0]=1;
        for (int i = 0; i < 300; i++)
        {
            n2[i+1]=n2[i]/2.0;
        }
        for (ll i = 0; i < min(w,u)-1; i++)
        {
            double base = n2[u+r-2];
            ans+=base*bt[u+r-2][i];
        }
        
        for (ll i = 0; i < min(h,l)-1; i++)
        {
            double base = n2[l+d-2];
            ans+=base*bt[l+d-2][i];
        }
        
        cout<<ans<<endl;
    }
    GoogleCodeJam()
    {
        int T;
        std::cin >> T;
        for (int i = 1; i <= T; i++)
        {
            case_prefix = "Case #" + std::to_string(i) + ": ";
            cout << case_prefix;
            exec();
        }
    }
};

int main()
{
    GoogleCodeJam();

    return 0;
}