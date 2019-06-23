#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
#define maxi(a, b) ((a)>(b) ? (a):(b))
#define mini(a, b) ((a)<(b) ? (a):(b))
#define sqr(a) ((a)*(a))
int main()
{
    //freopen("in.txt", "r", stdin);
    int stick[8], used[8], leg, body;
    for(int i=0;i<6;i++)
        scanf("%d ", &stick[i]);
    for(int i=0;i<6;i++)
        used[i]=0;
    for(int i=0;i<6;i++)
    {
        leg=0;
        for(int j=i;j<6;j++)
        {
            if(stick[j]==stick[i])
            {
                leg++;
                used[j]=1;
            }
            if(leg==4)
                break;
        }
        if(leg==4)
            break;
        for(int j=0;j<6;j++)
            used[j]=0;
    }

    for(int i=0;i<6;i++)
    {
        body=0;
        if(used[i]==0)
        {
            for(int j=i;j<6;j++)
            {
                if(stick[j]==stick[i] && used[j]==0)
                {
                    body++;
                }
                if(body==2)
                    break;
            }
        }
        if(body==2)
            break;
    }
    if(leg!=4)
        printf("Alien\n");
    else if(leg==4 && body==2)
        printf("Elephant\n");
    else printf("Bear\n");
    return 0;
}
