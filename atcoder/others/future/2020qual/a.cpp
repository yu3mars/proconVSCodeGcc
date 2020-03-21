#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {0,0,1,-1}, dy4[4] = {1,-1,0,0};
char dc4[4] = {'U','D','L','R'};
unordered_map<char, int> mpc{{'U', 0}, {'D', 1}, {'L', 2}, {'R', 3}, };
int dx4_r[4] = {0,0,-1,1}, dy4_r[4] = {-1,1,0,0};

int n,m,b;
int gx,gy;
vector<tuple<int,int,char>> r;  //y,x,c
vector<pii> byx;
char mp[40][40];
bool checked[40][40];
bool used[40][40];

int nextFix(int i)
{
    return (i+n)%n;
}

void input()
{
    cin>>n>>m>>b;
    cin>>gy>>gx;
    r.resize(m);
    for (int i = 0; i < m; i++)
    {
        int xx,yy;
        char cc;
        cin>>yy>>xx>>cc;
        r[i]=make_tuple(yy,xx,cc);
    }
    byx.resize(b);
    for (int i = 0; i < b; i++)
    {
        int yy,xx;
        cin>>yy>>xx;
        byx[i]=make_pair(yy,xx);
    }
}

void solve()
{
    m0(checked);
    m0(mp);

    mp[gy][gx]='G';
    checked[gy][gx]=true;
    for (int i = 0; i < b; i++)
    {
        mp[byx[i].first][byx[i].second]='B';
        checked[byx[i].first][byx[i].second]=true;
    }
    
    // set arrow
    queue<int> qy,qx;
    qy.push(gy);
    qx.push(gx);
    while (qy.size()>0)
    {
        int nowy=qy.front();
        qy.pop();
        int nowx=qx.front();
        qx.pop();
        for (int i = 0; i < 4; i++)
        {
            int nexty=nextFix(nowy+dy4[i]);
            int nextx=nextFix(nowx+dx4[i]);
            if(checked[nexty][nextx]==false)
            {
                
                mp[nexty][nextx]=dc4[i];
                
                checked[nexty][nextx]=true;
                qy.push(nexty);
                qx.push(nextx);
            }

        }
    }

    // remove unused arrow
    m0(used);
    for (int robot = 0; robot < m; robot++)
    {
        m0(checked);
        int nowy =get<0>(r[robot]);
        int nowx =get<1>(r[robot]);
        char nowc =get<2>(r[robot]);
        vector<pii> usedPanel;
        bool goaled=false;
        checked[nowy][nowx]=true;
        int changeCnt=0;

        for (int turn = 0; turn < 10000; turn++)
        {
            //cout<<robot<<"\t"<<nowy<<"\t"<<nowx<<"\t"<<nowc<<endl;//
            char mapc=mp[nowy][nowx];
            int nowCInt = mpc[nowc];

            if(mp[nowy][nowx]=='G')
            {
                goaled=true;
                //cout<<"goaled!"<<endl;//
                break;
            }
            else if(mp[nowy][nowx]=='B')
            {
                //cout<<"failed!"<<endl;//
                break;
            }
            
            if(mapc!=nowc)
            {
                nowc=mapc;
                nowCInt = mpc[nowc];
                usedPanel.push_back(make_pair(nowy,nowx));
                changeCnt++;
                //cout<<"changed"<<endl;
            }
            nowy=nextFix(nowy+dy4_r[nowCInt]);
            nowx=nextFix(nowx+dx4_r[nowCInt]);
            checked[nowy][nowx]=true;
        }
        if(goaled)
        {
            for (int i = 0; i < usedPanel.size(); i++)
            {
                used[usedPanel[i].first][usedPanel[i].second]=true;
            }
        }
    }

    // tsukawazu ikeru?
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if(mp[y][x]=='U' || mp[y][x]=='D' || mp[y][x]=='L' || mp[y][x]=='R')
            {
                if(used[y][x]==false)
                {
                    mp[y][x]='X';
                }
            }
        }
    }

    for (int  chal = 0; chal < 50; chal++)
    {
            
        // ikko kesu
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                if(mp[y][x]=='U' || mp[y][x]=='D' || mp[y][x]=='L' || mp[y][x]=='R')
                {
                    char tmpC=mp[y][x];
                    mp[y][x]='X';
                    bool allGoal=true;
                    m0(used);
                    for (int robot = 0; robot < m; robot++)
                    {
                        m0(checked);
                        int nowy =get<0>(r[robot]);
                        int nowx =get<1>(r[robot]);
                        char nowc =get<2>(r[robot]);
                        vector<pii> usedPanel;
                        bool goaled=false;
                        checked[nowy][nowx]=true;
                        int changeCnt=0;

                        for (int turn = 0; turn < 3000; turn++)
                        {
                            //cout<<robot<<"\t"<<nowy<<"\t"<<nowx<<"\t"<<nowc<<endl;//
                            char mapc=mp[nowy][nowx];
                            int nowCInt = mpc[nowc];

                            if(mp[nowy][nowx]=='G')
                            {
                                goaled=true;
                                //cout<<"goaled!"<<endl;//
                                break;
                            }
                            else if(mp[nowy][nowx]=='B')
                            {
                                //cout<<"failed!"<<endl;//
                                break;
                            }
                            
                            if(mapc!='X' && mapc!=nowc)
                            {
                                nowc=mapc;
                                nowCInt = mpc[nowc];
                                usedPanel.push_back(make_pair(nowy,nowx));
                                changeCnt++;
                                //cout<<"changed"<<endl;
                            }
                            nowy=nextFix(nowy+dy4_r[nowCInt]);
                            nowx=nextFix(nowx+dx4_r[nowCInt]);
                            checked[nowy][nowx]=true;
                        }
                        if(goaled)
                        {
                            for (int i = 0; i < usedPanel.size(); i++)
                            {
                                used[usedPanel[i].first][usedPanel[i].second]=true;
                            }
                        }
                        else
                        {
                            allGoal=false;
                            break;
                        }
                        
                    }

                    if(allGoal)
                    {
                        //cout<<"all goal\t"<<y<<"\t"<<x<<endl;//
                        //cout<<mp[y][x]<<endl;
                        // tsukawazu ikeru?
                        for (int yy = 0; yy < n; yy++)
                        {
                            for (int xx = 0; xx < n; xx++)
                            {
                                if(mp[yy][xx]=='U' || mp[yy][xx]=='D' || mp[yy][xx]=='L' || mp[yy][xx]=='R')
                                {
                                    if(used[yy][xx]==false)
                                    {
                                        mp[yy][xx]='X';
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        mp[y][x]=tmpC;
                    }
                    
                }
            }
        }
    }

    
}

void printMap()
{
    cout<<"printMap Start"<<endl;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            cout<<mp[y][x];
        }
        cout<<endl;
    }
    cout<<"printMap End"<<endl;
}

void printAns()
{
    vector<tuple<int,int,char>> ansv;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if(mp[y][x]=='U' || mp[y][x]=='D' || mp[y][x]=='L' || mp[y][x]=='R')
            {
                ansv.push_back(make_tuple(y,x,mp[y][x]));
            }
        }
    }
    cout<<ansv.size()<<endl;
    for (int i = 0; i < ansv.size(); i++)
    {
        cout<<get<0>(ansv[i])<<" "<<get<1>(ansv[i])<<" "<<get<2>(ansv[i])<<endl;
    }
}

void fileWriteAns()
{
    string filename = "atcoder/others/future/2020qual/MyOutput6.txt";
    std::ofstream writing_file;
    writing_file.open(filename, std::ios::out);
    vector<tuple<int,int,char>> ansv;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if(mp[y][x]=='U' || mp[y][x]=='D' || mp[y][x]=='L' || mp[y][x]=='R')
            {
                ansv.push_back(make_tuple(y,x,mp[y][x]));
            }
        }
    }
    writing_file<<ansv.size()<<endl;
    for (int i = 0; i < ansv.size(); i++)
    {
        writing_file<<get<0>(ansv[i])<<" "<<get<1>(ansv[i])<<" "<<get<2>(ansv[i])<<endl;
    }
    writing_file.close();
}

int main()
{
    input();
    solve();
    printAns();

    //printMap();
    //fileWriteAns();

    return 0;
}