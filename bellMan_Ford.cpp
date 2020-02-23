#include<iostream>

using namespace std;

//�洢�ߵ���Ϣ
struct Edge {
	int src, dst, weight;
};

//�洢ͼ
struct Graph
{
	int vertexNum;            //��¼������Ŀ
	int edgeNum;			  // ��¼�ߵ���Ŀ
	struct Edge* edges;		  //��¼�ߵ���Ϣ
};


//��Bellman-FordѰ�����·��
void BellmanFord(struct Graph* graph, int src)
{
	int V = graph->vertexNum;
	int E = graph->edgeNum;
	int* dist = static_cast<int*>(malloc(sizeof(int*) * V));

	//���������ʼ��
	for (int i = 0; i < V; i++)
	{
		dist[i] = INT_MAX;
	}
	dist[src] = 0;

	//�������·��
	for (int i = 0; i < V; i++)				//����ÿ�����
	{
		for (int j = 0; j < E; j++)         //�� i���ıߵ���Ϣ��¼
		{
			int u = graph->edges[j].src;
			int v = graph->edges[j].dst;
			int w = graph->edges[j].weight;
			
			if (dist[u] != INT_MAX && dist[u] + w < dist[v])	//���Դ��㵽u���ľ����uv����ľ���С��Դ��㵽v���ľ���
				dist[v] = dist[u] + w;							//����dist���ϸ���					
		}
	}

	//�ж��ڲ��Ƿ��л�
	for (int j = 0; j < E; j++)
	{
		int u = graph->edges[j].src;
		int v = graph->edges[j].dst;
		int w = graph->edges[j].weight;

		if (dist[u] != INT_MAX && dist[u] + w < dist[v])
			cout << "�ڲ��л�" << endl;
			return;
	}
	print(dist, V);
	return;
}




//ͼ�Ĵ���
void creatGraph(struct Graph* G, int V, int E)
{
	G->vertexNum = V;
	G->edgeNum = E;
	G->edges = (struct Edge*) malloc(sizeof(struct Edge));

}

//�ѱ���ӵ�ͼ��
void addEdge(struct Graph* G, int src, int dst, int weight)
{
	static int ind;
	struct Edge newEdge;
	newEdge.dst = dst;
	newEdge.src = src;
	newEdge.weight = weight;
	G->edges[ind++] = newEdge;

}

//��ʾ����
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

