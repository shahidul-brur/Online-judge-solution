//Status: Accepted
#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("146.txt", "r", stdin);
    string str;
    int len;
    while(cin>>str)
    {
        if(str[0]=='#')
            break;
        if(next_permutation(str.begin(), str.end()))
            cout<<str<< '\n';
        else
            printf("No Successor\n");
    }
    return 0;
}
