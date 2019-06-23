#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, i, cnt=0, m, sum;
    cin>>n;
    for(i=0;i<n;i++)
    {
        
        cin>>m;
        a[m] = 1;
    }
    sum = 0;
    int h = 0;
    for(i=1;i<=90;i++)
    {
        if(a[i]==0)
        {
            sum++;
            if(sum>=15)
            {
                cout << i << "\n";
                h=1;
                break;
            }
        }
        else
            sum = 0;
    }
    if(h==0)
        cout << "90\n";
    return 0;
}
