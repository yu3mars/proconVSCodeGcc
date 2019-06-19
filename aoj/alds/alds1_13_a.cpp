#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pic = pair<int, char>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

static const int FREE=-1;
static const int NOT_FREE = 9;

int row[8],col[8],dpos[2*8-1],dneg[2*8-1];
bool x[8][8];

void initialize()
{
    for(int i = 0; i < 8; i++)
    {
        row[i]=FREE;
        col[i]=FREE;
    }
    for(int i = 0; i < 15; i++)
    {
        dpos[i]=FREE;
        dneg[i]=FREE;
    }
    
    m0(x);
}

void printboard()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(x[i][j]) {
                if(row[i]!=j) return;
            }
        }
        
    }
    
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(row[i]==j) cout<<"Q";
            else cout<<".";
        }
        cout<<endl;
    }
    
}

void recursive(int i){
    if(i==8){
        printboard();
        return;
    }
    for(int j = 0; j < 8; j++)
    {
        if(col[j]==NOT_FREE || dpos[i+j]==NOT_FREE || dneg[i-j+8-1]==NOT_FREE) continue;
        row[i]=j;
        col[j]=dpos[i+j]=dneg[i-j+8-1]=NOT_FREE;
        recursive(i+1);
        row[i]=col[j]=dpos[i+j]=dneg[i-j+8-1]=FREE;
    }
    
}

int main(){
    initialize();
    int k;
    cin>>k;
    for(int i = 0; i < k; i++)
    {
        int r,c;
        cin>>r>>c;
        x[r][c]=true;
    }
    
    recursive(0);
    return 0;
}