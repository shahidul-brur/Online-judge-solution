//Accepted

#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    long long a[20005], mx, sum;
    int i, from, to, route, stop, cas;
    cin>>route;
    for(cas=1;cas<=route;cas++)
    {
        cin>>stop;
        for(i=1;i<stop;i++)
        {
            cin>>a[i];
        }

        sum = mx = -10000000000;
        int f, t;
        to = 0, from = 0;
        for(i=1;i<stop;i++)
        {
            if(sum<0)
            {
                sum = a[i];
                f = i;
            }
            else sum+=a[i];

            if(sum>mx || (sum==mx && i+1 - f > to - from))
            {
                mx = sum;
                from = f;
                to = i+1;
            }
        }
        if(mx < 0)
            cout << "Route " << cas << " has no nice parts\n";
        else
            cout << "The nicest part of route " << cas << " is between stops " << from <<" and " << to << "\n";
    }
    return 0;
}
