#include<iostream>

using namespace std;

struct Graph {
	int vertexNum;
	int** edges;
};

void createGraph(struct Graph* g, int v)
{
	g->edges = static_cast<int**>(malloc(v * sizeof(int*)));
	g->vertexNum = v;
	for (int i = 0; i < v; i++)
	{
		g->edges[i]= static_cast<int*>(malloc(v * sizeof(int)));
		for (int j = 0; i < v; j++)
		{
			g->edges[i][j] = INT_MAX;

		}
		g->edges[i][i] = 0;
	}
}


void addEdge(struct Graph* g, int src, int dst, int weight)
{
	g->edges[src][dst] = weight;
}



//用Dijkstra 找出最短路径
void Dijkstra(struct Graph* graph, int src)
{
	int v = graph->vertexNum;
	int* mdist;
	int* vset;
	mdist = static_cast<int *> (malloc(sizeof(int*) * v));
	vset = static_cast<int*> (malloc(sizeof(int*) * v));

	for (int i = 0; i < v; i++)                        //初始化数组
		mdist[i] = INT_MAX, vset[i] = 0;
 
	mdist[src] = 0;


	for (int count = 0; count < v - 1; count++)
	{
		
		int u, minval;
		for (int i = 0; i < v; i++)
		{
			if (vset[i] == 0 && mdist[i] < INT_MAX)   // 结点没被访问过且存在边
			{
				minval = mdist[i];
				u = i;
			}
		}
		vset[u] = 1;
		for (int j = 0; j < v; j++)
		{
			if (!vset[v] && graph->edges[u][j] != INT_MAX          //如果V结点没有被访问过且V结点到源结点的最短路径大于源结点到U结点加UJ边的距离，	
				&& mdist[u] + graph->edges[u][j] < mdist[v])   //就更新新的最小路径到mdist[v]。
				mdist[v] = mdist[u] + graph->edges[u][v];
		}
	}
	//打印最短路径
	for (int i = 0; i < v; i++)
	{
		if (mdist[i] != INT_MAX)
			cout << i << mdist[i];
		else
			cout << "INF" << i << endl;
	}

	return;
}
