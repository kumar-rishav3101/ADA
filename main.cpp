#include <iostream>
#include<math.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

void Binary(int a[],int l,int h ,int key)
{
    int mid;
    mid=(l+h)/2;
    if(h<l)
    {
        cout<<"\nMatch Not Found\n";
        return;
    }
    if(a[mid]<key)
    {
        return(Binary(a,mid+1,h,key));
    }else if(a[mid]>key)
    {
        return(Binary(a,l,mid-1,key));
    }else
    {
        cout<<"\nMatch Found at position \n"<<mid;
        return;
    }
}

void linear(int a[],int key,int c,int l)
{
    if(c==l)
    {
        cout<<"\nMatch Not Found\n";
        return;
    }
    if(a[c]!=key)
    {
        return(linear(a,key,c+1,l));
    }else
    {
        cout<<"\nMatch Found At Position:\n"<<c;
        return;
    }
}

int main()
{
   int n;
   cout<<"Enter Total No of Elements ";
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
   {
       a[i]=rand()%5000;
   }
   cout<<"Given Array\n";
   for(int i =0;i<n;i++)
   {
       cout<<a[i]<<"\t";
   }

   int key;
   cout<<"\nEnter Key :\n";
   cin>>key;
   cout<<"LINEAR SEARCH\n";
   linear(a,key,0,n);

   sort(a,a+n);
   cout<<"BINARY SEARCH\n";
   Binary(a,0,n,key);
}
