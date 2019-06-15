//Accepted

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int lcm(int a, int b)
{
    int i, mini, gcd;
    if(a<b) mini=a;
    else mini=b;
    for(i=mini;i>=1;i--)
    {
        if(a%i==0 && b%i==0)
        {
            gcd=i;
            break;
        }
    }
    return ((a*b)/gcd);
}

int main()
{
    freopen("10905.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    char num[52][100], temp[30];
    int N, i, j, k, l, len1, len2, big, m, Lcm;
    while(scanf("%d", &N)!=EOF)
    {
        if(N==0)
            break;
        for(i=0;i<N;i++)
            scanf("%s", num[i]);
        for(i=0;i<N;i++)
        {
            for(j=0;j<N-i-1;j++)
            {
                len1=strlen(num[j]);
                len2=strlen(num[j+1]);
                Lcm=lcm(len1, len2);
                for(m=0, l=0, k=0;m<Lcm;m++, k++, l++)
                {
                    if(l>=len2)
                        l=0;
                    if(k>=len1)
                        k=0;
                    if(num[j+1][l]<num[j][k])
                        break;
                    if(num[j+1][l]>num[j][k])
                    {
                        strcpy(temp, num[j]);
                        strcpy(num[j], num[j+1]);
                        strcpy(num[j+1], temp);
                        break;
                    }
                }
            }
        }
        for(i=0;i<N;i++)
        {
            printf("%s", num[i]);
        }
        printf("\n");
    }
    return 0;
}
