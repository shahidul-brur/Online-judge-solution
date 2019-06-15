//Accepted

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    freopen("12455.txt", "r", stdin);
    int i, j, sum, t, n, desire, length[21];
    cin>>t;
    while(t--)
    {
        cin>>desire;
        cin>>n;
        for(i=0;i<n;i++)
            cin>>length[i];
        for(i=0;i<(1<<n) ;i++)
        {
            sum=0;
            for(j=0;j<n;j++)
            {
                if(i & (1<<j))
                    sum+=length[j];
            }
            if(sum==desire)
                break;
        }
        if(sum==desire)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
