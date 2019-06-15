#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define INF 1000000000
vector< pii > AdjList[1002];
int dist[1002], V;
void bellmanford()
{
	for(int i=0;i<V;i++)
		dist[i]=INF;
    dist[0] = 0;
    for (int i = 0; i < V - 1; i++)
        for (int u = 0; u < V; u++)
            for (int j = 0; j < (int)AdjList[u].size(); j++)
            {
            	pii v = AdjList[u][j];
                dist[v.first] = min(dist[v.first], dist[u] + v.second);
            }
}

bool checkNegCycle()
{
    bool hasNegativeCycle = false;
    for (int u = 0; u < V; u++)
        for (int j = 0; j < (int)AdjList[u].size(); j++)
        {
            pii v = AdjList[u][j];
            if (dist[v.first]!=INF && dist[v.first] > dist[u] + v.second)
            {
                hasNegativeCycle = true;
                break;
            }
        }
        
    return hasNegativeCycle;
}

int main()
{
	freopen("558.txt", "r", stdin);
	int test, edge, i, j, u, v, cost;
	cin >> test;
	while (test--)
	{
		cin >> V >> edge;
		for (i = 0; i < edge; i++)
		{
			cin >> u>>v >> cost;
			AdjList[u].push_back(make_pair(v, cost));
		}
		
		bellmanford();
		if(checkNegCycle()==true)
			printf("possible\n");
		else printf("not possible\n");
		
		for(i=0;i<=V;i++)
            AdjList[i].clear();
	}
	return 0;
}
