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

void Dijkstra(int src)
{
    int dist[N];
    bool flag[N];
    for(int i=0;i<N;i++)
    {
        dist[i]=1000;
        flag[i]=false;
    }
    dist[src]=0;
    for(int c=0;c<N-1;c++)
    {
        int u = minDist(dist,flag);
        flag[u]=true;
        for(int v=0;v<N;v++)
        {
            if(!flag[v]&&graph[u][v]&&dist[u]!=1000&&dist[u]+graph[u][v]<dist[v])
                dist[v]=dist[u]+graph[u][v];

        }
    }

    for(int i=0;i<N;i++)
    {
        cout<<i<<"        "<<dist[i];
    }

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
    int src;
    cout<<"Enter Source:";
    cin>>src;
    Dijkstra(src);
    return 0;
}
