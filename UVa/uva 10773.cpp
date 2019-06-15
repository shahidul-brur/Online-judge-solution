#include<bits/stdc++.h>
using namespace std;
#define eps 1e-6

int main()
{
    int t, cas;
    double d, v, u, t1, t2;
    cin>>t;
    for(cas=1;cas<=t;cas++)
    {
        cin>>d>>v>>u;
        if(u+eps<v || u==0 || v==0 || fabs(u-v)<eps)
        {
            cout << "Case "<<cas<<": can't determine\n";
        }
        else
        {
            t1 = d/u;
            t2 = d/(sqrt(u*u-v*v));
            cout <<  "Case " << cas << ": ";
            cout << fixed << setprecision(3) << fabs(t1-t2) << "\n";
        }
    }
    return 0;
}
