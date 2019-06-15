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
void makeLower(char *str, int len)
{
    for(int i=0;i<len;i++)
    {
        if(str[i]>='A' && str[i]<='Z')
            str[i]= str[i]-'A'+'a';
    }
}
int main()
{
    freopen("10126.txt", "r", stdin);
    int n, len, i, j, w[10003], m=0;
    char text[1000003], word[500];
    map<string, int> mp;
    vector<string> wordlist;
    while(scanf("%d", &n)!=EOF)
    {
        memset(w, 0, sizeof(w));
        m=0;
        getchar();
        while(gets(text))
        {
            len=strlen(text);
            if(len>0)
                makeLower(text, len);
            if(strcmp(text, "endoftext")==0)
            {
                int p=0;
                sort(wordlist.begin(), wordlist.end());

                for(i=0;i<m;i++)
                {
                    if(w[mp[wordlist.at(i)]]==n)
                    {
                        string A = wordlist.at(i);
                        cout<<A<<"\n";
                        p++;
                    }
                }
                if(p==0)
                    cout<< "There is no such word." << "\n";

                printf("\n");
                m=0;
                mp.clear();
                wordlist.resize(0);
                break;
            }
            len=strlen(text);
            if(len>0)
            {
                i=0;
                while(text[i]<'a' || text[i]>'z')
                    i++;
                for(j=0;i<=len;i++)
                {
                    if(i==len || text[i]<'a' || text[i]>'z')
                    {
                        word[j]='\0';
                        j=0;
                        while(text[i]<'a' || text[i]>'z')
                            i++;
                        if(text[i]>='a' && text[i]<='z')
                            i--;

                        string str(word);
                        if(mp.find(str)==mp.end())
                        {
                            mp[str]=m++;
                            w[mp[str]]=1;
                            wordlist.push_back(str);
                        }
                        else w[mp[str]]++;

                    }
                    else if(text[i]>='a' && text[i]<='z')
                    {
                        word[j++]=text[i];
                    }
                }
            }
        }
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/

