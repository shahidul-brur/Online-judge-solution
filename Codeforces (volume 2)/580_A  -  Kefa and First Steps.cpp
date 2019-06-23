#include <bits/stdc++.h>
using namespace std;
#define maxi 100002
int main()
{
    //freopen("in.txt", "r", stdin);
    int i, j, n, a[100002], mx, siz;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    mx=0;
    for(i=0;i<n;)
    {
        siz = 1;
        for(j=i+1;j<n;j++)
        {
            if(a[j]>=a[j-1])
                siz++;
            else break;
        }
        if(siz>mx)
        {
            mx=siz;
        }
        i=j;
    }
    cout << mx << "\n";
    return 0;
}
