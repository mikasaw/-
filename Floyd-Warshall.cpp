#include<iostream>
#include<array>
using namespace std;


//��Floyd-Warshall �ҳ����·��


struct Graph {
	int vertexNum;
	int** edges;
};



void FloydWarshall(struct Graph* graph)
{
	int v = graph->vertexNum;
	
	int  dist[v][v];
	
	for (int i = 0; i < v; i++)               //��������ѱߵ���Ϣ��¼����
	{
		for (int j = 0; i < v; j++)
			dist[i][j] = graph->edges[i][j];
	}

	//�������
	for (int k = 0; k < v; k++)
		for (int i = 0; i < v; i++)
			for (int j = 0; j < v; j++)
				if (dist[i][k] != INT_MAX &&              //��̬�ҵ�i,j��������С����·������¼����
					dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];

	int dist1d[v * v];
	for(int i =0;i<v;i++)
		for(int j=0;j<v;j++)
			dist1d[i * v + j] = dist[i][j];
	print(dist1d, v);
}



//ͼ�Ĵ���
void createGraph(struct Graph* g, int v)
{
	g->edges = (int**)malloc(v * sizeof(int*));
	g->vertexNum = v;
	for (int i = 0; i < v; i++)
	{
		g->edges[i] = (int*)malloc(v * sizeof(int));
		for (int j = 0; i < v; j++)
		{
			g->edges[i][j] = INT_MAX;

		}
		g->edges[i][i] = 0;
	}
}

//��ͼ����ӱ�
void addEdge(struct Graph* g, int src, int dst, int weight)
{
	g->edges[src][dst] = weight;
}


//��ӡ����ͼ
void print(int dist[], int v)
{
	cout << "vertex distance" << endl;
	for (int i = 0; i < v; i++)
	{
		if (dist[i] != INT_MAX)
			cout << i << dist[i];
		else
			cout << "INF" << i << endl;
	}

}
