#include<bits/stdc++.h>
using namespace std;
const long long mx = 10000001;

int main()
{
    long long n;
    while(cin>>n)
    {
        long long p1=0, p2=0;
        long long n1 = n;
        long long cnt = 0;
        for(long long i = 2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                while(n%i==0)
                {
                    cnt++;
                    if(p1==0)
                        p1 = i;
                    else if(p2==0)
                        p2 = i;
                    n/=i;
                    if(cnt>2)
                        break;
                }
            }
        }
        if(n!=1)
        {
            cnt++;
            if(p1==0)
                p1 = n;
            else if(p2==0)
                p2 = n;
        }
        if(cnt<=1)
            cout << "1\n0\n";
        else if(cnt==2)
            cout << "2\n";
        else 
        {
            if(p2==0) p2 = p1;
            cout << 1 << "\n" << p1*p2 << "\n";
        }
    }
    return 0;
}
