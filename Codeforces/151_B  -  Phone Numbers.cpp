#include<bits/stdc++.h>
using namespace std;
// 1 = taxi, 2 = pizza, 3 = girl
int taxi[110], girl[110], pizza[110];
string name[110];
int type(string s)
{
    int l = s.length();
    if(s[0]==s[1] && s[1]==s[3] && s[3]==s[4] && s[4]==s[6] && s[6]==s[7])
        return 1;
    if(s[0]>s[1] && s[1]>s[3] && s[3]>s[4] && s[4]>s[6] && s[6]>s[7])
        return 2;
    return 3;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;

    while(cin>>n)
    {
        int t, g, p;
        t = g = p = 0;
        for(int i = 1;i<=n;i++)
        {
            int k;
            cin>>k>>name[i];
            for(int j = 1;j<=k;j++)
            {
                string s;
                cin>>s;
                int typ = type(s);
                if(typ==1)
                    taxi[i]++;
                else if(typ==2)
                    pizza[i]++;
                else girl[i]++;
                t = max(t, taxi[i]);
                p = max(p, pizza[i]);
                g = max(g, girl[i]);
            }
        }
        cout << "If you want to call a taxi, you should call: ";
        int cnt = 0;
        for(int i = 1;i<=n;i++)
        {
            if(taxi[i]==t)
            {
                if(cnt>0)
                cout << ", ";
                cout << name[i];
                cnt++;
            }
        }
        cout << ".\n";
        cout << "If you want to order a pizza, you should call: ";
        cnt = 0;
        for(int i = 1;i<=n;i++)
        {

            if(pizza[i]==p)
            {
                if(cnt>0)
                cout << ", ";
                cout << name[i];
                cnt++;
            }
        }
        cout << ".\n";
        cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
        cnt = 0;
        for(int i = 1;i<=n;i++)
        {

            if(girl[i]==g)
            {
                if(cnt>0)
                cout << ", ";
                cout << name[i];
                cnt++;
            }
        }
        cout << ".\n";
    }
    return 0;
}