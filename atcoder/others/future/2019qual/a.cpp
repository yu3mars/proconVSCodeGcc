#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {0,1,0,-1}, dy4[4] = {-1,0,1,0};
char cls[6] = {'.','.','L','R','D','T'};

int n,m,l;
vector<string> s;

int CalcScore(vector<string> myans, int mycnt[30][30])
{
    int score =0;
    for(int icmd = 0; icmd < n; icmd++)
    {
        int x = (m+1)/2, y=(m+1)/2, dir=0;
        
        for(int j = 0; j < l; j++)
        {
            if(s[icmd][j]=='S')
            {
                if(myans[y+dy4[dir]][x+dx4[dir]]!='#')
                {
                    x+=dx4[dir];
                    y+=dy4[dir];
                }
            }
            else if(s[icmd][j]=='L')
            {
                dir+=3;
                dir%=4;
            }
            else if(s[icmd][j]=='R')
            {
                dir+=1;
                dir%=4;
            }
        }
        mycnt[y][x]++;
    }
    
    for(int yy = 1; yy < m-1; yy++)
    {        
        for(int xx = 1; xx < m-1; xx++)
        {
            int cnttmp = mycnt[yy][xx];
            if(cnttmp==1) score+=10;
            else if(cnttmp==2) score+=3;
            else if(cnttmp==3) score++;

            //cout <<cnttmp << " ";  //comment out
        } 
        //cout << endl;  //comment out
    } 
    
    for(int i = 0; i < m; i++)
    {
        //cout << myans[i]<<endl;  //comment out
    }
    
    return score;
}

int main()
{
    std::random_device rnd;
    std::mt19937 mt(rnd());
    std::uniform_int_distribution<> rand6(0, 5);
    std::uniform_int_distribution<> rand2(0, 2);

    cin>>n>>m>>l;
    
    vector<string> ans(m);
    int cnt[30][30];
    m0(cnt);

    //　init map;
    string baseStr = "#";
    for(int i = 0; i < m-2; i++)
    {
        baseStr+='.';
    }
    baseStr+='#';
    for(int i = 0; i < m; i++)
    {
        ans[i]=baseStr;
    }
    for(int i = 0; i < m; i++)
    {
        ans[0][i]='#';
        ans[m-1][i]='#';
    }
    
    for(int i = 0; i < n; i++)
    {
        string ss;
        cin>>ss;
        s.push_back(ss);
    }
    
    int ansScore = CalcScore(ans, cnt);
    vector<string> tmpans(m);

    
    for(int trycnt = 0; trycnt < 1500; trycnt++)
    {
        int tmpcnt[30][30];
        m0(tmpcnt);
        
        for(int i = 0; i < m; i++)
        {
            tmpans[i]=ans[i];
        }
        
        for(int yy = 1; yy < m-1; yy++)
        {        
            for(int xx = 1; xx < m-1; xx++)
            {
                for(int i = 0; i < 4; i++)
                {
                    int ny = yy+dy4[i];
                    int nx = xx+dx4[i];
                    if(ny!=0&&ny!=m&&nx!=0&&nx!=m)
                    {
                        tmpans[yy][xx] = cls[rand6(mt)];
                        if(rand2(mt)==0)
                        {
                            tmpans[yy][xx]='.';
                        }
                        
                    }
                }                
            }            
        }

        int tmpScore = CalcScore(tmpans, tmpcnt);
        //cout << tmpScore<<endl;//comment out!
        if(ansScore < tmpScore)
        {
            ansScore = tmpScore;
            
            for(int i = 0; i < m; i++)
            {
                ans[i] = tmpans[i];
            }
            
            for(int i = 0; i < 30; i++)
            {
                
                for(int j = 0; j < 30; j++)
                {
                    cnt[i][j]=tmpcnt[i][j];
                }                
            }
            
        }
    }

    

    for(int i = 0; i < m; i++)
    {
        ans[0][i]='#';
        ans[m-1][i]='#';
        ans[i][0]='#';
        ans[i][m-1]='#';
    }
    for(int i = 0; i < m; i++)
    {
        cout<<ans[i]<<endl;
    }
    
    return 0;
}