#include<bits/stdc++.h>
using namespace std;
string s, s1;
int n, n1;
bool isSub(int p)
{
    int y = 0, m=0;
    for(int i=p, j=0;j<n1 && i<n;i++, j++)
    {
        if(s[i]!=s1[j])
            return 0;
        else m++;
    }
    if(m==n1)
        return 1;
    else return 0;
}
int main()
{
    int i, j, cnt = 0;
    cin>>s;
    cin>>s1;
    n = s.size();
    n1 = s1.size();
    for(i=0;i<n;i++)
    {
        if(isSub(i))
        {
            cnt++;
            i = i+n1-1;
        }
    }
    cout << cnt << "\n";
   return 0;
}

