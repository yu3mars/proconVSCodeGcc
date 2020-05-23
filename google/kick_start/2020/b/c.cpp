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
        ll mx = 1e9;
        string s;
        cin >> s;
        s = "1(" + s + ")";
        ll num = s.size();
        ll nans = 0, eans = 0;
        stack<ll> nq, eq,xq;
        nq.push(0);
        eq.push(0);
        xq.push(1);
        for (ll i = 0; i < num; i++)
        {
            char c = s[i];
            if ('1' <= c && c <= '9')
            {
                ll xx = c - '0';
                xq.push(xx);
            }
            else if (c == '(')
            {
                nq.push(0);
                eq.push(0);
            }
            else if (c == ')')
            {
                ll xx=xq.top();
                xq.pop();

                ll nn = nq.top();
                nq.pop();
                nn = nn * xx;
                nn%=mx;
                ll nn2=nq.top();
                nq.pop();
                nq.push(nn+nn2);

                ll ee = eq.top();
                eq.pop();
                ee = ee * xx;
                ee%=mx;
                ll ee2=eq.top();
                eq.pop();
                eq.push(ee+ee2);
                //cout<<i<<" "<<ee<<" "<<nn<<endl;//
            }
            else //NSEW
            {
                if (c == 'N')
                {
                    ll nn = nq.top();
                    nq.pop();
                    nn--;
                    nq.push(nn);
                }
                else if (c == 'S')
                {
                    ll nn = nq.top();
                    nq.pop();
                    nn++;
                    nq.push(nn);
                }
                else if (c == 'E')
                {
                    ll ee = eq.top();
                    eq.pop();
                    ee++;
                    eq.push(ee);
                }
                else if (c == 'W')
                {
                    ll ee = eq.top();
                    eq.pop();
                    ee--;
                    eq.push(ee);
                }
            }
        }

        nans+=nq.top();
        nans=(nans%mx+mx)%mx;
        nans++;
        
        eans+=eq.top();
        eans=(eans%mx+mx)%mx;
        eans++;
        
        //cout<<eq.size()<<" "<<nq.size()<<endl;//
        cout<<eans<<" "<<nans<<endl;
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