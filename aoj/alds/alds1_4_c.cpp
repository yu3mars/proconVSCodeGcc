#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

#define M 1046527 // prime number /* your task*/
#define L 14

char H[M][L]; /* Hash Table */

int getChar(char ch){
    if ( ch == 'A') return 1;
    else if ( ch == 'C') return 2;
    else if ( ch == 'G') return 3;
    else if ( ch == 'T') return 4;
}

/* convert a string into an integer value */
long long getKey(char str[]){
    long long sum = 0, p = 1, i;
    for ( i = 0; i < strlen(str); i++ ){
        sum += p*(getChar(str[i]));
        p *= 5;
    }
    return sum;
}

int h1(int key){
    return key % M;/* your task */;
}
int h2(int key){ 
    return 1+key%(M-1);/* your task */; 
}


int find(char str[]){
    /* your task */
    ll key,i,h;
    key=getKey(str);
    for(int i = 0; ; i++)
    {
        h=(h1(key)+i*h2(key))%M;
        if(strcmp(H[h],str)==0) return 1;
        else if(strlen(H[h])==0) return 0;
    }
    return 0;
}

int insert(char str[]){
    /* your task */
    ll key,i,h;
    key=getKey(str);
    for(int i = 0; ; i++)
    {
        h=(h1(key)+i*h2(key))%M;
        if(strcmp(H[h],str)==0) return 1;
        else if(strlen(H[h])==0)
        {
            strcpy(H[h],str);
            return 0;
        }
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        char com[7],str[13];
        scanf("%s %s",com,str);
        if(com[0]=='i')
        {
            insert(str);
        }
        else
        {
            if(find(str))
            {
        		printf("yes\n");
	        }
            else
            {
		        printf("no\n");
	        }
        }
        
    }
    
    return 0;
}