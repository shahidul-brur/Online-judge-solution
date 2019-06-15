//Accepted

#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
int path[12][12];
void printPath(int i, int j)
{
    if (i != j) printPath(i, path[i][j]);
    printf(" %d", j);
}
int main()
{
    freopen("in.txt", "r", stdin);
    int N, i, j, k, delay[12][12], connection, node, time, cas=1, from, to;
    while(cin>>N)
    {
        if(N==0)
            break;
        for(i=1;i<=N;i++)
            for(j=1;j<=N;j++)
                delay[i][j]=INF;
        
        for(i=1;i<=N;i++)
        {
            cin>>connection;
            for(j=1;j<=connection;j++)
            {
                cin>>node>>time;
                delay[i][node]=time;
            }
        }
        cin>>from>>to;
        for(i=1;i<=N;i++)
            for(j=1;j<=N;j++)
                path[i][j]=i;
        for(k=1;k<=N;k++)
            for(i=1;i<=N;i++)
                for(j=1;j<=N;j++)
                    if(delay[i][k] + delay[k][j]<delay[i][j])
                    {
                        delay[i][j]=delay[i][k] + delay[k][j];
                        path[i][j]=path[k][j];
                    }
        cout<<"Case "<<cas<<": Path =";
        printPath(from, to);
        cout<<"; "<<delay[from][to]<<" second delay"<< "\n";
        cas++;
    }
    return 0;
}