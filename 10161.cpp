//Accepted

#include <stdio.h>
#include <math.h>
int main()
{
    //freopen("10161in.txt", "r", stdin);
    int n, root, row, col;
    while(scanf("%d", &n)!=EOF)
    {
        if(n==0)
            break;
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
        printf("%d %d\n", col, row);
    }
    return 0;
}
