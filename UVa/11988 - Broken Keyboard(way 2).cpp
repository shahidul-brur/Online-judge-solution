/**********************************************************
Status:     Accepted
Problem:
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engstreerstrg,
            Begum Rokeya University, Rangpur, Bangladesh
Created on:
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("in.txt", "r", stdin);
    char str[100010], word[100010];
    string w;
    int len, i, j;
    list<string> text;
    while(scanf("%s", str)!=EOF)
    {
        len=strlen(str);
        j=0;
        for(i=0;i<=len;i++)
        {
            if(i==len)
            {
                word[j]='\0';
                if(j>0)
                {
                    w=string(word);
                    text.push_back(w);
                }
                break;
            }
            else if(str[i]=='[')
            {
                word[j]='\0';
                if(j>0)
                {
                    w=string(word);
                    text.push_back(w);
                }
                j=0;
                for(;;)
                {
                    i++;
                    if(str[i]==']' || i==len)
                        break;
                    else if(str[i]=='[')
                    {
                        i--;
                        break;
                    }
                    if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || str[i]=='_')
                        word[j++]=str[i];
                }
                word[j]='\0';
                if(j>0)
                {
                    w=string(word);
                    text.push_front(w);
                }
                j=0;
            }
            else if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || str[i]=='_')
                word[j++]=str[i];
        }

        while(!text.empty())
        {
            cout<<text.front();
            text.pop_front();
        }
        cout << "\n";

    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/

