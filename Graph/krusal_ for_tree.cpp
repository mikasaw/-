//用krusal去生成最小生成树
//给出生成点，无向有权图

#include<iostream>

using namespace std;


struct Edge
{
	int src;             //记录边的起点
	int dest;	     //记录边的终点
	int weight;	     //记录边的权值
};
 


struct Graph
{
	int V, E;		    //记录结点和边的数量
	struct Edge* edge;	    //记录边的信息
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


	//对图的边进行排序，
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

	 subset* subsets = static_cast<subset*>(malloc(V * sizeof(struct subset)));

	for (int v = 0; v < V; v++)			//初始化subsets数组
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;

	}

	while (e<V-1 &&  i<graph->E)         
	{
		
		struct Edge next_edge = graph->edge[i++];

		int x = find(subsets, next_edge.src);		           	   //找出下一条边的起点和终点
		int y = find(subsets, next_edge.dest);

		
		if (x != y)							   //存在就生成树
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




//用来记录结点的父母的信息
struct subset
{
	int parent;
	int rank;
};

//在subsets数组中周到i的父结点
int find(subset subsets[], int i)
{
	
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);

	return subsets[i].parent;
}

//把x,y两个点变为树的结点
void Union( subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	if (subsets[xroot].rank < subsets[yroot].rank)		//找出rank值最大的最为父结点
		subsets[xroot].parent = yroot;

	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;

	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}


//比较函数
int myComp(const void* a, const void* b)
{
	 Edge* a1 = (Edge*)a;
	 Edge* b1 = (Edge*)b;
	return a1->weight > b1->weight;

}
