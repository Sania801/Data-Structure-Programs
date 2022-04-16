#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
int  dijkstra(int cost[6][6],int dist[6],bool visit[6]);
int most_min(int dist[6],bool visit[6]);
int print_solution(int dist[6]);
int main()
{
    int cost[6][6]={
        {0,50,45,10,INT_MAX,INT_MAX},
        {INT_MAX,0,10,15,INT_MAX,INT_MAX},
        {INT_MAX,INT_MAX,0,INT_MAX,30,INT_MAX},
        {10,INT_MAX,INT_MAX,0,15,INT_MAX},
        {INT_MAX,20,35,INT_MAX,0,INT_MAX},
        {INT_MAX,INT_MAX,INT_MAX,INT_MAX,3,0}};
        int dist[6];
        bool visit[6];
        //int j=1;
        dijkstra(cost,dist,visit);
        //return 0;
}
int dijkstra(int cost[6][6],int dist[6],bool visit[6])
{
    int i,j,t,m,f;
    //bool visit[10];
    for(i=0;i<6;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[0]=0;
    for(j=0;j<6;j++)
    {
        visit[j]=false;

    }
    for(t=0;t<6;t++)
    {
        m=most_min(dist,visit);
        visit[m]=true;
        for(f=0;f<6;f++)
        {
            if(!visit[f] && cost[m][f]!=INT_MAX && cost[m][f]!=0 && cost[m][f]+ dist[m]<dist[f])
            {
                dist[f]=cost[m][f]+ dist[m];
            }
        }
    }
     print_solution(dist);
}
int most_min(int dist[6],bool visit[6])
{
    int minimum=INT_MAX;
    int l,ind;
    for(l=0;l<6;l++)
    {
        if(visit[l]==false &&  dist[l]<=minimum)
        {
            minimum=dist[l];
            ind=l;
        }
    }
    return ind;
}
int print_solution(int dist[6])
{
    int g=1,i;
    printf("\n The array which stores the final shortest path is as follows:");
    for(i=0;i<6;i++)
    {
        printf("\n%d:%d",g,dist[i]);
        g++;
    }
}
