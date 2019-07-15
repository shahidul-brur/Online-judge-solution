#include<bits/stdc++.h>
using namespace std;

int main()
{
   int jack, m, cost;
   cin>>jack>>cost>>m;
   m-=jack;
    if(m<=0)
        cout << "Lucky Chef\n";
    else
    {
        if(m/cost % 2==0)
            cout << "Lucky Chef\n";
        else cout << "Unlucky Chef\n";
    }
   return 0;
}
