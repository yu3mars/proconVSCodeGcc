#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

struct P
{
    string name;
    int time;
};

int head=0,tail=0,len=200000;
P que[200010];

void initialize()
{
    head=0;
    tail=0;
}

bool isEmpty()
{
    return head==tail;
}
bool isFull()
{
    return (tail+1)%len==head;
}

void enqueue(P pp)
{
    que[tail]=pp;
    tail++;
    tail%=len;
}

P dequeue()
{
    P ret = que[head];
    head++;
    head%=len;
    return ret;
}

int main(){
    int n,q;
    ll total=0;
    cin>>n>>q;
    
    for(int i = 0; i < n; i++)
    {
        P pp;
        cin>>pp.name>>pp.time;
        enqueue(pp);
    }
    
    
    while(isEmpty()==false){
        P pp = dequeue();
        if(pp.time<=q)
        {
            total+=pp.time;
            cout<<pp.name<<" "<<total<<endl;
        }
        else
        {
            total+=q;
            pp.time-=q;
            enqueue(pp);
        }
    }
    

    return 0;
}