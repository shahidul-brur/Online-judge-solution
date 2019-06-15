#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<stdlib.h>
#include<ctype.h>
#include<map>
#include<iomanip>
#define r 6371.01
#define pi 3.141592653589
#define PI acos(0.0)
#define EPS 1e-7

using namespace std;
int main()
{
    long int n,i,k=1,count,move,avg;
    long int a[1000];
    while(scanf("%ld",&n)==1)
    {
        if(n==0)
            break;
        count=0;
        move=0;
        avg=0;
        for(i=0;i<n;i++)
        {
            scanf("%ld",&a[i]);
            count=count+a[i];
        }
        if(count%n==0)
        {
            avg=(count/n);
            for(i=0;i<n;i++)
            {
                if(avg<a[i]||avg>a[i])
                  move++;
            }
        }
        printf("Set #%ld\n",k++);
        printf("The minimum number of moves is %ld.\n",move);
    }
    return 0;
}
