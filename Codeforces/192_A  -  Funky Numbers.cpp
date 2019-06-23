#include<bits/stdc++.h>
using namespace std;
//AC
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    long long n, i, k, y, m;
    while(cin>>n)
    {
        y=0;
        for(i=1;;i++)
        {
            m=n - i*(i+1)/2;
            if(m<=0)
                break;
            
            k = sqrt(1+8*m)/2 - 1;
            for(long long l=k;l<=k+1;l++)
            {
                if(l>0 && l*(l+1)/2==m)
                {
                    y=1;
                    break;
                }
                if(l*(l+1)/2>m)
                    break;
            }
            if(y==1)
                break;
        }
        if(y==1)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}





