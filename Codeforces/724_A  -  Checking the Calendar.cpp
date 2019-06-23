#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    map<string, int> m;
    m["monday"] = 1;
    m["tuesday"] = 2;
    m["wednesday"] = 3;
    m["thursday"] = 4;
    m["friday"] = 5;
    m["saturday"] = 6;
    m["sunday"] = 7;
    string a, b;
    while(cin>>a>>b)
    {
        int x = m[a];
        int y = m[b];

        int i, j;
        bool yes=0;
        for(i=2;i<=32;i++)
        {
            x++;
            if(x>7)
                x=1;
            if((i==29 || i==31 || i==32) && x==y)
            {
                yes=1;
                break;
            }
        }
        if(yes)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
