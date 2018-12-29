#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {0,1,0,-1}, dy4[4] = {-1,0,1,0};


struct quest
{
    public: ll a,b,c,s[10];

};

int t,n,m;
quest q[30000];
ll nowSkill[10];
ll nowMoney;
vector<int> qfinal[1010];

ll calcQScore(int t, int i)//turn t & quest i
{
    double AddMoney = q[i].c;
    AddMoney *= (1 + 9 * (double)(t - q[i].a) / (q[i].b - q[i].a));
    int SkillLack = 0;
    for (int j = 0; j < n; j++) SkillLack += max(0LL, q[i].s[j] - nowSkill[j]);

    if (SkillLack == 0) AddMoney *= 10;
    else {
        AddMoney *= pow(0.5, SkillLack);
        AddMoney += 1e-9;
    }
    return (long long)AddMoney;
}


int main()
{
    cin>>t>>n>>m;
    nowMoney=1000;
    for(int i = 0; i < 10; i++)
    {
        nowSkill[i]=0;
    }
    
    for(int i = 0; i < m; i++)
    {
        quest qq;
        cin>>qq.a>>qq.b>>qq.c;
        
        for(int j = 0; j < 10; j++)
        {
            cin>>qq.s[j];
        }
        q[i]=qq;
        qfinal[qq.b].push_back(i);
    }
    
    for(int turn = 1; turn <= t; turn++)
    {
        string cmd="3";
        int qDo = -1;
        ll qDoMoney=1000;
        ll skillShikiichi = 0;
        
        for(int skilli = 0; skilli < 10; skilli++)
        {
            skillShikiichi+=nowSkill[skilli];
        }
        skillShikiichi = 1000*pow(1.3, skillShikiichi);
        
        for(int qi = 0; qi < qfinal[turn].size(); qi++)
        {
            int qNumTmp = qfinal[turn][qi];
            ll qMoneyTmp = calcQScore(turn,qNumTmp);
            if(qMoneyTmp>qDoMoney)
            {
                qDo = qNumTmp;
                qDoMoney=qMoneyTmp;
            }
        }

        int trainDo=-1;  
        ll useMoney=0;   
        for(int skilli = 0; skilli < 10; skilli++)
        {
            ll needMoney = 10000*(ll)(pow(2,(int)nowSkill[skilli]+1));
            if(needMoney<=nowMoney)
            {
                trainDo=skilli;
                useMoney=needMoney;
            }
        }
        
        if(qDo>=0 && q[qDo].c>skillShikiichi)
        {
            cmd = "2 "+to_string(qDo+1);
            nowMoney+=q[qDo].c;
        }
        else
        {
            if(trainDo>=0)
            {
                cmd = "1 "+to_string(trainDo);
                nowMoney-=useMoney;
            }
            else if(qDo>=0)
            {
                cmd = "2 "+to_string(qDo+1);
                nowMoney+=q[qDo].c;
            }
            else
            {
                cmd="3";
                nowMoney+=1000;
            }
        }
        
        cout<<cmd<<endl;
    }
    
    return 0;
}