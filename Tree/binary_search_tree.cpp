
//���ֲ�������





#include<iostream>

using namespace std;


struct node {
	struct node* left  ;
	struct node* right ;
	int data ;
}; 
 
int treesize = 0;

//�ڵ㴴��
node* newnode(int data)
{
	//node* newnode = (node*)malloc(sizeof(node));
	node* newnode = new node;
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

//�ڵ����
node* insert(node* root, int data)
{
	if (root == NULL)
		root = newnode(data);
	else if (root->data > data)
		root->left = insert(root->left, data);   // ����ݹ���ҵ����ʵ�λ�ý��в���
	else if (root->data < data)
		root->right = insert(root->right, data); // ���ҵݹ���ҵ����ʵ�λ�ý��в���

	return root;
}

//��ȡ���ֵ   ���������ұ�  һֱ�ݹ�Ѱ����ȥ
node*  getMax(node* root) 
{
	
	if (root->right == NULL)
		return root;
	else
	{
		root->right = getMax(root->right);
	}
}

//�ڵ�ɾ��
node* Delete(node* root, int data) {
	if (root == NULL)
		return root;

	if (root->data < data)
		root->right = Delete(root->right, data);
	else if (root->data > data)
		root->left = Delete(root->left, data);
	else
	{
			if (root->right == NULL || root->left == NULL)  //�ڵ�����ҽڵ㶼Ϊ�գ�ֱ��ɾ��
			{
			free(root);
			return NULL;
			}
			else if (root->left == NULL )                  //��ڵ�Ϊ�գ�ɾ�����ڵ㣬�ҽڵ����µĸ��ڵ㣬
			{
			auto* tmp = root;
			root = root->right;
			free(tmp);
			return root;
			}
			else if (root->right == NULL)                  //�ҽڵ�Ϊ�գ�ɾ�����ڵ㣬��ڵ����µĸ��ڵ�
			{
			auto * tmp = root;
			root = root->right;
			free(tmp);
			return root;
			}
			else											//���ҽڵ㶼��Ϊ��
			{
				auto * tmp = getMax(root->left);			//�ҵ��˽ڵ�Ϊ�����������ֵ
				root->data = tmp->data;						//�����ֵ��ֵ�����ڵ�
				root->left = Delete(root->left, tmp->data); //�ٰ����ֵ������ɾ��
			}
	}

  return root;
}


//�ڵ����   �ݹ���ң��ȸ�ֵ���������ң��ȸ�ֵС�����Ҳ���
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


//���ĸ߶�   �ֱ����Ҹ�����һ�����߶�
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


//������нڵ�   �ݹ�������нڵ�
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


//����ݹ������
void preOrderTraversal(node* root)
{
	if (root == NULL)
		return;

	cout << root->data << endl;
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);

}




//����ݹ������
void inOrderTraversal(node* root)
{
	if (root == NULL)
		return;

	inOrderTraversal(root->left);
	cout << root->data << endl;
	inOrderTraversal(root->right);
}




//����ݹ������
void postOrderTraversal(node* root)
{
	if (root == NULL)
		return;

	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout << root->data << endl;
}