#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n, i, b, g, r, a;
   string s, c;
   while(cin>>n)
   {
       b = g = r = 0;
       cin>>s;
       for(i=0;i<n;i++)
       {
           if(s[i]=='B')
            b++;
           else if(s[i]=='G')
            g++;
            else if(s[i]=='R')
                r++;
       }

       if(b>0 && g>0 && r>0)
         cout << "BGR\n";


       else if(b==0 && g==0)
            cout << "R\n";
       else if(b==0 && r==0)
            cout << "G\n";
        else if(r==0 && g==0)
            cout << "B\n";


        else if(b==0 && r==1 && g==1)
            cout << "B\n";
        else if(g==0 && r==1 && b==1)
            cout << "G\n";
        else if(r==0 && b==1 && g==1)
            cout << "R\n";

        else if(b==0 && r==1 && g>1)
            cout << "BR\n";
        else if(b==0 && r>1 && g==1)
            cout << "BG\n";
        else if(g==0 && r==1 && b>1)
            cout << "GR\n";
          else if(g==0 && r>1 && b==1)
            cout << "BG\n";

        else if(r==0 && b==1 && g>1)
            cout << "BR\n";
        else if(r==0 && b>1 && g==1)
            cout << "GR\n";

        else
        {
            /*
            if(b==0)
            {
                cout << "B";
                if(g<=r )
                    cout << "G";
                if(r<=g) cout << "R";
            }
            else if(g==0)
            {
                if(b<=r)
                    cout << "B";
                cout << "G";
                if(r<=b)
                    cout << "R";
            }
            else if(r==0)
            {

                if(b<=g)
                    cout << "B";
                if(g<=b)
                    cout << "G";
                cout << "R";
            }
            */
            cout << "BGR\n";
        }
   }
   return 0;
}
