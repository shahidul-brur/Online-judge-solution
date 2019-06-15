/************************************************************
* Problem:   
* Link:                                                     
* Verdict: Accepted  
* Date:                                                     
* 
* Coder:     Md. Shahidul Islam
* Dept. :    Computer Science and Engineering
* Institute: Begum Rokeya University, Rangpur, Bangladesh
*
*************************************************************/

#include <bits/stdc++.h>
using namespace std;
int diff(string a, string b)
{
    int l=a.size();
    int d = 0;
    for(int i=0;i<l;i++)
    {
        if(a[i] != b[i])
            d++;
    }
    return d;
}

int main()
{
    
    //freopen("in.txt", "r", stdin);
    string s[1003], t;
    int test, c, i, j, n;
    cin>>test;
    for(c=1;c<=test;c++)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>s[i];
        }
        cin>>t;
        cout << "Case "<< c << ":\n";
        for(i=0;i<n;i++)
        {
            if(diff(s[i], t)<=1)
            {
                cout << s[i] << "\n";
            }
        }
    }
    return 0;
}