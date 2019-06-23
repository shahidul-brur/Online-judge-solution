#include<bits/stdc++.h>
using namespace std;

int main()
{
   //freopen("in.txt", "r", stdin);
   int a, b, c, rem, i, y;
   while(cin>>a>>b>>c)
    {
        if(c%a==0 || c%b==0)
        cout << "Yes\n";
    else if((a+b)<=c && c%(a+b)==0)
        cout << "Yes\n";
    else
    {
        y = 0;
        for(i=a;i<=c;i+=a)
            if((c - i)%b==0)
        {
            y = 1;
            break;
        }
        if(y==0)
        {
            for(i=b;i<=c;i+=b)
                if((c - i)%b==0)
                {
                    y = 1;
                    break;
                }
        }
        if(y==1)
            cout << "Yes\n";
        else cout << "No\n";
    }
}

    return 0;
}
