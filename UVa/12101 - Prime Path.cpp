/**********************************************************
Status:     Accepted
Problem:    UVa : 11730 - Number Transformation
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
Date created: 27 - 07 - 2015
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
#define infinity 1000000
int prime[10003], start, target, visited[10003], found, step[10003], d[5];
void generatePrime(int N)
{
    int i, j, cnt=0;
    memset(prime, 0, sizeof(prime));
    prime[0]=1;
    prime[1]=1;
    for(i=4;i<=N;i+=2)
        prime[i]=1;
    for(i=3;i<=N/i;i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*2;j<=N;j+=i)
                prime[j]=1;
        }
    }
}
void bfs()
{
    queue<int> q;
    found=0;
    q.push(start);
    visited[start]=1;
    step[start]=0;
    while(!q.empty())
    {
        int number=q.front();
        
        q.pop();
        d[0]=d[1]=d[2]=d[3]=0;
        int i=0;
        int s = number;
        while(s>0)
        {
            d[i++] = s%10;
            s/=10;
        }
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<=9;j++)
            {
                int d1[6];
                d1[0] = d[0];
                d1[1] = d[1];
                d1[2] = d[2];
                d1[3] = d[3];
                d1[i] = j;
                int nxt = d1[0] + d1[1]*10 + d1[2]*100 + d1[3]*1000;
                if(nxt>=1000 && prime[nxt]==0 && visited[nxt]==0)
                {
                    visited[nxt]=1;
                    step[nxt]=step[number]+1;
                    if(nxt==target)
                    {
                        found=1;
                        break;
                    }
                    else
                        q.push(nxt);
                }
            }
        }
        if(found==1)
            break;
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int cas, test;
    cin>>test;
    generatePrime(10000);
    for(cas=1;cas<=test;cas++)
    {
        scanf("%d %d", &start, &target);
        memset(visited, 0, sizeof(visited));
        memset(step, 0, sizeof(step));
        if(start==target)
            printf("0\n");
        else
        {
            bfs();
            if(step[target]==0)
                printf("Impossible\n", cas);
            else printf("%d\n", step[target]);
        }
    }
    return 0;
}
