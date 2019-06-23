#include <bits/stdc++.h>
using namespace std;

int main()
{
    //fast;
    //in;
    //out;
    int n;
    cin>>n;
    int s = n/5;
    n%=5;
    s+=n/4;
    n%=4;
    s+=n/3;
    n%=3;
    s+=n/2;
    n%=2;
    s+=n/1;
    cout << s;
    return 0;
}