#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int a, i, total, t;
    cin>>t;
    while(t-->0)
    {
        cin>>a;
        int y=0;
        for(i=3;;i++)
        {
            total = (i-2)*180;
            if(total==(a*i))
            {
                y=1;
                //cout << " # " << i << "\n";
                break;
            }
            else if(total>i*a)
                break;
        }
        if(y==0)
            cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
