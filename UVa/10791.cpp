#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main()
{
    freopen("10791.txt", "r", stdin);
    long long cas=1, n, i, r;
    long long mini;
    while(cin>>n)
    {
        if(n==0)
            break;
        r=sqrt(n);
        mini=30000000000;
        for(i=1;i<=r;i++)
        {
            if(n%i==0)
            {
                if(i+n/i<mini)
                    mini=i+n/i;
            }
        }
        cout<<"Case "<<cas<<": "<<mini<<endl;
        cas++;
    }
    return 0;
}
