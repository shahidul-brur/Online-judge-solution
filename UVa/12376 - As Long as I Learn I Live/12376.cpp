//Accepted

#include <stdio.h>

int main()
{
   // freopen("12376.txt", "r", stdin);
    int t, c, node, edge, node_value[200], gain[200], go[200],i,total,from,to,last;

    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%d %d",&node, &edge);
        for(i=0;i<node;i++)
        {
            scanf("%d",&node_value[i]);
            gain[i]=0;
            go[i]=0;
        }
        for(i=0;i<edge;i++)
        {
            scanf("%d %d",&from,&to);
            if(node_value[to]>gain[from])
            {
                gain[from]=node_value[to];
                go[from]=to;
            }
        }
        total=0;

        to=go[0];
        total+=node_value[to];
        while(go[to]!=0)
        {
            last=to;
            to=go[last];
            total+=node_value[to];
        }
        printf("Case %d: %d %d\n",c,total,to);
    }
    return 0;
}
