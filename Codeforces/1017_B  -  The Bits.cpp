#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    while(cin>>n)
    {

        string a,b;
        cin>>a>>b;
        int z=0,o=0;
        long long int cnt = 0;
        for(int i = 0; i<n; i++)
        {
            if(b[i]=='0')
            {
                if(a[i]=='0')
                    cnt+=o;
                else
                    cnt+=z;
            }
            else
            {
                if(a[i]=='0')
                    z++;
                else
                    o++;
            }
        }
        z=0,o=0;
        for(int i = n-1; i>=0; i--)
        {
            if(b[i]=='0')
            {
                if(a[i]=='0')
                    cnt+=o;
                else
                    cnt+=z;
            }
            if(a[i]=='0')
                z++;
            else
                o++;
        }
        cout << cnt << "\n";
    }
    return 0;
}

