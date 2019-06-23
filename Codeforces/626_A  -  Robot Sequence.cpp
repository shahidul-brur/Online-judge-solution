#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
   int n, i, c, j, x, y, nx, ny;
   string s;
   while(cin>>n)
   {
       c=0;
       cin>>s;
       for(i=0;i<n;i++)
       {
           x=y=0;
           for(j=i;j<n;j++)
           {
               if(s[j]=='D')
                    y--;
               else if(s[j]=='U')
                    y++;
               else if(s[j]=='L')
                    x--;
               else x++;
               if(x==0 && y==0)
                    c++;
               else
               {
                   nx = x;
                   ny = y;
                   for(int k=j;k>=i;k--)
                   {

                       if(s[j]=='D')
                            ny--;
                       else if(s[j]=='U')
                            ny++;
                       else if(s[j]=='L')
                            nx--;
                       else nx++;
                   }
                   if(nx==0 && ny==0)
                        c++;
               }
           }
       }
       cout << c << "\n";
   }
   return 0;
}
