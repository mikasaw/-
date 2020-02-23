
//二分查找树，





#include<iostream>

using namespace std;


struct node {
	struct node* left  ;
	struct node* right ;
	int data ;
}; 
 
int treesize = 0;

//节点创建
node* newnode(int data)
{
	//node* newnode = (node*)malloc(sizeof(node));
	node* newnode = new node;
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

//节点插入
node* insert(node* root, int data)
{
	if (root == NULL)
		root = newnode(data);
	else if (root->data > data)
		root->left = insert(root->left, data);   // 向左递归查找到合适的位置进行插入
	else if (root->data < data)
		root->right = insert(root->right, data); // 向右递归查找到合适的位置进行插入

	return root;
}

//获取最大值   在树的最右边  一直递归寻找下去
node*  getMax(node* root) 
{
	
	if (root->right == NULL)
		return root;
	else
	{
		root->right = getMax(root->right);
	}
}

//节点删除
node* Delete(node* root, int data) {
	if (root == NULL)
		return root;

	if (root->data < data)
		root->right = Delete(root->right, data);
	else if (root->data > data)
		root->left = Delete(root->left, data);
	else
	{
			if (root->right == NULL || root->left == NULL)  //节点的左右节点都为空，直接删除
			{
			free(root);
			return NULL;
			}
			else if (root->left == NULL )                  //左节点为空，删除父节点，右节点变成新的父节点，
			{
			auto* tmp = root;
			root = root->right;
			free(tmp);
			return root;
			}
			else if (root->right == NULL)                  //右节点为空，删除父节点，左节点变成新的父节点
			{
			auto * tmp = root;
			root = root->right;
			free(tmp);
			return root;
			}
			else											//左右节点都不为空
			{
				auto * tmp = getMax(root->left);			//找到此节点为根的树的最大值
				root->data = tmp->data;						//把最大值赋值给根节点
				root->left = Delete(root->left, tmp->data); //再把最大值从数中删除
			}
	}

  return root;
}


//节点查找   递归查找，比根值大就向左查找，比根值小就向右查找
int  findnode(node * root,int data)   
{
	if (root == NULL)
		return 0;
	else if (root->data = data)
		return 1;
	else if (root->data < data)
		return  findnode(root->right, data);
	else if (root->data > data)
		return  findnode(root->left, data);
		
	

}


//树的高度   分别左右各遍历一遍计算高度
int height(node* root) 
{
	int LeftTreeHight = 0;
	int RightTreeHight = 0;
	while (root->left != NULL)
	{
		root = root->left;
		LeftTreeHight++;
	}
	
	while (root->right != NULL)
	{
		root = root->right;
		RightTreeHight++;
	}
	if (LeftTreeHight < RightTreeHight)
		return RightTreeHight;
	else
		return LeftTreeHight;

}


//清除所有节点   递归清除所有节点
void clearNode(node* root)
{
	if (root == NULL)
		return ;
	else 
	{
		if (root->left != NULL)
			clearNode(root->left);
		if (root->right != NULL)
			clearNode(root->right);
		free(root);
	}

}


//先序递归遍历树
void preOrderTraversal(node* root)
{
	if (root == NULL)
		return;

	cout << root->data << endl;
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);

}




//中序递归遍历树
void inOrderTraversal(node* root)
{
	if (root == NULL)
		return;

	inOrderTraversal(root->left);
	cout << root->data << endl;
	inOrderTraversal(root->right);
}




//后序递归遍历树
void postOrderTraversal(node* root)
{
	if (root == NULL)
		return;

	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout << root->data << endl;
}