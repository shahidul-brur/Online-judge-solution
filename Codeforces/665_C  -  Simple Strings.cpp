#include<bits/stdc++.h>

using namespace std;

int main()
{
    char s[2000005];
    int l, i;
    cin>>s;
    l = strlen(s);
    cout << s[0];
    for(i=1;i<l;i++)
    {
        if(s[i]==s[i-1])
        {
            for(char c = 'a';c<='z';c++)
            {
                if(c!=s[i] && c!=s[i+1])
                {
                    s[i] = c;
                    break;
                }
            }
        }
        cout << s[i];
    }
    return 0;
}
