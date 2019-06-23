#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
#define maxi(a, b) ((a)>(b) ? (a):(b))
#define mini(a, b) ((a)<(b) ? (a):(b))
#define sqr(a) ((a)*(a))
bool isPrime(int n)
{
    if(n<2)
        return 0;
    if(n==2)
        return 1;
    if(n%2==0)
        return 0;
        int r=sqrt(n);
    for(int i=3;i<=r;i+=2)
        if(n%i==0)
        return 0;
    return 1;
}
int main()
{
    /***** for faster input output ********/
       ios_base::sync_with_stdio(false);
    /***** *********************** ********/
    int n, a, b, i;
    cin>>n;
    for(i=4;i<=n/2;i++)
    {
        if(!isPrime(i) && !isPrime(n-i))
        {
            cout<<i<<" "<< n-i<<"\n";
            break;
        }
    }
    return 0;
}
