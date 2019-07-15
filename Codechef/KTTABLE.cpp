#include<bits/stdc++.h>
using namespace std;
int fact(int num)
{
    int f=1;
    for(int i=1;i<=num;i++)
    {
        f=f*i;
    }
    return f;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    
    long n,t, a[10004], i, cnt, b;
    cin>>t;
    while(t-->0)
    {
        cin>>n;
        a[0]=0;
        for(i=1;i<=n;i++)
            cin>>a[i];
        cnt=0;
        for(i=1;i<=n;i++)
        {
            cin>>b;
            if(b<=a[i]-a[i-1])
                cnt++;
        }
        cout << cnt << "\n";
        
    }
    return 0;
}

