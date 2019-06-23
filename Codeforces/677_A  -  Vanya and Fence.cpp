#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    long long a[1005], n, h, cnt, b;
    while(cin>>n>>h)
    {
        cnt = 0;
        for(int i=0;i<n;i++)
        {
            cin>>b;
            if(b>h)
                cnt+=2;
            else cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}
