#include<bits/stdc++.h>
using namespace std;
bool L[100002], R[100002];
int main()
{
    //freopen("12715.txt", "r", stdin);
    long int  x,t,i,j,c,n, m,from, to,p,max,cv;
    scanf("%ld",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%ld %ld",&n,&m);
        memset(L, false, sizeof(L));
        memset(R, false, sizeof(R));
        for(i=0;i<n;i++)
        {
            scanf("%ld %ld",&from,&to);
            L[from]=true;
            R[to]=true;
        }
        printf("Case %ld:\n",c);
        for(j=0;j<m;j++)
        {
            scanf("%ld",&p);
            max=0;
            for(i=0;i<n;i++)
            {
                if(p<L[i] && p>R[i])
                    cv=0;
                else
                {
                    if((p-L[i])<(R[i]-p))
                        cv=p-L[i];
                    else cv=R[i]-p;
                }
                if(cv>max)
                    max=cv;
            }
            printf("%ld\n",max);
        }
    }
    return 0;
}
