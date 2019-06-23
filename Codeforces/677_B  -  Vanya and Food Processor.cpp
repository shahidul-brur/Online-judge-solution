#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    long long a[100005], n, h, cnt, b, k, i, j, sum;
    while(cin>>n>>h>>k)
    {
        cnt = 0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sum = a[0];
        i=0;
        while(1)
        {
            while(i+1<n && sum+a[i+1]<=h)
            {
                sum+=a[i+1];
                i++;
            }
            cnt+=sum/k;
            
                
            
            sum = sum%k;
            if(i+1>=n)
            {
                if(sum>0)
                    cnt++;
                sum = 0;
                break;
            }
            
            //cout << " # "<< sum << "  "<< cnt << " "; 
            if(a[i+1]+sum>h)
            {
                cnt++;
                //cout << "+1 ";
                sum=0;
            }
            //cout << "\n";
        }
        cout << cnt << "\n";
    }
    return 0;
}

