#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define all(x) (x).begin(), (x).end()
#define m0(x) memset(x, 0, sizeof(x))

int dx4[4] = {1, 0, -1, 0}, dy4[4] = {0, 1, 0, -1};

class GoogleCodeJam
{
  public:
    string case_prefix;
    void exec()
    {
        int w;
        cin>>w;
        cin.clear();
        fflush(stdin);
        vector<ll> ans(6), res(w);
        for(int ww = 0; ww < w; ww++)
        {
            //cout<<ww;
            printf("%d\n", ww);
            fflush(stdout);
            //cin>>res[ww];
            scanf("%ld", &res[ww]);
            //cin.clear();
            fflush(stdin);
        }
        ans[0]=res[1]-res[0];
        ans[1]=res[2]-res[1]-ans[0]*2;
        ans[2]=res[3]-res[2]-ans[0]*4;
        ans[3]=res[4]-res[3]-ans[0]*8-ans[1]*2;
        ans[4]=res[5]-res[4]-ans[0]*16;
        ans[5]=res[0]-ans[0]-ans[1]-ans[2]-ans[3]-ans[4];


        for(int i = 0; i < 6; i++)
        {
            if(i>0)
            {
                //cout<<" ";
                printf(" ");
            } 
            //cout<<ans[i];
            printf("%ld", ans[i]);
        }
//        cout<<endl;
        printf("\n");
        fflush(stdout);
        
    }
    GoogleCodeJam()
    {
        int T;
//        std::cin >> T;
        scanf("%d", &T);
        cin.clear();
        fflush(stdin);
        for (int i = 1; i <= T; i++)
        {
            case_prefix = "Case #" + std::to_string(i) + ": ";
            //cout << case_prefix;
            printf("%s",case_prefix);
            fflush(stdout);
            exec();
        }
    }
};

int main()
{
    GoogleCodeJam();

    return 0;
}