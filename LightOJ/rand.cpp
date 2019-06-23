/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul.brur        |
|                                   |
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    freopen("in.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, q, i, j, l, r, n;
    t = rand()%5+1;
    cout << t << "\n";
    while(t--)
    {
        n = rand()%100+1;
        q = rand()%5000+1;
        cout << n << " " << q << "\n";
        for(i=1;i<=n;i++)
        {
            int v = rand()%1000000;
            cout << v << " ";
        }
        cout << "\n";
        while(q--)
        {
            int typ, p, val;
            typ = rand()%3+1;
            cout << typ << " ";
            if(typ==1)
            {
                p = rand()%n;
                cout << p << "\n";
            }
            else if(typ==2)
            {
                p = rand()%n;
                val = rand()%1000000;
                cout << p << " " << val << "\n";
            }
            else
            {
                l = rand()%n;
                r = rand()%n;
                if(l>r)
                    swap(l, r);
                cout << l << " " << r << "\n";
            }
        }
    }
    return 0;
}

