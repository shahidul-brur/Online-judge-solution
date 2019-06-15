/************************************************************
* Problem:   
* Link:                                                     
* Verdict:   Accepted 
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
    freopen("in.txt", "r", stdin);
    
    map<string, int> m;
    map<string, int> w;
    
    m["JAN"] = 1;
    m["FEB"] = 2;
    m["MAR"] = 3;
    m["APR"] = 4;
    m["MAY"] = 5;
    m["JUN"] = 6;
    m["JUL"] = 7;
    m["AUG"] = 8;
    m["SEP"] = 9;
    m["OCT"] = 10;
    m["NOV"] = 11;
    m["DEC"] = 12;
    
    w["SUN"] = 1;
    w["MON"] = 2;
    w["TUE"] = 3;
    w["WED"] = 4;
    w["THU"] = 5;
    w["FRI"] = 6;
    w["SAT"] = 7;
    
    int mnt[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int cnt, t, i, d, day;
    string month, week;
    cin>>t;
    while(t--)
    {
        cin>>month>>week;
        cnt = 0;
        d = w[week]-1;
        
        for(i=1;i<=mnt[m[month]];i++)
        {
            d++;
            if(d>7)
                d=1;
            if(d==6 || d==7)
                cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}