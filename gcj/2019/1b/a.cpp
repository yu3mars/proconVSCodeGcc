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
        int p,q;
        cin>>p>>q;
        vector<int> x(p),y(p);
        vector<char> c(p);
        vector<int> lsN(q+1),lsS(q+1),lsE(q+1),lsW(q+1);
        for(int i = 0; i < p; i++)
        {
            cin>>x[i]>>y[i]>>c[i];
            if(c[i]=='N')
            {
                lsN[y[i]+1]++;
            }
            else if(c[i]=='S')
            {
                lsS[y[i]-1]++;
            }
            else if(c[i]=='E')
            {
                lsE[x[i]+1]++;
            }
            else if(c[i]=='W')
            {
                lsW[x[i]-1]++;
            }
        }
        for(int i = 0; i < q; i++)
        {
            lsN[i+1]+=lsN[i];
            lsE[i+1]+=lsE[i];
        }
        for(int i = q - 1; i >= 0; i--)
        {
            lsS[i]+=lsS[i+1];
            lsW[i]+=lsW[i+1];
        }
        int ansx=0, ansy=0;
        for(int i = 0; i <= q; i++)
        {
            if(lsN[i]+lsS[i]>lsN[ansy]+lsS[ansy])
            {
                ansy=i;
            }
            if(lsE[i]+lsW[i]>lsE[ansx]+lsW[ansx])
            {
                ansx=i;
            }
        }
        /*
        cout<< "lsN";
        for(int i = 0; i <= q; i++)
        {
            cout<<" "<<lsN[i];
        }
        cout<<endl;

        cout<< "lsS";
        for(int i = 0; i <= q; i++)
        {
            cout<<" "<<lsS[i];
        }
        cout<<endl;

        cout<< "lsE";
        for(int i = 0; i <= q; i++)
        {
            cout<<" "<<lsE[i];
        }
        cout<<endl;

        cout<< "lsW";
        for(int i = 0; i <= q; i++)
        {
            cout<<" "<<lsW[i];
        }
        cout<<endl;
*/
        cout<<ansx<<" "<<ansy<<endl;
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