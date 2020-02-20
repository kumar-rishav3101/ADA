#include<iostream>
using namespace std;
int N;
int graph[20][20];

int minDist(int dist[],bool flag[])
{
    int min=1000,min_index;
    for(int v=0;v<N;v++)
    {
        if(flag[v]==false&&dist[v]<min)
        {
            min=dist[v];
            min_index=v;
        }
    }
    return min_index;
}
void printMST(int parent[])
{
    char ch = 'a';
    char ver[26];
    for(int i=0;i<26;i++,ch=ch+1)
        ver[i]=ch;
    cout<<"Edge   Weight"<<endl;
    for (int i = 1; i < N; i++)
        cout<<ver[parent[i]]<<" -> "<<ver[i]<<"     "<<graph[i][parent[i]]<<endl;
}

void Prism()
{
    int parent[N];
    int dist[N];
    bool flag[N];
    for(int i=0;i<N;i++)
    {
        dist[i]=1000;
        flag[i]=false;
    }
    dist[0]=0;
    parent[0]=-1;
    for(int c=0;c<N-1;c++)
    {
        int u = minDist(dist,flag);
        flag[u]=true;
        for(int v=0;v<N;v++)
        {
            if(flag[v]==false&&graph[u][v]&&graph[u][v]<dist[v])
             {dist[v]=graph[u][v];
                parent[v]=u;}
        }
    }

    printMST(parent);

}

int main()
{
    cout<<"Enter Total Vertices:";
    cin>>N;
    cout<<"Enter Adjacency Matrix:-";
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>graph[i][j];
        }
    }
    Prism();
    return 0;
}

