#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    cin >> n >> a;

    // ここにプログラムを追記
  
    for(int i = 0; i < n; i++)
    {
        char op;
        int b;
        cin >> op >> b;
        if(op == '+')
        {
            a +=b;
            cout << i+1 << ':' << a << endl;
        }
        else if(op == '-')
        {
            a-=b;
            cout << i+1 << ':' << a << endl;
        }
        else if(op == '*')
        {
            a*=b;
            cout << i+1 << ':' << a << endl;
        }
        else if(op == '/')
        {
            if(b == 0) 
            {
                cout << "error" << endl;
                break;
            }
            a/=b;
            cout << i+1 << ':' << a << endl;
        }
        
    }
  
}
