#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l, i, j, l1;
    string a, b;
    while(cin>>a>>b)
    {
        l = a.length();
        l1 = b.length();
        if(l!=l1)
        {
            cout << "NO\n";
        }
        else
        {
            bool y=1;
            for(i=0, j=l-1;i<l;i++, j--)
            {
                if(a[i]!=b[j])
                    {
                        y=0;
                        break;
                    }
            }
            if(y)
                cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
