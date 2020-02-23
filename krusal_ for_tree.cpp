//��krusalȥ������С������
//�������ɵ㣬������Ȩͼ

#include<iostream>

using namespace std;


struct Edge
{
	int src;             //��¼�ߵ����
	int dest;			 //��¼�ߵ��յ�
	int weight;			 //��¼�ߵ�Ȩֵ
};
 


struct Graph
{
	int V, E;				//��¼���ͱߵ�����
	struct Edge* edge;	    //��¼�ߵ���Ϣ
};

struct Graph* createGraph(int V, int E)
{
	Graph* graph = new Graph;
	graph->E = E;
	graph->V = V;

	graph->edge = new Edge[E];

	return graph;
}





void  KruskalMST(struct Graph* graph)
{
	int V = graph->V;
	Edge result[V];
	int e = 0;           
	int i = 0;			 


	//��ͼ�ı߽�������
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

	 subset* subsets = static_cast<subset*>(malloc(V * sizeof(struct subset)));

	for (int v = 0; v < V; v++)			//��ʼ��subsets����
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;

	}

	while (e<V-1 &&  i<graph->E)         
	{
		
		struct Edge next_edge = graph->edge[i++];

		int x = find(subsets, next_edge.src);			//�ҳ���һ���ߵ������յ�
		int y = find(subsets, next_edge.dest);

		
		if (x != y)										//���ھ�������
		{
			result(e++) = next_edge;
			Union(subsets, x, y);
		}

	}
	cout << "Following are the edges in the constructed MST" << endl;
	for(i =0;i<e;i++)
	{
		cout << result[i].src << result[i].dest;
	}
	return;

}




//������¼���ĸ�ĸ����Ϣ
struct subset
{
	int parent;
	int rank;
};

//��subsets�������ܵ�i�ĸ����
int find(subset subsets[], int i)
{
	
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);

	return subsets[i].parent;
}

//��x,y�������Ϊ���Ľ��
void Union( subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	if (subsets[xroot].rank < subsets[yroot].rank)		//�ҳ�rankֵ������Ϊ�����
		subsets[xroot].parent = yroot;

	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;

	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}


//�ȽϺ���
int myComp(const void* a, const void* b)
{
	 Edge* a1 = (Edge*)a;
	 Edge* b1 = (Edge*)b;
	return a1->weight > b1->weight;

}
