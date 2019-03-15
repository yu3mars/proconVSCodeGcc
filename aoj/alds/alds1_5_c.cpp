#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

struct Point
{
    double x,y;
};
double rad60 = M_PI*60/180;

void print(Point p)
{
    cout<<p.x<<" "<<p.y<<endl;
}

void kock(int n,Point p1,Point p2)
{
    if(n==0) return;
    Point s,t,u;
    s.x=(p1.x*2+p2.x)/3;
    s.y=(p1.y*2+p2.y)/3;
    t.x=(p1.x+p2.x*2)/3;
    t.y=(p1.y+p2.y*2)/3;
    u.x=(t.x-s.x)*cos(rad60)-(t.y-s.y)*sin(rad60)+s.x;
    u.y=(t.x-s.x)*sin(rad60)+(t.y-s.y)*cos(rad60)+s.y;

    kock(n-1,p1,s);
    print(s);
    kock(n-1,s,u);
    print(u);
    kock(n-1,u,t);
    print(t);
    kock(n-1,t,p2);
}

int n;
int main(){
    cin>>n;
    Point pp1,pp2;
    pp1.x=0;
    pp1.y=0;
    pp2.x=100;
    pp2.y=0;
    print(pp1);
    kock(n,pp1,pp2);
    print(pp2);
    return 0;
}