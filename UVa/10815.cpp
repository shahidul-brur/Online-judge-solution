//Accepted

#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("10815.txt", "r", stdin);
    int len, i, j,c=0, len1;
    string txt, tmp;
    char temp[202];
    vector<string> word;
    while(cin>>txt)
    {
        len=txt.size();
        for(i=0,j=0;i<=len;i++)
        {
            if(txt[i]>='A' && txt[i]<='Z')
                temp[j++]=txt[i]-'A'+'a';
            else if(txt[i]>='a' && txt[i]<='z')
                temp[j++]=txt[i];
            else
            {
                temp[j]='\0';
                j=0;
                len1=strlen(temp);
                if(len1>0)
                {

                    tmp=string(temp);
                    word.push_back(tmp);
                }

            }
        }
    }
    sort(word.begin(), word.end());
    c=word.size();
    for(i=0;i<c;i++)
    {
        cout<<word[i]<<endl;
        if(i+1<c)
            while(word[i]==word[i+1])
            {
                i++;
                if(i>=c)
                    break;
            }
    }
    return 0;
}
