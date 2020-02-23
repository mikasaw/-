#include<iostream>

using namespace std;

//存储边的信息
struct Edge {
	int src, dst, weight;
};

//存储图
struct Graph
{
	int vertexNum;            	  //记录结点的数目
	int edgeNum;			  //记录边的数目
	struct Edge* edges;		  //记录边的信息
};


//用Bellman-Ford寻找最短路径
void BellmanFord(struct Graph* graph, int src)
{
	int V = graph->vertexNum;
	int E = graph->edgeNum;
	int* dist = static_cast<int*>(malloc(sizeof(int*) * V));

	//距离数组初始化
	for (int i = 0; i < V; i++)
	{
		dist[i] = INT_MAX;
	}
	dist[src] = 0;

	//计算最短路径
	for (int i = 0; i < V; i++)		                        //遍历每个结点
	{
		for (int j = 0; j < E; j++)        			 //把 i结点的边的信息记录
		{
			int u = graph->edges[j].src;
			int v = graph->edges[j].dst;
			int w = graph->edges[j].weight;
			
			if (dist[u] != INT_MAX && dist[u] + w < dist[v])	//如果源结点到u结点的距离加uv两点的距离小于源结点到v结点的距离
				dist[v] = dist[u] + w;				//就在dist表上更新					
		}
	}

	//判断内部是否有环
	for (int j = 0; j < E; j++)
	{
		int u = graph->edges[j].src;
		int v = graph->edges[j].dst;
		int w = graph->edges[j].weight;

		if (dist[u] != INT_MAX && dist[u] + w < dist[v])
			cout << "内部有环" << endl;
			return;
	}
	print(dist, V);
	return;
}




//图的创建
void creatGraph(struct Graph* G, int V, int E)
{
	G->vertexNum = V;
	G->edgeNum = E;
	G->edges = (struct Edge*) malloc(sizeof(struct Edge));

}

//把边添加到图上
void addEdge(struct Graph* G, int src, int dst, int weight)
{
	static int ind;
	struct Edge newEdge;
	newEdge.dst = dst;
	newEdge.src = src;
	newEdge.weight = weight;
	G->edges[ind++] = newEdge;

}

//显示距离
void print(int dist[], int V)
{
	for (int i = 0; i < V; i++)
	{
		if (dist[i] != INT_MAX)
			cout << i << dist[i] << endl;
		else
			cout << i;
	}

}

