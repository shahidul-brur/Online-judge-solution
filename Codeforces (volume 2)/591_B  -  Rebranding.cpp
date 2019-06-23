/**********************************************************
Status:     
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
Created on: 28-08-2015
***********************************************************/

#include <bits/stdc++.h>
using namespace std;

#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
#define maxi(a, b) ((a)>(b) ? (a):(b))
#define mini(a, b) ((a)<(b) ? (a):(b))
#define sqr(a) ((a)*(a))
int main()
{
    //freopen("in.txt", "r", stdin);
    int n, R;
    vector<int> index[27];
    string str;
    char to, from;
    while(cin>>n)
    {
        cin>>R;
        cin>>str;
        for(int i=0;i<n;i++)
        {
            index[str[i] - 'a'].push_back(i);
        }
        while(R--)
        {
            cin>>from>>to;
            if(from != to)
            {
                /*
                int siz = index[from - 'a'].size();
                for(int i=0;i<siz;i++)
                {
                    str[index[from - 'a'][i]] = to;
                }
                
                siz = index[to - 'a'].size();
                for(int i=0;i<siz;i++)
                {
                    str[index[to - 'a'][i]] = from;
                }
                */
                swap(index[from -'a'], index[to - 'a']);
            }
            
        }
        
        for(int i=0;i<26;i++)
        {
            int siz = index[i].size();
            for(int j=0;j<siz;j++)
            {
                str[index[i][j]]= i + 'a';
            }
            index[i].resize(0);
        }
        cout<<str<<endl;
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/

