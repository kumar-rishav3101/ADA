#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
void insertionsort(int a[],int n,int count,int ch)
{
    int v,j;
    for(int i=1;i<n;i++)
    {
        v=a[i];
        j=i-1;
        while(j>=0 && a[j]>v)
        {
            a[j+1]=a[j];
            j--;
            count=count+2;
        }
        if((j>=0 && a[j]<=v)||(j<0 && a[j]<=v))
            count++;
        a[j+1]=v;
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<"\t";
    if(ch==1)
        cout<<"\nNumber of comparisions in ascending order = "<<count<<"\n";
    else if(ch==2)
        cout<<"\nNumber of comparisions in descending order = "<<count<<"\n";
    else
        cout<<"\nNumber of comparisions in random order = "<<count<<"\n";
}
int main()
{
    int ch,n,count=0;
    do
    {
        cout<<"1.Ascending Order \n2.Descending Order \n3.Random Order \n4.Exit\nEnter your choice\n";
        cin>>ch;
        switch(ch)
        {
            case 1:{cout<<"Enter no of elements\n";
                        cin>>n;
                        int a[n];
                        for(int i=1;i<=n;i++)
                            a[i-1]=i;
                        insertionsort(a,n,count,1);
                        break;
                    }
            case 2:{cout<<"Enter no of elements\n";
                        cin>>n;
                        int a[n],k=0;
                        for(int i=n;i>=0;i--)
                        {
                            a[k]=i;
                            k++;
                        }
                        insertionsort(a,n,count,2);
                        break;
                    }
            case 3:{cout<<"Enter no of elements\n";
                        cin>>n;
                        int a[n];
                        srand(time(NULL));
                        for(int i=0;i<n;i++)
                            a[i]=rand()%n;
                        insertionsort(a,n,count,3);
                        break;
                    }
            case 4:{exit(0);break;}
        }
    }while(1);
    return 0;
}
