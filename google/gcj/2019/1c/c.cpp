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
    int r,c;
    unordered_map<string, bool[2]> um;
    vector<string> mpconv(string s)
    {
        vector<string> ret(r);
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                ret[i]+=s[i*c+j];
            }
        }
        return ret;
    }
    string mpconv(vector<string> v)
    {
        string ret;
        for(int i = 0; i < r; i++)
        {
            ret+=v[i];
        }
        return ret;
    }

    void bfs(int cnt, string mpStr){
        if(um.count(mpStr)>0) return;
        bool bans[2];
        vector<string> mp = mpconv(mpStr);
        set<int> ret;
        int ans=0;
        for(int x = 0; x < c; x++)
        {
            for(int y = 0; y < r; y++)
            {
                if(mp[y][x]!='.') continue;
                vector<string> nextmp(mp.size());
                bool ok;
                // set v
                for(int i = 0; i < mp.size(); i++)
                {
                    nextmp[i]=mp[i];
                }
                
                ok=true;
                nextmp[y][x]='!';
                for(int i = y+1; i < r; i++)
                {
                    if(mp[i][x]=='#'){
                        ok=false;
                        break;
                    }
                    else if(mp[i][x]=='!') break;
                    else
                    {
                        nextmp[i][x]='!';
                    }
                }
                for(int i = y - 1; i >= 0; i--)
                {
                    if(mp[i][x]=='#'){
                        ok=false;
                        break;
                    }
                    else if(mp[i][x]=='!') break;
                    else
                    {
                        nextmp[i][x]='!';
                    }
                }
                
                if(ok)
                {
                    bfs(cnt+1, mpconv(nextmp));
                    auto result = um
                }

                if(cnt==0)
                {
                    //cout<<"v"<<"\t"<<x<<"\t"<<y<<endl;//
                    for(auto it = ret.begin(); it != ret.end(); it++)
                    {
                        //cout<<*it<<endl;//
                        if(*it %2 == 1)
                        {
                            ans++;
                            break;
                        }
                    }
                    ret.clear();
                }
                
                // set h
                for(int i = 0; i < mp.size(); i++)
                {
                    nextmp[i]=mp[i];
                }
                ok=true;
                nextmp[y][x]='!';
                for(int i = x+1; i < c; i++)
                {
                    if(mp[y][i]=='#'){
                        ok=false;
                        break;
                    }
                    else if(mp[y][i]=='!') break;
                    else
                    {
                        nextmp[y][i]='!';
                    }
                }
                for(int i = x - 1; i >= 0; i--)
                {
                    if(mp[y][i]=='#'){
                        ok=false;
                        break;
                    }
                    else if(mp[y][i]=='!') break;
                    else
                    {
                        nextmp[y][i]='!';
                    }
                }
                
                if(ok)
                {
                    set<int> prog = bfs(cnt+1, mpconv(nextmp));
                    for(auto it = prog.begin(); it != prog.end(); it++)
                    {
                        ret.insert(*it +1);
                    }
                }

                if(cnt==0)
                {
                    //cout<<"v"<<"\t"<<x<<"\t"<<y<<endl;//
                    for(auto it = ret.begin(); it != ret.end(); it++)
                    {
                        //cout<<*it<<endl;//
                        if(*it %2 == 1)
                        {
                            ans++;
                            break;
                        }
                    }
                    ret.clear();
                }
            }
        }
        if(cnt==0)
        {
            set<int> newret;
            newret.insert(ans);
            return;
        }
        if(ret.size()==0)
        {
            ret.insert(0);
            bans[0]=true;
            bans[1]=false;
            um.emplace(make_pair(mpStr, bans));
        }
        return;
    }

    void exec()
    {
        um.clear();
        cin>>r>>c;
        vector<string> mp(r);
        for(int i = 0; i < r; i++)
        {
            cin>>mp[i];
        }
        auto finalAns = bfs(0, mpconv(mp));
        cout<<*finalAns.begin()<<endl;
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