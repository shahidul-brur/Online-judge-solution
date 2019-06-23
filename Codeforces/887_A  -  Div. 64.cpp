#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int l;
    while(cin>>s)
    {
        l = s.length();
        int z = 0;
        for(int i = l-1;i>=0;i--)
        {
            if(s[i]=='0')
                z++;
            if(z==6)
            {
                int o = 0;
                for(int j = i-1;j>=0;j--)
                {
                    if(s[j]=='1')
                    {
                        o = 1;
                        break;
                    }
                }
                if(o==1)
                {
                    cout << "yes\n";
                    return 0;
                }
                break;
            }
        }
        cout << "no\n";
    }
    return 0;
}
