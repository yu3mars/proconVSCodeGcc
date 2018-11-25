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
    for(;;)
    {
        string s[2];
        cin>>s[0];
        if(s[0]==".") break;
        cin>>s[1];
        if(s[0]==s[1])
        {
            cout<<"IDENTICAL"<<endl;
            continue;
        }
        
        for(int i = 0; i < 2; i++)
        {
            s[i]="a"+s[i]+"a";
        }
        vector<string> v[2];
        
        for(int i = 0; i < 2; i++)
        {
            string tmp="";
            for(int j = 0; j < s[i].size(); j++)
            {
                if(s[i][j]!='"')
                {
                    tmp+=s[i][j];
                    if(j==s[i].size()-1)
                    {
                        v[i].push_back(tmp);
                        tmp="";
                    }
                }
                else
                {
                    v[i].push_back(tmp);
                    tmp="";
                }
            }
        }
        if(v[0].size()!=v[1].size())
        {
            cout<<"DIFFERENT"<<endl;
        }
        else
        {
            bool ok = true;
            int diffcnt=0;
            
            for(int i = 0; i < v[0].size(); i++)
            {
                //cout<<v[0][i]<<"\t"<<v[1][i]<<endl;
                if(v[0][i]!=v[1][i])
                {
                    if(i%2==0)
                    {
                        ok = false;
                        break;
                    }
                    else
                    {
                        diffcnt++;
                        if(diffcnt>1) break;
                    }
                }
            }
            //cout<<ok<<"\t"<<diffcnt<<endl;
            if(ok)
            {
                if(diffcnt==0) 
                {
                    cout<<"IDENTICAL"<<endl;
                }
                else if(diffcnt==1)
                {
                    cout<<"CLOSE"<<endl;
                }
                else
                {
                    cout<<"DIFFERENT"<<endl;
                }
            }
            else
            {
                cout<<"DIFFERENT"<<endl;
            }
        }
        
    }

    return 0;
}