#include<iostream>
#include<iomanip>
using namespace std;
int cost[10][10],v,visited[10],visit[10],stk[10],top;
int main()
{
    int n,m,i,j,k;
    cout<<"Enter Total No of Vertices :";
    cin>>n;
    cout<<"Enter Total No of Edges:";
    cin>>m;
    cout<<"Enter Each Edge :";
    for(k=0;k<m;k++)
    {
        cin>>i>>j;
        cost[i][j]=1;
    }
    cout<<"Enter initial vertex To begin Traverse from ";
    cin>>v;
    cout<<"DFS \n";
    cout<<v<<" ";
    visited[v]=1;
    k=1;
    while(k<n)
    {
        for(j=n;j>0;j--)
        {
            if(cost[v][j]!=0&&visited[j]!=1&&visit[j]!=1)
            {
                visit[j]=1;
                stk[top]=j;
                top++;
            }

        }
         v=stk[--top];
            cout<<v<<" ";
            k++;
            visit[v]=0;
            visited[v]=1;
    }
    return 0;
}
