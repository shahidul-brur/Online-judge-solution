#include<bits/stdc++.h>
using namespace std;
#define MX 100002
int a[MX], lef[MX], rgt[MX];
int main()
{
//    freopen("in.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int m, s;
    while(cin>>m>>s)
    {
        if(s==0 && m==1)
        {
            cout << "0 0\n";
            continue;
        }
        
        if((s==0 && m>1) || s>9*m)
        {
            cout << "-1 -1\n";
            continue;
        }
        char n1[110], n2[110];
        for(int i = 0;i<m;i++)
            n1[i] = n2[i] = '0';
        n1[m] = n2[m] = '\0';
        int k = s-1;
        int  i = m-1;
        n1[0] = '1';
        while(k>0)
        {
            if(k>=9)
            {
                n1[i] += 9;
                k-=9;
            }
            else 
            {
                n1[i] += k;
                k = 0;
            }
            i--;
        }
        i = 1;
        k = s;
        if(s>=9)
        {
            n2[0] = '9';
            k-=9;
        }
        else
        {
            n2[0] = s+'0';
            k=0;
        }
        while(k>0)
        {
            if(k>=9)
            {
                n2[i] = '9';
                k-=9;
            }
            else 
            {
                n2[i] = k + '0';
                k = 0;
            }
            i++;
        }
        cout << n1 << " " << n2 << "\n";
    }
    return 0;
}

