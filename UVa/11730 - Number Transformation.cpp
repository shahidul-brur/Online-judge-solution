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
int prime[1003], primeList[1003], start, target, visited[1003], found, step[1003];
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
    for(i=2;i<=N;i++)
        if(prime[i]==0)
            primeList[cnt++]=i;
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
        for(int i=0;primeList[i]<number;i++)
        {
            if(number%primeList[i]==0 && number+primeList[i]<=target && visited[number+primeList[i]]==0)
            {
                visited[number+primeList[i]]=1;
                step[number+primeList[i]]=step[number]+1;
                if(number+primeList[i]==target)
                {
                    found=1;
                    break;
                }
                else
                    q.push(number+primeList[i]);
            }
        }
        if(found==1)
            break;
    }
}
int main()
{
    //freopen("11730.txt", "r", stdin);
    int cas=1;
    generatePrime(1000);
    while(scanf("%d %d", &start, &target)!=EOF);
    {
        if(start == 0 && target==0)
            break;
        memset(visited, 0, sizeof(visited));
        memset(step, 0, sizeof(step));
        if(start==target)
            printf("Case %d: 0\n", cas);
        else
        {
            bfs();
            if(step[target]==0)
                printf("Case %d: -1\n", cas);
            else printf("Case %d: %d\n", cas, step[target]);
        }
    }
    return 0;
}
/**********************************************************
About this problem:



************************************************************/
