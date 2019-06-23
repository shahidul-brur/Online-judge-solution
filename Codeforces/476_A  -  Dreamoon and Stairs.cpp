#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("in.txt", "r", stdin);
    int n, m, total, no;
    scanf("%d %d", &n, &m);
    if(n%2==0)
        total=n/2;
    else total=(n-1)/2+1;
    
    no=0;
    while(total%m!=0)
    {
        total++;
        if(total>n)
        {
            no=1;
            break;
        }
    }
    if(no==0)
        printf("%d\n", total);
        
    else printf("-1\n");
    return 0;
}