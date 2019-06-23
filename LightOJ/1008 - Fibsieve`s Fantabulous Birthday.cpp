//Accepted

#include <stdio.h>
#include <math.h>
int main()
{
    freopen("1008.txt", "r", stdin);
    long long t, n, root, row, col, cas=1;
    scanf("%lld", &t);
    while(t--)
    {
       scanf("%lld", &n);
        root=sqrt(n);
        if(root*root == n)
        {
            if(root%2 == 0)
            {
                row=1;
                col=root;
            }
            else
            {
                row = root;
                col = 1;
            }
        }
        else
        {
            if(root%2==0)
            {
                if(n<=(root*root+root+1))
                {
                    col=root+1;
                    row=n-root*root;
                }
                else
                {
                    row=root+1;
                    col=root+1-(n-(root*root+root+1));
                }
            }
            else
            {
                if(n<=(root*root+root+1))
                {
                    row=root+1;
                    col=n-root*root;
                }
                else
                {
                    col=root+1;
                    row=root+1-(n-(root*root+root+1));
                }
            }
        }
        printf("Case %lld: %lld %lld\n", cas, col, row);
        cas++;
    }
    return 0;
}
