#include<bits/stdc++.h>
using namespace std;
#define inf 1e-6
int sqr(int x)
{
    return (x)*(x);
}
int main()
{
    int x[5], y[5], side[5];
    int i, j, t, id;
    cin>>id;
    cin>>t;
    while(t--)
    {
        for(i=0;i<3;i++)
        {
            cin>>x[i]>>y[i];
        }

        side[0] = sqr(x[0] - x[1]) + sqr(y[0]-y[1]);
        side[1] = sqr(x[2] - x[1]) + sqr(y[2]-y[1]);
        side[2] = sqr(x[0] - x[2]) + sqr(y[0]-y[2]);

        if(side[0]!=side[1] && side[1]!=side[2] && side[2]!=side[0])
            cout << "Scalene";
        else cout << "Isosceles";

        if(id==2)
        {
            if(side[0] == side[1]+side[2]  || side[1] == side[0]+side[2] || side[2] == side[1]+side[0])
                cout << " right";
            else if(side[0] > side[1]+side[2]  || side[1] > side[0]+side[2] || side[2] > side[1]+side[0])
                cout << " obtuse";
            else cout << " acute";
        }
        cout << " triangle\n";

    }
}
