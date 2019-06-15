//Accepted
#include <bits/stdc++.h>
using namespace std;
struct dict
{
    char eng[15];
    char forn[15];
}dictionary[100002];
int sortingCondition(const dict *A, const dict *B)
{
    return (strcmp(A->forn, B->forn));
}
int BS(int from, int to, char *word)
{
    int mid;

    while(from<=to)
    {
        mid=(from+to)/2;
        if(strcmp(dictionary[mid].forn, word)==0)
            return mid;
        else if(strcmp(word, dictionary[mid].forn)<0)
        {
            to=mid-1;
        }
        else
        {
            from=mid+1;
        }
    }
    if(from>to)
        return (-1);
}
int main()
{
    freopen("10282.txt", "r", stdin);
    char in[13], dic[25];
    int i,j,len,k,w=0,found;
    while(gets(dic))
    {
        len=strlen(dic);
        if(len==0)
            break;
        sscanf(dic, "%s %s", dictionary[w].eng, dictionary[w].forn);
        w++;
    }
    qsort(dictionary, w, sizeof(dictionary[0]), (int (*)(const void *, const void *))sortingCondition);
    while(scanf("%s", in)!=EOF)
    {
        found=BS(0, w-1, in);
        if(found==-1)
            printf("eh\n");
        else
            printf("%s\n",dictionary[found].eng);
    }
    return 0;
}
