//Accepted

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>
#define maxi 10000
using namespace std;

vector<int> V, S;

int L[1000006] = {-1}, Seq[1000006], n, mx;
void LIS()
{
    for(int i = 0;i<n;i++)
    {
        vector<int>::iterator it = lower_bound(S.begin(), S.end(), V[i]);
        
        if(it == S.end())
        {
            S.push_back(V[i]);
            L[i] = S.size();
            mx = i;
        }
        else 
        {
            *it = V[i];
            L[i] = it - S.begin()+1;
        }
    }
}
void buildSeq()
{
    int siz = S.size() - 1;
    int i = mx;
    Seq[siz--] = V[mx];
    for(int j=mx-1;j>=0;j--)
    {
        if(V[j]<Seq[siz+1] && L[j] == L[i]-1)
        {
            Seq[siz--] = V[j];
            i = j;
        }
    }
}
int main()
{
    //freopen("481.txt", "r", stdin);
    int num;
    n=0;
    while(cin>>num)
    {
        n++;
        V.push_back(num);
    }
    LIS();
    buildSeq();
    int len = S.size();
    cout << len << "\n-\n";
    for(int i=0;i<len;i++)
        cout << Seq[i] << "\n";
    return 0;
    
}
