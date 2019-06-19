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

int mp[1410][1410];
int dp[1410][1410];
int h,w;

class Rectangle{
    public:
    int height;
    int left;
    Rectangle(){};
    Rectangle(int height, int left):height(height),left(left) {};
};

int getLargestRectangle(int buffer[]){
    int maxv=0;
    stack<Rectangle> s;
    for(int i = 0; i <= w; i++)
    {
        Rectangle rect = Rectangle(buffer[i],i);
        if(s.empty())
        {
            s.push(rect);
        }
        else if(s.top().height<rect.height)
        {
            s.push(rect);
        }
        else if(s.top().height>rect.height)
        {
            int target = i;
            while(s.empty()==false && s.top().height>rect.height)
            {
                Rectangle pre = s.top();
                s.pop();
                int area = pre.height * (i - pre.left);
                maxv = max(maxv, area);
                target=pre.left;
            }
            rect.left=target;
            s.push(rect);
        }
    }
    return maxv;
}

int getLargestRectangle(){
    int ans=0;
    for(int ww = 0; ww < w; ww++)
    {
        for(int hh = 0; hh < h; hh++)
        {
            if(mp[hh][ww]==1) dp[hh][ww]=0;
            else if (hh==0) dp[hh][ww]=1;
            else 
            {
                dp[hh][ww]=dp[hh-1][ww]+1;
            }
        }
    }
    for(int hh = 0; hh < h; hh++)
    {
        ans = max(ans, getLargestRectangle(dp[hh]));
    }
    return ans;
}

int main(){
    cin>>h>>w;
    m0(mp);
    m0(dp);
    for(int hh = 0; hh < h; hh++)
    {
        for(int ww = 0; ww < w; ww++)
        {
            cin>>mp[hh][ww];
        }
    }
    cout<< getLargestRectangle()<<endl;
    return 0;
}