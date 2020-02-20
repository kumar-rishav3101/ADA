#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
using namespace std;
int count;
 int partation(int a[],int l,int r)
 {
     int p=a[r];
     int i=(l-1);
     int temp;
     for(int j=l;j<=r-1;j++)
     {
         if(a[j]<p)
         {
             i++;
             temp = a[i];
             a[i]=a[j];
             a[j]=temp;
             count++;
         }else
         {
             count++;
         }
     }
            temp = a[i+1];
             a[i+1]=a[r];
             a[r]=temp;

             return(i+1);

 }

 void quicksort(int a[],int l,int r,int n)
 {
     if(l<r)
     {
         int s=partation(a,l,r);
         quicksort(a,l,s-1,s-l+1);
         quicksort(a,s+1,r,r-s);
     }
 }

 int main()
 {
     int n;
     cout<<"Enter Total Elements :";
     cin>>n;
     int a[n];

     for(int i=0;i<n;i++)
     {
         cin>>a[i];
     }
     quicksort(a,0,n-1,n);
     for(int i=0;i<n;i++)
     {
         cout<<a[i]<<"  ";
     }
 }
