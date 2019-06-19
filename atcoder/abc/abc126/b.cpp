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
    string s;
    cin>>s;
    bool atoMM, maeMM;
    atoMM=false;
    maeMM=false;
    if((s[0]=='0' && s[1]!='0') || (s[0]=='1' && (s[1]=='0' || s[1]=='1' || s[1]=='2')))
    {
        maeMM=true;
    } 
    if((s[2]=='0' && s[3]!='0') || (s[2]=='1' && (s[3]=='0' || s[3]=='1' || s[3]=='2')))
    {
        atoMM=true;
    }
    if(atoMM==true && maeMM==false)
    {
        cout<<"YYMM"<<endl;
    }
    else if(atoMM==false && maeMM==true)
    {
        cout<<"MMYY"<<endl;
    }
    else if(atoMM==true && maeMM==true)
    {
        cout<<"AMBIGUOUS"<<endl;
    }
    else if(atoMM==false && maeMM==false)
    {
        cout<<"NA"<<endl;
    }
    
    return 0;
}