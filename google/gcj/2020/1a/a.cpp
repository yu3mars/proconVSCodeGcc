#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define all(x) (x).begin(), (x).end()
#define m0(x) memset(x, 0, sizeof(x))

int dx4[4] = {1, 0, -1, 0}, dy4[4] = {0, 1, 0, -1};


vector<string> split_naive(const string &s, char delim) {
    vector<string> elems;
    string item;
    for (char ch: s) {
        if (ch == delim) {
            if (!item.empty())
                elems.push_back(item);
            item.clear();
        }
        else {
            item += ch;
        }
    }
    if (!item.empty())
        elems.push_back(item);
    return elems;
}
bool starts_with(const std::string& s, const std::string& prefix) {
   auto size = prefix.size();
   if (s.size() < size) return false;
   return std::equal(std::begin(prefix), std::end(prefix), std::begin(s));
}
bool ends_with(const std::string& s, const std::string& suffix) {
   if (s.size() < suffix.size()) return false;
   return std::equal(std::rbegin(suffix), std::rend(suffix), std::rbegin(s));
}

class GoogleCodeJam
{
public:
    string case_prefix;
    void exec()
    {
        ll n;
        cin>>n;
        vector<string> s(n);
        vector<vector<string>> sSprit(n);
        for (int i = 0; i < n; i++)
        {
            cin>>s[i];
        }
        for (int i = 0; i < n; i++)
        {
            sSprit[i]=split_naive(s[i],'*');
        }
        
        vector<string> bgn(n),mid(n),en(n);
        for (int i = 0; i < n; i++)
        {
            if(s[i][0]=='*') bgn[i]="";
            else bgn[i]=sSprit[i][0];

            if(s[i][s[i].size()-1]=='*') en[i]="";
            else en[i]=sSprit[i][sSprit[i].size()-1];
            string midStr ="";
            for (int j = 0; j < sSprit[i].size(); j++)
            {
                if(j==0 && s[i][0]!='*') continue;
                if(j==sSprit[i].size()-1 && s[i][s[i].size()-1]!='*') continue;
                midStr+=sSprit[i][j];
            }
            mid[i]=midStr;
        }

        

        string bStr="",mStr="",eStr="";
        bool ok=true;
        for (int i = 0; i < n; i++)
        {
            if(starts_with(bgn[i],bStr))
            {
                bStr = bgn[i];
            }
            else if(starts_with(bStr,bgn[i]))
            {
                //do nothing    
            }
            else
            {
                cout<<"*"<<endl;
                return;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(ends_with(en[i],eStr))
            {
                eStr = en[i];
            }
            else if(ends_with(eStr,en[i]))
            {
                //do nothing    
            }
            else
            {
                cout<<"*"<<endl;
                return;
            }
        }
        //cout<<"ans:";
        cout<<bStr;
        for (int i = 0; i < n; i++)
        {
            //if(mStr.size()>0)
            cout<<mid[i];
        }
        
        cout<<eStr<<endl;

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