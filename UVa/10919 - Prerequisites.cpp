//Accepted

#include<stdio.h>
int main()
{
    //freopen("10919.txt", "r", stdin);
    int course_taken, category, course_id[150],i,j,k,req,cnt_course,meet_req,sub_cate,re_course_id[150];
    while(scanf("%d",&course_taken)&&course_taken!=0)
    {
        scanf("%d",&category);
        for(i=1;i<=course_taken;i++)
            scanf("%d",&course_id[i]);
        meet_req=1;
        for(i=1;i<=category;i++)
        {
            scanf("%d",&sub_cate);
            scanf("%d",&req);
            for(j=1;j<=sub_cate;j++)
                scanf("%d",&re_course_id[j]);
            cnt_course=0;
            for(j=1;j<=sub_cate;j++)
            {
                for(k=1;k<=course_taken;k++)
                {
                    if(course_id[k]==re_course_id[j])
                    {
                        cnt_course++;
                        break;
                    }
                }
            }
            if(cnt_course<req)
                meet_req=0;
        }
        if(meet_req==1)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
