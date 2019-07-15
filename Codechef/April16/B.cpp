#include<bits/stdc++.h>
using namespace std;

int main()
{
    int rgb[5], k, t, cnt;
    cin>>t;
    while(t--)
    {
        cin>>rgb[0]>>rgb[1]>>rgb[2];
        cin>>k;
        sort(rgb, rgb+3);
        if(k==1)
            cout << "1\n";
        
        else if(k<=rgb[0])
        {
            k--;
            cout << 3 + 3*(k/3) + k%3 << "\n";
        }
        else if(k<=rgb[1])
        {
            k--;
            cout << 3 + 3*(k/2) + k%2 << "\n";
        }
         else
         {
             k--;
             cout << 3 + 3*k << "\n"; 
         }
    }
    return 0;
}
