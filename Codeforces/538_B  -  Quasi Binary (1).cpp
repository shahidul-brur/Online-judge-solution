#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int i;
    while(cin>>s)
    {
        int l = s.length();
        int mx = 0;
        for(i=0;i<l;i++)
        {
            int d = s[i] - '0';
            mx = max(mx, d);
        }
        cout << mx << "\n";
        vector<int> v;
        while(1)
        {
            int n = 0;
            for(i=0;i<l;i++)
            {
                n = n*10;
                if(s[i]>'0')
                {
                    n+=1;
                    s[i]--;
                }
            }
            if(n==0)
                break;
            v.push_back(n);
        }
        for(int i=0;i<mx;i++)
            cout << v[i] << " ";
        cout << "\n";
    }
    return 0;
}

