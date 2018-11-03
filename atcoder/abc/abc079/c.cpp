#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    string ans;
    string s;
    cin >> s;
    int ls[4];
    string op[] = {"+","-"};
    
    for(int i = 0; i < 4; i++)
    {
        ls[i] = s.at(i)-'0';
    }
    
    
    for(int bit = 0; bit < (1<<3); bit++)
    {
        int tmp = ls[0];
        
        for(int i = 0; i < 3; i++)
        {
            if(((bit>>i)& 1)== 0)//plus
            {
                tmp+=ls[i+1];
            }
            
            else
            {
                tmp-=ls[i+1];
            }
            
        }
        if(tmp==7)
        {
            
            for(int j = 0; j < 3; j++)
            {
                cout << ls[j] << op[(bit>>j) & 1];
            }
            cout << ls[3] << "=7" << endl;
            break;
        }
    }
    
    return 0;
}