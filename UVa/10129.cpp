#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
    freopen("10129.txt", "r", stdin);
    int t, n, i, j, len, cnt, first[27], last[27];
    char word[1002];
    scanf("%d", &t);
    while(t--)
    {
        memset(first, 0, sizeof(first));
        memset(last, 0, sizeof(last));
        scanf("%d", &n);
        for(i=1;i<=n;i++)
        {
            scanf("%s", word);
            len=strlen(word);
            first[word[0]-'a']++;
            last[word[len-1]-'a']++;
        }
        for(i=0, cnt=0;i<26;i++)
            if(first[i]==last[i])
                cnt+=first[i];
        if(cnt>=n-1)
            printf("Ordering is possible.\n");
        else
            printf("The door cannot be opened.\n");

    }
    return 0;
}
