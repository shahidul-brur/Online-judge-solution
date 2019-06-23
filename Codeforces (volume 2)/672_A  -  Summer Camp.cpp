#include<bits/stdc++.h>
using namespace std;
char s1[10005];
int len=0;
void inS(int n)
{
    int i=0;
    char s[10005];
    while(n>0)
    {
        int r = n%10;
        s[i++] = char(r + '0');
        n=n/10;
    }
    s[i] = '\0';
    //cout << " # " << s << "\n";
    len = strlen(s1);
    for(int j=i-1;j>=0;j--)
        s1[len++] = s[j];
    s1[len] = '\0';
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, i;
    while(cin>>n)
    {
        len = 0;
        for(i=1;strlen(s1)<=n;i++)
        {
            inS(i);
        }
        cout << s1[n-1] << "\n";
    }
    return 0;
}
