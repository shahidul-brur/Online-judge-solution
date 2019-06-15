#include<bits/stdc++.h>
using namespace std;
string nextStr(string s)
{
    int siz = s.size();
    char str[15];
    int j=0;
    for(int i=siz-1;i>=0;i--)
    {
        str[j++]= s[i];
    }
    str[j]='\0';
    for(int i=0;i<=siz;i++)
    {
        if(i==siz)
        {
            str[i] = 'a';
            str[i+1] = '\0';
            break;
        }
        else if(str[i]<'z')
        {
            str[i] = (char)(str[i] + 1);
            break;
        }
        else if(str[i]=='z')
            str[i]='a';
    }
    char newS[15];
    siz = strlen(str);
    for(int i=siz-1, j=0;i>=0;i--)
        newS[j++]=str[i];
    newS[j] = '\0';
    return string(newS);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int i, cnt;
    map<string, int> m;
    string s = "a";
    m[s]=1;
    cnt=2;
    while(s!="vwxyz")
    {
        s = nextStr(s);
        cout << "  # " << s << "\n";
        m[s]=cnt++;
    }
    while(cin>>s)
    {
        cout << m[s] << "\n";
    }
    return 0;
}

