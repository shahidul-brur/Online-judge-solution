#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int, int> >
#define pii pair<int, int>
#define all(a) a.begin(), a.end()
#define F(i, a, b) for(i=a;i<=b;i++)
#define Fr(i, b, a) for(i=b;i>=a;i--)
#define eps 1e-6
#define pi acos(-1)
#define mp make_pair
#define mem(a, b) memset(a, b, sizeof(a))

int main()
{
    //freopen("in.txt", "r", stdin);
    ll n, y=0, w[5], i, j, k, sum;
    cin>>n;
    
    for(i=0; ; i++)
    {
        sum = i*1234567;
        if(sum>n)
            break;
        for(j= 0; ;j++)
        {
            sum=i*1234567+j*123456;
            if(sum>n)
                break;
            if((n-sum)%1234==0)
            {
                y=1;
                break;
            }
        }
        if(y==1)
            break;
    }
    
    if(y==1)
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
