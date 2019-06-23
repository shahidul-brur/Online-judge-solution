#include<bits/stdc++.h>
using namespace std;
int c[100005];
int s[100005], e[100005];
int tz(int  n)
{
    int c = 0;
    for (int i=5; n/i>=1; i *= 5)
          c += n/i;
    return c;
}
int main()
{
    int z = 0, nz;
    for(int i=1;z<=100000;i++)
    {
        nz = tz(i);
        if(nz==z)
            c[z]++;
        else
        {
            z = nz;
            c[z]=1;
            s[z] = i;
        }
    }
    int m, i, j;
    while(cin>>m)
    {
        cout << c[m] << "\n";
        for(i=s[m], j=1;j<=c[m];j++, i++)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
