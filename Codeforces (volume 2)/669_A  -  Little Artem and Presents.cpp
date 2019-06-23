#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdin);
    int n;
    while(cin>>n)
    {
        int g = n/3;
    g*=2;
    if(n%3>0)
        g++;
    cout << g<< "\n";
    }
    return 0;
}
