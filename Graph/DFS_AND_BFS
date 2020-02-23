

#include <iostream>
using namespace std;

#define SIZE 40

struct queue {

	int items[SIZE];
	int front;
	int rear;
};


struct queue* creatQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
int pollQueue(struct queue* q);

struct node {
	int vertex;
	struct node* next;
};


struct Graph
{ 
	int numVertices;                  //顶点的数量
	struct node** adjlists;           //结点的信息表
	int* visited;			  //是否遍历过的标志位的记录表
};


struct node* creatNode(int v);				//图结点的创建
struct Graph* creatGraph(int vertices);			//生成图
void addEdge( Graph* Grph, int src, int dest);		//在图上添加边
void printGrapg(Graph* graph);				//创建一个队列
void bfs( Graph* Grph, int startVertex);		//广度优先遍历



//广度优先遍历 采用队列先进先出的特性来实现
void bfs( Graph* graph, int startVertex) {
	queue* q = creatQueue();
	graph->visited[startVertex] = 1;
	enqueue(q, startVertex);				    		    //先把开始的结点入队
	cout << "start traversal from vertex" << startVertex << endl;

	while (!isEmpty(q))
	{
		cout << pollQueue(q);                                               //把遍历的结点打印
		int currentVertex = dequeue(q);				            //把队列头的结点取出

		 node* temp = graph->adjlists[currentVertex];                       //在图中结点信息表中把此结点的信息取出

		while (temp)							    //遍历取出结点的连接结点
		{
			int adjVertex = temp->vertex;
			if (graph->visited[adjVertex] == 0)			    //如果没有遍历过就入队列
			{
				graph->visited[adjVertex] = 1;
				enqueue(q, adjVertex);
			}
			temp = temp->next;								
		}
	}
}




void dfs(struct Graph* graph, int vertex)
{

	node* temp = graph->adjlists[vertex]
	graph->visited[vertex] = 1;				//更改标志表，表明已经遍历过				
	cout << vertex;

	while (temp != NULL)					//结点有子结点，继续遍历下去
	{
		int connectedVertex = temp->vertex;
		if (graph->visited[connectedVertex] == 0)      //如果结点没被遍历过，就进行递归
			dfs(graph, connectedVertex);

		temp = temp->next;
	}

}





//图结点的创建
struct node* creatNode(int v) {
	struct node* newNode = (node *)malloc(sizeof(struct node));
	newNode->next = NULL;
	newNode->vertex = v;
	return newNode;
}

//生成图
struct Graph* creatGraph(int vertices) {
	struct Graph* newGraph =(Graph*) malloc(sizeof(struct Graph));
	newGraph->numVertices = vertices;

	newGraph->adjlists = (node ** )malloc(vertices * sizeof(struct node*));
	newGraph->visited = (int*)malloc(vertices * sizeof(int));

	for (int i = 0; i < vertices; i++)
	{
		newGraph->adjlists[i] = NULL;
		newGraph->visited[i] = 0;
	}
	return newGraph;
}

//在图上添加边
void addEdge(struct Graph* graph, int src, int dest)
{
	
	//添加从原点到目的点的边的信息到adjlists上，便于查找
	struct node* newNode = creatNode(dest);
	newNode->next = graph->adjlists[src];
	graph->adjlists[src] = newNode;

	// 添加从目的点到原点的边的信息到adjlists上
	newNode = creatNode(src);
	newNode->next = graph->adjlists[dest];
	graph->adjlists[dest] = newNode;

}


//创建一个队列
struct queue* creatQueue()
{
	struct queue* q =static_cast<queue*> (malloc(sizeof(struct queue)));
	q->front = -1;
	q->rear = -1;
	return q;

}

//判断队列是否为空
int isEmpty(struct  queue* q )
{
	if (q->rear == -1)
		return 1;
	else
		return 0;

}


//结点入队操作
void enqueue(struct queue* q, int value) 
{
	if (q->rear == SIZE - 1)
		cout << "queue is full " << endl;
	else {
		if (q->front == -1)
			q->front = 0;
		q->rear++;
		q->items[q->rear] = value;

	}

}

//结点出队操作
int dequeue(struct queue* q)
{
	int item;
	if (isEmpty(q))
	{
		cout << "queue is empty" << endl;
		item = -1;
	}
	else
	{
		item = q->items[q->front];
		q->front++;
		if (q->front > q->rear)
		{
			q->front = q->rear = -1;
		}
		return item;
	}
}


//查看队列头的结点信息
int pollQueue(struct queue* q)
{
	return q->items[q->front];
}



//打印整个队列
void display(struct queue* q)
{
	for (int i = 0; i < q->rear; i++)
	{
		cout << q->items[i];
	}
}

//打印整个图
void printGrapg(struct Graph* graph)
{
	for (int i = 0; i < graph->numVertices; i++)
	{
		cout << graph->adjlists[i] << endl;
		cout << graph->visited[i]<<endl;
	}

}

