

//�����������:
//��1��ÿ���ڵ�����Ǻ�ɫ�������Ǻ�ɫ��
//��2�����ڵ��Ǻ�ɫ��
//��3��ÿ��Ҷ�ӽڵ㣨NIL���Ǻ�ɫ��[ע�⣺����Ҷ�ӽڵ㣬��ָΪ��(NIL��NULL)��Ҷ�ӽڵ㣡]
//��4�����һ���ڵ��Ǻ�ɫ�ģ��������ӽڵ�����Ǻ�ɫ�ġ�
//��5����һ���ڵ㵽�ýڵ������ڵ������·���ϰ�����ͬ��Ŀ�ĺڽڵ㡣

// ����(3)�е�Ҷ�ӽڵ㣬��ֻΪ��(NIL��null)�Ľڵ㡣
// ����(5)��ȷ��û��һ��·���������·����������������������������ǽӽ�ƽ��Ķ�������


#include<iostream>

using namespace std;



struct Node {
	int val;
	Node* par;
	Node* left;
	Node* right;
	int color;        // 0Ϊ��ɫ��1Ϊ��ɫ
};

//�����ڵ�
Node* newnode(int val, Node* par)
{
	//Node* newnode = (Node*)malloc(sizeof(Node));
	Node* newnode = new Node;
	newnode->val = val;
	newnode->par = par;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->color = 1;   //��ɫ��ʼ��Ϊ��ɫ
	
	return newnode;

}

//���һ���ڵ��Ƿ�ΪҶ��
bool isleaf(Node* n)
{
	if (n->left == NULL || n->right == NULL)
		return true;
	else
		return false;
}


//����
Node* leftRotate(Node* lnode)
{
	
		Node* parent = lnode->right;                  //����ת�������ӽ����Ϊ�µĸ��״洢
		Node* grandParent = lnode->par;              //���游����Ϣ�洢


		parent->left = lnode;
		if (lnode->right != NULL)                    //�ѽ���������������Ϊ�游
			lnode->right->par = grandParent;

		lnode->par = parent;
		lnode->right = parent->left;                  // ���¸��׵����ӽڵ��ƶ���Ϊ��ת�����ҽ��
		parent->left->par = lnode; 
			                                          
		if (grandParent != NULL)                      //�ж��µĸ�����λ��     
		{
			if (grandParent->right == parent)         //����߾ͳ�Ϊ���������ӽ��
				grandParent->right = parent;
			else
				grandParent->left = parent;           //���ұ߾ͳ�Ϊ���������ӽ�� 
			
		}
	
	return lnode;
}





//����  ����ͬ��
Node* rightRotate(Node* rnode) 
{
	Node* parent = rnode->left;
	Node* grandParent = rnode->par;

	parent->right = rnode;
	if (rnode->right != NULL)
		rnode->right->par = grandParent;

	rnode->par = parent;
	rnode->left = parent->right;
	parent->right->par = rnode;

	if (grandParent != NULL)
	{
		if (grandParent->right == parent)
			grandParent->right = rnode;
		else
			grandParent->left = rnode;
	}    

	return rnode;
}


//�ڲ�������������
void checkNode(Node* node) {

	// �ڵ�Ϊ�����
	if (node == NULL || node->par == NULL) {
		return;
	}
	Node* child = node;
	// ���Ӷ��Ǻ�ɫ�ڵ�
	if (node->color == 0 || (node->par)->color == 0) {
		return;
	}

	// ���Ӷ��Ǻ�ɫ�ڵ�
	// ����常
	Node* parent = node->par;
	Node* grandParent = parent->par;

	//үүΪ�գ�����Ϊ���ڵ�
	if (grandParent == NULL) {
		parent->color = 0;
		return;
	}

	//���Ӻ�үү��Ϊ��ɫ
	if (grandParent->right != NULL && (grandParent->right)->color == 1 
		&& grandParent->left != NULL && (grandParent->left)->color == 1)
	{
		(grandParent->right)->color = 0;
		(grandParent->left)->color = 0;
		 grandParent->color = 1;
		return;
	}
	else {
		  //����ߵ����
		Node* greatGrandParent = grandParent->par;
		if (grandParent->right == parent) {
			
			if (parent->right == node) {
				grandParent->right = parent->left;
				if (parent->left != NULL) {
					(parent->left)->par = grandParent;
				}
				parent->left = grandParent;
				grandParent->par = parent;

				
				parent->par = greatGrandParent;
				if (greatGrandParent != NULL) {
					if (greatGrandParent->left != NULL && greatGrandParent->left == grandParent) {
						greatGrandParent->left = parent;
					}
					else {
						greatGrandParent->right = parent;
					}
				}

				// �ı���ɫ
				parent->color = 0;
				grandParent->color = 1;
			}
			else {   
				// ���׺ͺ�����ת
				parent->left = child->right;
				if (child->right != NULL) {
					(child->right)->par = parent;
				}
				child->right = parent;
				parent->par = child;

				// ���Ӻ��游��ת
				grandParent->right = child->left;
				if (child->left != NULL) {
					(child->left)->par = grandParent;
				}
				child->left = grandParent;
				grandParent->par = child;

				// ���ӵ�����
				child->par = greatGrandParent;
				if (greatGrandParent != NULL) {
					if (greatGrandParent->left != NULL && greatGrandParent->left == grandParent) {
						greatGrandParent->left = child;
					}
					else {
						greatGrandParent->right = child;
					}
				}

				// �ı亢�Ӻ��游��ɫ
				child->color = 0;
				grandParent->color = 1;
			}
		}
		else {   //������
			
			if (parent->left == node) {
				grandParent->left = parent->right;
				if (parent->right != NULL) {
					(parent->right)->par = grandParent;
				}
				parent->right = grandParent;
				grandParent->par = parent;

				// ���ӵ�����
				parent->par = greatGrandParent;
				if (greatGrandParent != NULL) {
					if (greatGrandParent->left != NULL && greatGrandParent->left == grandParent) {
						greatGrandParent->left = parent;
					}
					else {
						greatGrandParent->right = parent;
					}
				}

				// �ı亢�Ӻ��游����ɫ
				parent->color = 0;
				grandParent->color = 1;
			}
			else {   //Left Right Case

				// ��ת���׺ͺ���
				parent->right = child->left;
				if (child->left != NULL) {
					(child->left)->par = parent;
				}
				child->left = parent;
				parent->par = child;

				// ��ת���Ӻ��游
				grandParent->left = child->right;
				if (child->right != NULL) {
					(child->right)->par = grandParent;
				}
				child->right = grandParent;
				grandParent->par = child;

				// ���ӵ�����
				child->par = greatGrandParent;
				if (greatGrandParent != NULL) {
					if (greatGrandParent->left != NULL && greatGrandParent->left == grandParent) {
						greatGrandParent->left = child;
					}
					else {
						greatGrandParent->right = child;
					}
				}

				// �ı亢�Ӻ��游����ɫ
				child->color = 0;
				grandParent->color = 1;
			}
		}
	}
}




//�����ϲ�����
void insertNode(int val, Node* root)
{
	Node* buffRoot = root;
	while (buffRoot)                   //�ݹ��ҵ����ʵ�λ�á�
	{
		if (buffRoot->val > val)
		{
			if (buffRoot->left != NULL)
				buffRoot = buffRoot->left;
			else
			{
				buffRoot->left = newnode(val, buffRoot);   //�Ҳ����򴴽��µĽ��
				break;
			}
		}
		else
		{
			if (buffRoot->right != NULL)
				buffRoot = buffRoot->right;
			else
			{
				buffRoot->right = newnode(val, buffRoot); 
				break;
			}
		}

	}
	while (buffRoot != root)          
	{
		checkNode(buffRoot);                  //�Բ������������е���
		if (buffRoot->par = NULL)
		{
			root = buffRoot;
			break;
		}
		buffRoot = buffRoot->par;
		if (buffRoot == root)
			buffRoot->color = 0;

	}
}

//���õݹ���������(��ɾ��������)
void checkForCase2(Node* toDelete, int Delete, int fromDirection, Node** root) {

	if (toDelete == (*root)) {
		(*root)->color = 0;
		return;
	}

	if (!Delete && toDelete->color == 1) {
		if (!fromDirection) {
			if (toDelete->right != NULL) {
				toDelete->right->color = 1;
			}
		}
		else {
			if (toDelete->left != NULL) {
				toDelete->left->color = 1;
			}
		}
		toDelete->color = 0;
		return;
	}


	// ��ȡ������ݵ���Ϣ�����н�һ������
	Node* sibling;
	Node* parent = toDelete->par;
	int locateChild = 0;    // ��������Ľ��ΪҶ�ӽ����Ϊ0�������Ϊ 1.
	if (parent->right == toDelete) {     //��ȡToDelete�����ֵܡ�
		sibling = parent->left;
		locateChild = 1;
	}
	else {
		sibling = parent->right;
	}

	//����ֵܽ����ӽ�㶼Ϊ��ɫ
	if ((sibling->right != NULL && sibling->right->color == 1) || (sibling->left != NULL && sibling->left->color == 1)) {
		if (sibling->right != NULL && sibling->right->color == 1) {

			// �ֵ�Ϊ���׵����ӽ�㣬�ֵܵ��ӽ��Ϊ�ҽ�� 
			if (locateChild == 1) {

				int parColor = parent->color;

				//1.�������ֵܵ��ҽ��
				sibling = leftRotate(sibling->right);

				// 2.�������ֵ�
				parent = rightRotate(sibling);

				// �����ת���Ƿ�Ϊ��
				if (parent->par == NULL) {
					*root = parent;
				}

				// 3.�ı���ɫ
				parent->color = parColor;
				parent->left->color = 0;
				parent->right->color = 0;

				// 4.�ѽ��ɾ��
				if (Delete) {
					if (toDelete->left != NULL) {
						toDelete->left->par = parent->right;
					}
					parent->right->right = toDelete->left;
					free(toDelete);
				}

			}
			else {   //�ֵ�Ϊ���׵����ӽ�㣬 �ֵ�Ҳ���ڵ����ӽ��

				int parColor = parent->color;

				// 1.�������ֵܽ��
				parent = leftRotate(sibling);

				//�����ת���Ƿ�Ϊ��
				if (parent->par == NULL) {
					*root = parent;
				}

				// ������ɫ
				parent->color = parColor;
				parent->left->color = 0;
				parent->right->color = 0;

				// 2.ɾ�����
				if (Delete) {
					if (toDelete->right != NULL) {
						toDelete->right->par = parent->left;
					}
					parent->left->left = toDelete->left;
					free(toDelete);
				}

			}
		}
		else {

			// �ֵ�Ϊ���׵����ӽ�㣬�ֵܺ���Ϊ���ӽ�� 
			if (locateChild == 0) {

				int parColor = parent->color;   //��¼���׵���ɫ

				//  1�� �����ֵܵ����ӽ��
				sibling = rightRotate(sibling->left);


				// 2.�����ֵܽ��
				parent = leftRotate(sibling);

				// �����ת���Ƿ�Ϊ�����
				if (parent->par == NULL) {
					*root = parent;
				}

				// ������ɫ
				parent->color = parColor;
				parent->left->color = 0;
				parent->right->color = 0;

				// 3.ɾ�����
				if (Delete) {
					if (toDelete->right != NULL) {
						toDelete->right->par = parent->left;
					}
					parent->left->left = toDelete->right;
					free(toDelete);
				}


			}
			else {   //�ֵ�Ϊ���ӽ�㣬�ֵܵĺ���ҲΪ���ӽ��

				int parColor = parent->color;

				// �����ֵ�
				parent = rightRotate(sibling);

				// �����ת���Ƿ�Ϊ��
				if (parent->par == NULL) {
					*root = parent;
				}

				// ������ɫ 
				parent->color = parColor;
				parent->left->color = 0;
				parent->right->color = 0;

				//ɾ�����
				if (Delete) {
					if (toDelete->left != NULL) {
						toDelete->left->par = parent->right;
					}
					parent->right->right = toDelete->left;
					free(toDelete);
				}

			}
		}
	}
	else if (sibling->color == 0) {						 //����ֵܵ���ɫΪ��ɫ

		// �ı�Ϊ��ɫ
		sibling->color = 1;

		
		if (Delete) { 
			if (locateChild) {							//ɾ������λ���ڸ������ұ�
				toDelete->par->right = toDelete->left;
				if (toDelete->left != NULL) {
					toDelete->left->par = toDelete->par;
				}
			}
			else {
				toDelete->par->left = toDelete->right;  //ɾ������λ���ڸ��������
				if (toDelete->right != NULL) {
					toDelete->right->par = toDelete->par;
				}
			}
		}

		checkForCase2(parent, 0, locateChild, root);           
	}   
	else {   
		if (locateChild) {    //����

			toDelete->par->right = toDelete->left;
			if (toDelete->left != NULL) {
				toDelete->left->par = toDelete->par;
			}

			parent = rightRotate(sibling);

			//�ж���ת���Ƿ�Ϊ�����
			if (parent->par == NULL) {
				*root = parent;
			}

			parent->color = 0;
			parent->right->color = 1;
			checkForCase2(parent->right, 0, 1, root);
		}
		else {   // ����

			toDelete->par->left = toDelete->right;
			if (toDelete->right != NULL) {
				toDelete->right->par = toDelete->par;
			}
			parent = leftRotate(sibling);

			//�ж���ת���Ƿ�Ϊ�����
			if (parent->par == NULL) {
				*root = parent;
			}

			parent->color = 0;
			parent->left->color = 1;
			checkForCase2(parent->left, 0, 0, root);
		}
	}        //

}

//���Ľ��ɾ��
void deleteNode(int val, Node** root) {
	Node* buffRoot = *root;

	//���ҵ�Ҫɾ���Ľ��
	while (1) {

		if (val == buffRoot->val) 
		{
			break;
		}

		if (val > buffRoot->val) {                //���ҳ�������
			if (buffRoot->right != NULL) {
				buffRoot = buffRoot->right;
			}
			else {
				cout << "Not found" << endl;
				return;
			}
		}
		else {
			if (buffRoot->left != NULL) {        //�����������
				buffRoot = buffRoot->left;
			}
			else {
				cout << "Not found" << endl;
				return;
			}
		}
	}

	Node* toDelete = buffRoot;

	// �鿴����߽�����Ҷ�ӽ�㣬�����ұ߽�� ����Ҷ�ӽ��
	if (toDelete->left != NULL) {
		toDelete = toDelete->left;
		while (toDelete->right != NULL) {
			toDelete = toDelete->right;
		}
	}
	else if (toDelete->right != NULL) {
		toDelete = toDelete->right;
		while (toDelete->left != NULL) {
			toDelete = toDelete->left;
		}
	}
	if (toDelete == *root) {
		*root = NULL;
		return;
	}

	// ����ֵ
	buffRoot->val = toDelete->val;
	toDelete->val = val;

	// ����Ƿ�Ϊ��һ�����
	if (toDelete->color == 1 || (toDelete->left != NULL && toDelete->left->color == 1) || (toDelete->right != NULL && toDelete->right->color == 1)) {

		// �����Ҷ�ӽ��
		if (toDelete->left == NULL && toDelete->right == NULL) {
			// ֱ��ɾ��
			if (toDelete->par->left == toDelete) {
				toDelete->par->left = NULL;
			}
			else {
				toDelete->par->right = NULL;
			}
		}
		else {   //���ɾ�����ĺ��ӽ��Ϊ��ɫ

			//����Ƿ��������
			if (toDelete->left != NULL) {
				//����������Ϊɾ�����µĸ����
				toDelete->par->right = toDelete->left;
				toDelete->left->par = toDelete->par;
				toDelete->left->color = 1;
			}
			else {   //���Һ�������Ϊɾ������µĸ����
				toDelete->par->left = toDelete->right;
				toDelete->right->par = toDelete->par;
				toDelete->right->color = 1;
			}
		}

		
		free(toDelete);
	}
	else {   // ���2 
		checkForCase2(toDelete, 1, ((toDelete->par->right == toDelete)), root);
	}



}


//�����ӡ���Ľ��ֵ����ɫ
void printInorder(Node* root) {
	if (root != NULL) {
		printInorder(root->left);
		printf("%d c-%d ", root->val, root->color);
		printInorder(root->right);
	}
}



//������к�ɫ�ĸ���
void checkBlack(Node* temp, int c) {
	if (temp == NULL) {
		printf("%d ", c);
		return;
	}
	if (temp->color == 0) {
		c++;
	}
	checkBlack(temp->left, c);
	checkBlack(temp->right, c);
}

