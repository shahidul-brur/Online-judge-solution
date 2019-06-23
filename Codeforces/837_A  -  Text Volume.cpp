#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    char s[300];
    cin>>n;
    getchar();
    gets(s);
    int mx = 0, cur = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i]==' ') cur = 0;
        else if(isupper(s[i])) cur++;
        mx = max(cur, mx);
    }
    
        cout << mx << "\n";
    return 0;
}
