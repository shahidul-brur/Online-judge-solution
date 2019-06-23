/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul2009         |
|                                   |
\*=================================*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    ll a[10], t1, t2;
    cin>>a[2]>>a[3]>>a[5]>>a[6];
    t1 = min(a[2], min(a[5], a[6]));
    a[2]-=t1;
    t2 = min(a[2], a[3]);
    ll sum = t1*256 + 32*t2;
    cout << sum << "\n";
    
    return 0;
}
