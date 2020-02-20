#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
using namespace std;
int n;

void merge(int b[],int p,int c[],int q,int arr[])
{
    int i=0,j=0,k=0;
    while(i<p&&j<q)
    {
        if(b[i]<c[j])
        {
            arr[k]=b[i];
            i++;
        }
        else
        {
            arr[k]=c[j];
            j++;
        }
        k++;
    }
    if(i==p)
    {
        for(int x=j;x<q;x++)
        {
            arr[k]=c[x];
            k++;
        }
    }else
    {
        for(int x=i;x<p;x++)
        {
            arr[k]=b[x];
            k++;
        }
    }

    if(k==n)
    {
        for(int x=0;x<n;x++)
        {
            cout<<arr[x]<<" ";
        }
    }
}

void mergesort(int arr[],int n)
{
    int b[n],c[n];
    int bn=0,cn=0;

    if(n>1)
        {
    for(int i=0 ; i <= floor((n/2)-1);i++)
    {
        b[bn]=arr[i];
        bn++;
    }
    for(int i=n/2;i<n;i++)
    {
        c[cn]=arr[i];
        cn++;
    }
    mergesort(b,bn);
    mergesort(c,cn);
    merge(b,bn,c,cn,arr);

        }
}
int main()
 {
     cout<<"Enter Total Elements :";
     cin>>n;
     int a[n];
     cout<<"Enter Each Elements :\n";
     for(int i=0;i<n;i++)
     {
         cin>>a[i];
     }
     cout<<"Sorted Array :\n";
     mergesort(a,n);

 }

