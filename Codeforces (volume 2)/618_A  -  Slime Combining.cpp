#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{

    int n, k, i;
    while(cin>>n)
    {
        a[0] = 1;
        k=1;
        n--;
        while(n>0)
        {
            a[k]++;
            n--;
            if(a[k]==a[k-1])
            {
                //cout << "  " << k  << " " << a[k] << "\n";
                for(i=k;i>=1;i--)
                {
                    if(a[i]==a[i-1])
                    {
                        a[i-1]++;
                        a[i]=0;
                        k=i;
                    }
                    else
                    {
                        if(a[i]==0)
                            k=i;
                        else
                            k=i+1;
                        break;
                    }
                }
            }
            else
                k++;
        }
        for(i=0;i<=k;i++)
            if(a[i]>0)
                cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}
