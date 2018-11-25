using ll = long long;

// Combination Table 
ll C[51][51]; // C[n][k] -> nCk 

void comb_table (int N)
{ 
    for (int i = 0 ;i <= N; i++)
    { 
        for (int j = 0 ;j <= i; j++)
        { 
            if (j == 0 or j == i)
            {
                C[i][j] = 1LL; 
            }
            else
            { 
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]); 
            } 
        } 
    } 
}
