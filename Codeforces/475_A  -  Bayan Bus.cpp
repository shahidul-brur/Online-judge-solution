/**********************************************************
Status:
Problem:
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
Created on:
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
    /***** for faster input output ********/
       ios_base::sync_with_stdio(false);
    /***** *********************** ********/
    int n;
    cin>>n;
    cout<<"+";
    for(int i=1;i<=24;i++)
        cout<<"-";
    cout<<"+"<<"\n";
    for(int i=1;i<=4;i++)
    {
        cout<<"|";
        for(int j=0;j<11;j++)
        {
            if(j==0)
            {
                if(i<=n)
                    cout<<"O.";
                else cout<<"#.";
            }
            else
            {
                if(i==3)
                    cout<<"..";

                else if(i!=3)
                {
                    int m;
                    if(i>=4)
                        m=3;
                    else m=i;

                    if((4+(j-1)*3+m)<=n)
                        cout<<"O.";
                    else cout<<"#.";
                }
            }
        }
        if(i==1)
            cout<<"|D|)";
        else if(i==2)
            cout<<"|.|";
        else if(i==3)
            cout<<"..|";
        else cout<<"|.|)";

        cout<<"\n";
    }
    cout<<"+";
    for(int i=1;i<=24;i++)
        cout<<"-";
    cout<<"+"<<"\n";
    return 0;
}
/**********************************************************
About this problem:

************************************************************/