#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

struct Node{
    int key;
    Node *prev, *next;
};

Node *nil;

void Init()
{
    nil = (Node *)malloc(sizeof(Node));
    nil->next=nil;
    nil->prev=nil;
}

void InsertNode(int key)
{
    Node *x = (Node *)malloc(sizeof(Node));
    x->key=key;
    x->next=nil->next;
    nil->next->prev=x;
    nil->next=x;
    x->prev=nil;
}

Node* ListSearch(int key)
{
    Node *cur=nil->next;
    while(cur!=nil && cur->key!=key)
    {
        cur=cur->next;
    }
    return cur;
}

void DeleteNode(Node *t)
{
    if(t==nil)return;
    t->prev->next=t->next;
    t->next->prev=t->prev;
    free(t);
}

void DeleteFirst()
{
    DeleteNode(nil->next);
}

void DeleteLast()
{
    DeleteNode(nil->prev);
}

void DeleteKey(int key)
{
    DeleteNode(ListSearch(key));
}

void PrintNodes()
{
    Node *cur=nil->next;
    while(cur!=nil)
    {
        printf("%d",cur->key);
        if(cur->next !=nil)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
        }
        cur=cur->next;
    }
}

int main(){
    Init();
    int n;
    cin>>n;
    
    for(int i = 0; i < n; i++)
    {
        char c[20];
        int key;
        scanf("%s", c);
        if(c[0]=='i')//insert
        {
            scanf("%d",&key);
            InsertNode(key);
        }
        else if(strlen(c)==6)//delete
        {
            scanf("%d",&key);
            DeleteKey(key);
        }
        else if(c[6]=='F')//deleteFirst
        {
            DeleteFirst();
        }
        else //deleteLast
        {
            DeleteLast();
        }
    }
    PrintNodes();

    return 0;
}