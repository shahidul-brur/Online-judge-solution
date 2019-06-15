/**********************************************************
Status:     Accepted
Problem:    UVa 630
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
int main()
{
    freopen("630.txt", "r", stdin);
    int test, vocabulary, cas, i, j, v[28], w[28], lenW, lenV, cnt, ana;
    char voca[1005][25], word[25];
    scanf("%d", &test);
    for(cas=1;cas<=test;cas++)
    {
        scanf("%d",&vocabulary);
        for(i=0;i<vocabulary;i++)
        {
            scanf("%s", voca[i]);
        }
        if(cas>1)
            printf("\n");
        while(scanf("%s", word)!=EOF)
        {
            if(strcmp(word, "END")==0)
                break;
            cnt=0;
            lenW=strlen(word);
            memset(w, 0, sizeof(w));
            for(i=0;i<lenW;i++)
            {
                w[word[i]-'a']++;
            }

            printf("Anagrams for: %s\n", word);
            for(i=0;i<vocabulary;i++)
            {
                lenV=strlen(voca[i]);
                ana=1;
                if(lenV==lenW)
                {
                    memset(v, 0, sizeof(v));
                    for(j=0;j<lenW;j++)
                        v[voca[i][j]-'a']++;
                    for(j=0;j<26;j++)
                    {
                        if(v[j]!=w[j])
                        {
                            ana=0;
                            break;
                        }
                    }
                }
                else ana=0;
                if(ana==1)
                {
                    cnt++;
                    printf("%3d) %s\n", cnt, voca[i]);
                }
            }
            if(cnt==0)
                printf("No anagrams for: %s\n", word);
        }
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/
