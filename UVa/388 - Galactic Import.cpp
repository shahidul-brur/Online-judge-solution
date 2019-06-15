#include <bits/stdc++.h>
int main()
{
    freopen("388.txt", "r", stdin);
    int n, i, j, len;
    float value, maxi;
    char planet[3], ans, line[50];
    while(scanf("%d", &n)!=EOF)
    {
        maxi=-1;
        ans='?';
        while(n--)
        {
            scanf("%s %f %s", planet, &value, line);
            len=strlen(line);
            for(i=0;i<len;i++)
            {
                if(line[i]=='*')
                {
                    if(value>maxi)
                        ans=planet[0];
                    break;
                }
            }
        }
        printf("Import from %c\n", ans);
    }
    return 0;
}
