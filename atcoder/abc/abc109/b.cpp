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
	int n;
	cin >> n;
	vector<string> s;
	bool ok = true;
	for (int i = 0; i < n; i++)
	{
		string ss;
		cin >> ss;
		s.push_back(ss);
	}
	for (int i = 0; i < n; i++)
	{
		if (i > 0)
		{
			if (s[i - 1][s[i - 1].length() - 1] != s[i][0])
			{
				ok = false;
				break;
			}
		}
	}
    
    for(int i = 0; i < n; i++)
    {
        if(ok==false) break;
        for(int j = 0; j < i; j++)
        {
            if(s[i]==s[j])
            {
                ok = false;
                break;
            }
        }
        
    }
    

	if (ok)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
    return 0;
}