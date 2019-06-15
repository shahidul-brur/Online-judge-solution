#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("in.txt", "r", stdin);
    long long prod[105], ar[105], maxi, p, num;
    int n, i, j;
    while(cin>>num)
    {
        if(num==-999999)
            break;
        
        maxi = -9999999;
        
        prod[0] = 1;
        n = 1;
        if(num==0)
            prod[n]=1;
        else prod[n]=num;
        
        ar[n] = num;
        maxi = max(maxi, num);
        while(cin>>num)
        {
            if(num==-999999)
                break;
            n++;
            ar[n] = num;
            maxi = max(maxi, num);
            if(num!=0)
                prod[n] = num*prod[n-1];
            else prod[n] = 1;
        }
        
        for(i=1;i<=n;i++)
        {
            if(prod[i-1]!=0)
            {
                for(j=i;j<=n;j++)
                {
                    if(ar[j]==0)
                        break;
                    p = prod[j]/prod[i-1];
                    maxi = max(maxi, p);
                }
            }
        }
        cout << maxi << "\n";
    }
    return 0;
}
