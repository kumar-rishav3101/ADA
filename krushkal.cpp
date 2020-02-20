#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
class Edges
{
    public:int sources,dest,weights;
};

bool compare(Edges e1,Edges e2){
    return e1.weights<e2.weights;}

int findParent(int v,int *parent)
{
    if(parent[v]==v)
        return v;
    else
        return(findParent(parent[v],parent));
}


void krushkal(Edges *input,int n,int E)
{
    sort(input,input+E,compare);
    Edges *output=new Edges[n-1];
    int *parent = new int[n];
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    int count=0;
    int i=0;
    while(count !=n-1)
    {
        Edges CurrentEdge=input[i];
        int sourceParent=findParent(CurrentEdge.sources,parent);
        int destParent=findParent(CurrentEdge.dest,parent);

        if(sourceParent!=destParent)
        {
            output[count]=CurrentEdge;
            count++;
            parent[sourceParent]=destParent;
        }
        i++;
    }
    for(int i=0;i<n-1;i++)
    {
        cout<<output[i].sources<<"   "<<output[i].dest<<"   "<<output[i].weights<<"   "<<"\n";
    }
}
int main()
{
    int n,E;
    cout<<"Enter Total No of Vertices :";
    cin>>n;
    cout<<"Enter Total Edges :";
    cin>>E;
    Edges *input=new Edges[E];
    cout<<"Enter Values of source destination and weights of each edges";
    for(int i=0;i<E;i++)
    {
        cin>>input[i].sources>>input[i].dest>>input[i].weights;
    }
    krushkal(input,n,E);
    return 0;
}
