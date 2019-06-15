#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    long long x, k, p, q, a, b, t;
    cin>>t;
    while(t--)
    {
        cin>>x>>k;
        b = x/k;
        if(k*b<x)
            b++;
        a = x/k;
        q = x/b;
        if(b*q>x)
            q--;
        p = (x-b*q)/a;
        cout << p << " " << q << "\n";
    }
    return 0;
}


