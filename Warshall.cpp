#include<iostream>
#include<iomanip>
using namespace std;

void warshall(int g[10][10],int n)
{
    for(int k=0;k<n;k++)
    {
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(g[i][j]||g[i][k]&&g[k][j])
                    g[i][j]=1;
            }
        }
    }
     cout<<"\nTransitive Matrix is :\n";
        for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<g[i][j]<<"\t";

        }
        cout<<"\n";
    }
}

int main()
{
    int n;
    cout<<"Enter total Rows:";
    cin>>n;
    int g[10][10];
    cout<<"Enter Matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>g[i][j];

        }
    }
    cout<<"Adjacency Matrix is :\n";
        for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<g[i][j]<<"\t";

        }
        cout<<"\n";
    }
    warshall(g,n);
    return 0;

}
