#include<stdio.h>
int main()
{
    int n, note, i, one;
    scanf("%d", &n);
    one=0;
    for(i=1;i<=n;i++)
     {
             scanf("%d", &note);
             if(note==1)
             one=1;
     }
     if(one==1)
             printf("-1\n");
     else  printf("1\n");
     return 0;
}