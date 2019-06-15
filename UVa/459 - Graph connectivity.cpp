//Accepted

#include <bits/stdc++.h>
using namespace std;
int baseNode[29];
int buildBaseNode(int node)
{
    if(baseNode[node]==node) return node;
    return baseNode[node]=buildBaseNode(baseNode[node]);
}
int main()
{
    freopen("459.txt", "r", stdin);
    int i, n, cnt, t, cas, b1, b2, node1, node2;
    char e[3], edge[4];
    scanf("%d", &t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%s", e);
        n=e[0] - 'A' + 1;
        for(i=1;i<=27;i++)
            baseNode[i]=i;

        getchar();
        while(gets(edge))
        {
            if(edge[0]=='\0')
                break;
            node1=edge[0] - 'A' + 1;
            node2=edge[1] - 'A' + 1;
            b1=buildBaseNode(node1);
            b2=buildBaseNode(node2);
            if(b1!=b2)
                baseNode[b1]=b2;
        }

        for(i=1;i<=n;i++)
            if(baseNode[i]!=i)
                baseNode[i]=buildBaseNode(i);

        cnt=0;
        for(i=1;i<=n;i++)
        {
            if(baseNode[i]==i)
                cnt++;
        }
        if(cas>1)
            printf("\n");
        printf("%d\n", cnt);
    }
    return 0;
}
