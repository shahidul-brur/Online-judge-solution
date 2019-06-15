/************************************************************
* Verdict:  ACCEPTED 
* Date:                                                     
* 
* Coder:     Md. Shahidul Islam
* Dept. :    Computer Science and Engineering
* Institute: Begum Rokeya University, Rangpur, Bangladesh
*
*************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a[10002], i, j, yes;
    char ch[3];
    while(scanf("%d", &n)!=EOF)
    {
        if(n==0)
            break;
        scanf("%s", ch);
        
        for(i=0;i<n;i++)
        {
            scanf("%d", &a[i]);
        }
        yes = 1;
        for(i=0;i<n;i++)
        {
            set<int> s; 
            for(j=0;j<i;j++)
            {
                int v = a[i] - a[j];
                s.insert(v);
            }
            for(j=i+1;j<n;j++)
            {
                int v = a[j] - a[i];
                if(s.find(v)!=s.end())
                {
                    yes = 0;
                    break;
                }
            }
            if(yes==0)
                break;
            s.clear();
        }
        
        if(yes==1)
            cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}