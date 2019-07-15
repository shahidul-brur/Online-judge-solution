#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, j, act, laddu, rnk;
    char org[25], activity[50];
    cin>>t;
    while(t--)
    {
        cin>>act>>org;
        laddu=0;
        while(act--)
        {
            cin>>activity;
            if(strcmp(activity, "CONTEST_WON")==0)
            {
                cin>>rnk;
                if(rnk<20)
                    laddu+=300+20-rnk;
                else laddu+=300;
            }
            else if(strcmp(activity, "TOP_CONTRIBUTOR")==0)
                laddu+=300;
            else if(strcmp(activity, "BUG_FOUND")==0)
            {
                int sev;
                cin>>sev;
                laddu+=sev;
            }
            else laddu+=50;
        }
        if(strcmp(org, "INDIAN")==0)
            cout << laddu/200 << "\n";
        else cout << laddu/400 << "\n";
    }
    return 0;
}
