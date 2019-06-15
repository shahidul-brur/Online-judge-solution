/**********************************************************
Status:     Accepted
Problem:    12897
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
    //freopen("12897.txt", "r", stdin);
    int test, cas, R;
    string str;
    char to, from, rep[28];
    scanf("%d", &test);
    for(cas=1;cas<=test;cas++)
    {
        for(int i=0;i<26;i++)
            rep[i]=char(i+'A');
        cin>>str;
        scanf("%d", &R);
        while(R--)
        {
            cin>>to>>from;
            for(int i=0;i<26;i++)
            {
                if(rep[i]==from)
                    rep[i] = to;
            }
        }
        for(int i=0;i<26;i++)
        {
            if((rep[i]-'A')!=i)
                replace(str.begin() , str.end(), char(i+'A'), rep[i]);
        }
        cout<<str<<endl;
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/

