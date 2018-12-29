#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int top, stk[110];

void initialize()
{
    top=0;
}

void push(int n)
{
    top++;
    stk[top]=n;
}
bool isFull()
{
    return top>=110;
}
bool isEmpty()
{
    return top==0;
}

int pop()
{
    if(isEmpty())
    {
        cout<<"err"<<endl;
        return -9999999;
    }
    top--;
    return stk[top+1];
}

int main(){
    int x;
    char s[100];
    initialize();

    while(scanf("%s", s) != EOF ){
        if ( s[0] == '+' ){
            int a=pop();
            int b=pop();
            push(a+b);
        } else if ( s[0] == '-' ){
            int a=pop();
            int b=pop();
            push(b-a);
        } else if ( s[0] == '*' ){
            int a=pop();
            int b=pop();
            push(a*b);
        } else {
            x = atoi(s);
            push(x);
        }
    }
    cout<<pop()<<endl;

    return 0;
}