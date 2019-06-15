//Accepted

#include <stdio.h>

int main()
{
    freopen("11309.txt", "r", stdin);
    int t, H, M, h, m, i, ans, pal, temp;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d:%d", &H, &M);
        h=H;
        m=M+1;
        if(m==60)
        {
            m=0;
            h++;
            if(h==24)
                h=0;
        }
        ans=h*100+m;
        temp=ans;
        pal=0;
        while(temp>0)
        {
            pal = pal*10 + temp%10;
            temp/=10;
        }
        while(pal!=ans)
        {
            m++;
            if(m==60)
            {
                m=0;
                h++;
                if(h==24)
                    h=0;
            }
            ans=h*100+m;
            temp=ans;
            pal=0;
            while(temp>0)
            {
                pal = pal*10 + temp%10;
                temp/=10;
            }
        }
        printf("%02d:%02d\n",h, m);
    }
    return 0;
}
