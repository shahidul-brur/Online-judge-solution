#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc,k=0;
    stack<string> backword,forword;
    backword.push("http://www.lightoj.com/");
    forword.push("http://www.lightoj.com/");
    cin>>tc;
    while(tc--)
    {
        k++;

        string str,st;
        cout<<"Case "<<k<<":"<<endl;
        while(cin>>str)
        {

            if(str == "VISIT")
            {
                cin>>st;
                backword.push(st);
                cout<<backword.top()<<endl;
            }
            else if(str == "BACK")
            {

                if(!backword.empty())
                {
                    forword.push(backword.top());
                    backword.pop();
                    if(backword.size()!=0)
                    cout<<backword.top()<<endl;
                    else cout<<"Ignored"<<endl;


                }



            }
            else if(str == "FORWARD")
            {
                if(!forword.empty())
                {
                    backword.push(forword.top());
                    forword.pop();
                    if(forword.size()!=0)
                    cout<<forword.top()<<endl;
                    else cout<<"Ignored"<<endl;

                }



            }
            else if(str == "QUIT")
            {

               break;
            }
        }


    }

    return 0;
}
