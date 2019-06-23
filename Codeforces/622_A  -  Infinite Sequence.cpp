#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, p, v, i;
    while(cin>>n)
    {
        p = (sqrt(8*n + 1) - 1)/2;
        for(p=p-1;;p++)
        {
            if(p*(p+1)/2>=n)
            {
                cout << n- p*(p-1)/2<< "\n";
                break;
            }
        }
    }
    return 0;
}
