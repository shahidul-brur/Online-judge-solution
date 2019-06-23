/*=================================*\
                                   
      Md. Shahidul Islam           
         CSE, BRUR                 
      Rangpur, Bangladesh          
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com 
\*=================================*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<algorithm>
#include<utility>
#include<ctime>
#include<cctype>
#include<string>
#include<sstream>
#include<cstring>
#include<fstream>
#include<iterator>
#include<iostream>
#include<cassert>
using namespace std;
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define F(i, a, b)      for(int i=(a);i>=(b);i--)
const int MX = 1005;
char s[MX][MX];
int r[MX], c[MX];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    while(cin>>n>>m)
    {
        int cnt = 0;
        f(i, 0, n-1)
        {
            cin>>s[i];
            f(j, 0, m-1)
                cnt+=s[i][j]=='*';
        }
        if(cnt==0)
        {
            cout << "YES\n1 1\n";
            return 0;
        }
        f(i, 0, n-1)
        {
            r[i] = 0;
            f(j, 0, m-1) 
                r[i]+=s[i][j]=='*';
        }
        
        f(j, 0, m-1)
        {
            c[j] = 0;
            f(i, 0, n-1) 
                c[j]+=s[i][j]=='*';
        }
        
        f(i, 0, n-1)
        {
            f(j, 0, m-1) 
            {
                if(r[i]+c[j]-(s[i][j]=='*')==cnt)
                {
                    cout << "YES\n" << i+1 << " " << j+1 << "\n";
                    return 0;
                }
            }
        }
        
        cout << "NO\n";
        
    }
    return 0;
}

