#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define eps 1e-10
int main()
{
    int n, r, R;
    bool y;
    while(cin>>n>>R>>r)
    {
        y = 1;
        if(r>R) y = 0;
        else if(r*2>R)
        {
            if(n>1)
                y = 0;
        }
        else
        {
            double theta = 2.0*asin(r/(double)(R-r));
            if(n*theta>2.0*pi+eps)
                y = 0;
        }
        if(y)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

