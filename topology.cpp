#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    int n,c=0,o=0,n1;

    cout<<"Enter number of vertices in a graph :\n";
    cin>>n;
    n1=n;
    int x=n;
    int a[n][n],t[n];
    cout<<"Enter the Adjacancy Matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
        t[i]=0;
    }
    while(x>0)
    {
        for(int i=0;i<n;i++)
        {
            if(t[i]==0)
            {
                c=0;
                for(int j=0;j<n;j++)
                {
                        if(a[j][i]!=0)
                            c++;
                        if(c==1)
                            break;
                }
                if(c==0)
                {
                    o++;
                    t[i]=o;
                    for(int h=0;h<n;h++)
                        a[i][h]=0;
                }
            }
        }
        x=x-1;
    }

    cout<<"Topological ordering is \n";
    for(int i=0;i<n1;i++)
        cout<<t[i]<<"\t";
}
