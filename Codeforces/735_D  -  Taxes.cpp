/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|        Dept. of CSE,              |
|    Begum Rokeya University,       |
|      Rangpur, Bangladesh          |
|                                   |
| mail: shahidul.cse.brur@gmail.com |
|                                   |
| FB  : fb.com/shahidul.brur        |
|                                   |
| Blog: shahidul-brur.blogspot.com  |
|                                   |
\*=================================*/
//solution of CF 735D/736B
//Category: Number Theory

#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    for(int i=2;i<=n/i;i++)
        if(n%i==0)
            return 0;
    return 1;
}
int main()
{
    int n;
    cin>>n;
    if(n==2)
        cout << "1\n";
    else if(n%2==0)
        cout << "2\n";
    else if(isPrime(n))
        cout << "1\n";
    else if(isPrime(n-2))
        cout << "2\n";
    else cout << "3\n";
    
    return 0;
}



