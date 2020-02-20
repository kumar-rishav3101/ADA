#include<iostream>
#include<iomanip>
using namespace std;
int n;
int a[20][20];
void floyd()
{
    int dist[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dist[i][j]=a[i][j];
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    cout<<"Result:-\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dist[i][j]<<"  ";
        }
        cout<<"\n";
    }
}

int main()
{
    cout<<"Enter Total Vertices :";
    cin>>n;
    cout<<"Enter Matrix:-\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    floyd();
}
