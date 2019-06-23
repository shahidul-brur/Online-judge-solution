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
map<string, int> points;
map<string, int> point2;
vector<string> nameList;
vector<int> gett;
int main()
{
    //freopen("in.txt", "r", stdin);
    int n, score, maxp;
    string name, won;
    map<string, int>::iterator index;
    cin>>n;
    
    for(int i=1;i<=n;i++)
    {
        cin>>name>>score;
        gett.push_back(score);
        nameList.push_back(name);
        points[name]+=score;
    }
    
    maxp=-100000000;
    for(index=points.begin();index!=points.end();index++)
    {
        if(index->second > maxp)
        {
            maxp=index->second;
        }
    } 
    for(int i=0;i<n;i++)
    {
        point2[nameList[i]]+=gett[i];
        if(point2[nameList[i]]>=maxp && points[nameList[i]]>=maxp)
        {
            won = nameList[i];
            break;
        }
    }
    cout<<won<< "\n";
    return 0;
}
/**********************************************************
About this problem:

************************************************************/

