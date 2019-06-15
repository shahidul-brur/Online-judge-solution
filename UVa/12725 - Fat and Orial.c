//Accepted
#include<stdio.h>
#define eps 1e-9

int main()
{
    //freopen("in.txt", "r", stdin);
    double current, n, target, m, next;
    int test, cas=1;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%lf %lf %lf %lf", &current, &target, &n, &m);
        next = (double)(target*(m+n) - (n*current))/m;
       if(next > 10.0 + eps || next+eps < 0.0)
            printf("Case #%d: Impossible\n", cas);
        else 
            printf("Case #%d: %.2lf\n", cas, next);
        cas++;
    }
    return 0;
}