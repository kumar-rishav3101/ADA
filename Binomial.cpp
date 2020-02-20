#include<iostream>
using namespace std;

int binomial(int n,int k)
{
    if(k==0||k==n)
        return 1;
    return(binomial(n-1,k-1)+binomial(n-1,k));

}

int main()
{
    int n,k;
    cout<<"Enter Value of n:";
    cin>>n;
    cout<<"Enter value of k:";
    cin>>k;
    cout<<binomial(n,k);
}
