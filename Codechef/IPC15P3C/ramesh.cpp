#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int a, b, i, len, cut, test, j, k;
    char s[100005], t[100005];
    cin>>test;
    while(test--)
    {
        cin>>s>>a>>b;

        len = strlen(s);
        cut = 0;

        int imp = 0;
        cout << len <<"\n";
        for(i=0;i<len;)
        {
            cout << "i="  << i << " ....\n\n";
            if(i==len-1)
            {
                cut++;
                break;
            }
            long long n = 0;
            for(j=i;j<len;j++)
            {
                 cout << "            j = " <<  j << " ...\n";
                n = n*10 + s[j] - '0';

                if(n>b && (n/10 < a || n/10>b))
                {
                    imp = 1;
                    break;
                }
                if(n>b)
                {
                    cut++;
                    i = j;
                    break;
                }
                if(imp == 1)
                    break;
            }
        }

        if(imp==1)
            cout << "-1\n";
        else cout << cut << "\n";
    }
    return 0;
}
