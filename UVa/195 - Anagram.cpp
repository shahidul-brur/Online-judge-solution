#include<bits/stdc++.h>
using namespace std;
string s;
char seq[1000005], siz;
bool take[1000005];
void print(int i)
{
    if(i==siz)
    {
        seq[i] = '\0';
        cout << seq << "\n";
        return;
    }
    for(int j=0;j<siz;j++)
    {
        if(take[j]==0)
        {
            seq[i]=s[j];
            take[j]=1;
            print(i+1);
            take[j]=0;
        }
    }
}
int main()
{
    int i, t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        memset(take, 0, sizeof(take));
        
        sort(s.begin(), s.end());
        
        siz = s.size();
        
        for(i=0;i<siz;i++)
        {
            seq[0] = s[i];
            take[i] = 1;
            print(1);
            take[i] = 0;
        }
    }
    return 0;
}
