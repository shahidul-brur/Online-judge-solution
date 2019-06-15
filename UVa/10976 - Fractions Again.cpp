//Accepted
//10976 - Fractions Again

#include <iostream>

using namespace std;

int main()
{
    int k, x, y, sol, yList[10000];
    while(cin>>k)
    {
        sol=0;
        for(y=k+1;y<=2*k;y++)
        {
            x=(k*y)/(y-k);
            if(x*(y-k)==k*y)
                yList[sol++]=y;
        }
        cout<<sol<<endl;
        for(x=0;x<sol;x++)
            cout<<"1/"<<k<<" = 1/"<<(k*yList[x])/(yList[x]-k)<<" + 1/"<<yList[x]<<endl;
    }
    return 0;
}
