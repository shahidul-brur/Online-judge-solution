#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    long long n, k, i, j, sum, a[100005];
    while(cin>>n>>k)
    {
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(i=1;i<=n;i++)
        {
            sum = i*(i+1)/2;
            if(sum==k)
            {
                cout << a[i] << "\n";
                break;
            }
            else if(sum>k)
            {
                //cout << sum << " , " << i*(i-1)/2 << "-> ";
                sum = i*(i-1)/2;
                cout << a[k-sum] << "\n";
                break;
            }
        }
    }
    return 0;
}
