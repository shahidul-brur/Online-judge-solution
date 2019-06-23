#include <bits/stdc++.h>
using namespace std;


int main()
{
    //freopen("a.txt", "r", stdin);
    int n, min1, min2, min3, max1, max2, max3, f, s, th, rem;
    scanf("%d", &n);
    scanf("%d %d", &min1, &max1);
    scanf("%d %d", &min2, &max2);
    scanf("%d %d", &min3, &max3);
    f=min1;
    s=min2;
    th=min3;
    rem=n-(f+s+th);

    if(rem>0)
    {
        if(rem<=(max1-f))
        {
            f+=rem;
            rem=0;
        }
        else
        {
            f=max1;
            rem=rem-(max1-min1);
        }
    }
    if(rem>0)
        {
            if(rem<=(max2-s))
            {
                s+=rem;
                rem=0;
            }
            else
            {
                s=max2;
                rem=rem-(max2-min2);
            }
        }

        if(rem>0)
        {
            if(rem<=(max3-th))
            {
                th+=rem;
                rem=0;
            }
            else
            {
                th=max3;
                rem=rem-(max2-min3);
            }
        }
    printf("%d %d %d\n", f, s, th);
    return 0;
}