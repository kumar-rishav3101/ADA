#include<stdlib.h>
#include<iostream>
using namespace std;

int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

void knapsack(int n,int wt[],int p[],int cap)
{
    int v[10][10],i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=cap;j++)
        {
            if(i==0||j==0)
                v[i][j]=0;
            else if(j<wt[i])
                v[i][j]=v[i-1][j];
            else
                v[i][j]=max(v[i-1][j],v[i-1][j-wt[i]]+p[i]);
        }
    }

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=cap;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"The Optimized Value is :\t"<<v[n][cap];
}

int main()
{
    int cap,n;
    cout<<"Enter Capacity Of Knapsack ";
    cin>>cap;
    cout<<"Enter Total Count Of Elements :";
    cin>>n;
    int wt[n],v[n];
    cout<<"Enter Capacity And Value OF Each Elements \n";
    for(int i=0;i<n;i++)
    {
        cin>>wt[n]>>v[n];
    }
    cout<<"The Table is\n";
    knapsack(n,wt,v,cap);
    return 0;
}
