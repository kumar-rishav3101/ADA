#include<iostream>
#include<iomanip>
using namespace std;
int number[10],stk[10],top=-1;
int subset(int pos,int sum,int n,int stk[])
{
    int i;
    static int found =0;
    if(sum>0)
    {
        for(i=pos;i<n;i++)
        {
            stk[++top]=number[i];
            subset(i+1,sum-number[i],n,stk);
            top--;
        }
    }
    if(sum==0)
    {
        for(i=top;i>=0;i--)
            cout<<stk[i]<<" ";
        cout<<"\n";
        found=1;
    }
    return found;
}
int main()
{
    int n,sum=0;
    cout<<"Enter Total no of Elements :";
    cin>>n;
    cout<<"Enter All elements ";
    for(int i=0;i<n;i++)
    {
        cin>>number[i];
    }
    cout<<"Enter Sum :";
    cin>>sum;
    if(!subset(0,sum,n,stk))
    {
        cout<<"No Solution :";
    }else
    {
        cout<<"Solution";
    }

}
