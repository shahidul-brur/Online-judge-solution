#include <stdio.h
int main()
{
    int s, r, i, j, con, single_start[102], single_end[102], rep_start[102], rep_end[102], rep_inter[102];
    while(scanf("%d %d", &s, &r)!=EOF)
    {
        for(i=1;i<=s;i++)
            scanf("%d %d", &single_start[i], &single_end[i]);

        for(i=1;i<=r;i++)
            scanf("%d %d %d", &rep_start[i], &rep_end[i], &rep_inter);


    }
    return 0;
}
