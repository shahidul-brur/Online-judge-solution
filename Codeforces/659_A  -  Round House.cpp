#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int n, a, b, p, i;
    while(cin>>n>>a>>b)
    {
        if(b>=0)
        {
            for(p=a, i=1;i<=b;i++)
            {
                p++;
                if(p>n)
                    p=1;
            }
        }
        else
        {
            b=-b;
            for(p=a, i=1;i<=b;i++)
            {
                p--;
                if(p<1)
                    p=n;
            }
        }
        cout << p << "\n";
    }
    return 0;
}
