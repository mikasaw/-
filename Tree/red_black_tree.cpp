

//红黑树的特性:
//（1）每个节点或者是黑色，或者是红色。
//（2）根节点是黑色。
//（3）每个叶子节点（NIL）是黑色。[注意：这里叶子节点，是指为空(NIL或NULL)的叶子节点！]
//（4）如果一个节点是红色的，则它的子节点必须是黑色的。
//（5）从一个节点到该节点的子孙节点的所有路径上包含相同数目的黑节点。

// 特性(3)中的叶子节点，是只为空(NIL或null)的节点。
// 特性(5)，确保没有一条路径会比其他路径长出俩倍。因而，红黑树是相对是接近平衡的二叉树。


#include<iostream>

using namespace std;



struct Node {
	int val;
	Node* par;
	Node* left;
	Node* right;
	int color;            // 0为黑色，1为红色
};

//创建节点
Node* newnode(int val, Node* par)
{
	//Node* newnode = (Node*)malloc(sizeof(Node));
	Node* newnode = new Node;
	newnode->val = val;
	newnode->par = par;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->color = 1;   //颜色初始化为红色
	
	return newnode;

}

//检查一个节点是否为叶子
bool isleaf(Node* n)
{
	if (n->left == NULL || n->right == NULL)
		return true;
	else
		return false;
}


//左旋
Node* leftRotate(Node* lnode)
{
	
		Node* parent = lnode->right;                  //把旋转结点的右子结点作为新的父亲存储
		Node* grandParent = lnode->par;               //把祖父的信息存储


		parent->left = lnode;
		if (lnode->right != NULL)                     //把结点的右子树父亲设为祖父
			lnode->right->par = grandParent;

		lnode->par = parent;
		lnode->right = parent->left;                  // 把新父亲的左子节点移动成为旋转结点的右结点
		parent->left->par = lnode; 
			                                          
		if (grandParent != NULL)                      //判断新的父结点的位置     
		{
			if (grandParent->right == parent)     //在左边就成为根结点的左子结点
				grandParent->right = parent;
			else
				grandParent->left = parent;   //在右边就成为根结点的右子结点 
			
		}
	
	return lnode;
}





//右旋  分析同上
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


//在插入操作后调整树
void checkNode(Node* node) {

	// 节点为根结点
	if (node == NULL || node->par == NULL) {
		return;
	}
	Node* child = node;
	// 父子都是黑色节点
	if (node->color == 0 || (node->par)->color == 0) {
		return;
	}

	// 父子都是红色节点
	// 检查叔父
	Node* parent = node->par;
	Node* grandParent = parent->par;

	//爷爷为空，父亲为根节点
	if (grandParent == NULL) {
		parent->color = 0;
		return;
	}

	//孩子和爷爷都为黑色
	if (grandParent->right != NULL && (grandParent->right)->color == 1 
		&& grandParent->left != NULL && (grandParent->left)->color == 1)
	{
		(grandParent->right)->color = 0;
		(grandParent->left)->color = 0;
		 grandParent->color = 1;
		return;
	}
	else {
		  //在左边的情况
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

				// 改变颜色
				parent->color = 0;
				grandParent->color = 1;
			}
			else {   
				// 父亲和孩子旋转
				parent->left = child->right;
				if (child->right != NULL) {
					(child->right)->par = parent;
				}
				child->right = parent;
				parent->par = child;

				// 孩子和祖父旋转
				grandParent->right = child->left;
				if (child->left != NULL) {
					(child->left)->par = grandParent;
				}
				child->left = grandParent;
				grandParent->par = child;

				// 附加到树上
				child->par = greatGrandParent;
				if (greatGrandParent != NULL) {
					if (greatGrandParent->left != NULL && greatGrandParent->left == grandParent) {
						greatGrandParent->left = child;
					}
					else {
						greatGrandParent->right = child;
					}
				}

				// 改变孩子和祖父颜色
				child->color = 0;
				grandParent->color = 1;
			}
		}
		else {   //左边情况
			
			if (parent->left == node) {
				grandParent->left = parent->right;
				if (parent->right != NULL) {
					(parent->right)->par = grandParent;
				}
				parent->right = grandParent;
				grandParent->par = parent;

				// 附加到树上
				parent->par = greatGrandParent;
				if (greatGrandParent != NULL) {
					if (greatGrandParent->left != NULL && greatGrandParent->left == grandParent) {
						greatGrandParent->left = parent;
					}
					else {
						greatGrandParent->right = parent;
					}
				}

				// 改变孩子和祖父的颜色
				parent->color = 0;
				grandParent->color = 1;
			}
			else {   //Left Right Case

				// 旋转父亲和孩子
				parent->right = child->left;
				if (child->left != NULL) {
					(child->left)->par = parent;
				}
				child->left = parent;
				parent->par = child;

				// 旋转孩子和祖父
				grandParent->left = child->right;
				if (child->right != NULL) {
					(child->right)->par = grandParent;
				}
				child->right = grandParent;
				grandParent->par = child;

				// 附加到树上
				child->par = greatGrandParent;
				if (greatGrandParent != NULL) {
					if (greatGrandParent->left != NULL && greatGrandParent->left == grandParent) {
						greatGrandParent->left = child;
					}
					else {
						greatGrandParent->right = child;
					}
				}

				// 改变孩子和祖父的颜色
				child->color = 0;
				grandParent->color = 1;
			}
		}
	}
}




//在树上插入结点
void insertNode(int val, Node* root)
{
	Node* buffRoot = root;
	while (buffRoot)                  				  //递归找到合适的位置。
	{
		if (buffRoot->val > val)
		{
			if (buffRoot->left != NULL)
				buffRoot = buffRoot->left;
			else
			{
				buffRoot->left = newnode(val, buffRoot);   //找不到则创建新的结点
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
		checkNode(buffRoot);                 			 //对插入结点后的树进行调整
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

//采用递归来调整树(在删除操作后)
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


	// 获取结点亲戚的信息来进行进一步调整
	Node* sibling;
	Node* parent = toDelete->par;
	int locateChild = 0;    		 // 如果调整的结点为叶子结点则为0，父结点为 1.
	if (parent->right == toDelete) {    	 //获取ToDelete结点的兄弟。
		sibling = parent->left;
		locateChild = 1;
	}
	else {
		sibling = parent->right;
	}

	//如果兄弟结点的子结点都为红色
	if ((sibling->right != NULL && sibling->right->color == 1) || (sibling->left != NULL && sibling->left->color == 1)) {
		if (sibling->right != NULL && sibling->right->color == 1) {

			// 兄弟为父亲的左子结点，兄弟的子结点为右结点 
			if (locateChild == 1) {

				int parColor = parent->color;

				//1.先左旋兄弟的右结点
				sibling = leftRotate(sibling->right);

				// 2.再右旋兄弟
				parent = rightRotate(sibling);

				// 检查旋转点是否为根
				if (parent->par == NULL) {
					*root = parent;
				}

				// 3.改变颜色
				parent->color = parColor;
				parent->left->color = 0;
				parent->right->color = 0;

				// 4.把结点删除
				if (Delete) {
					if (toDelete->left != NULL) {
						toDelete->left->par = parent->right;
					}
					parent->right->right = toDelete->left;
					free(toDelete);
				}

			}
			else {   //兄弟为父亲的右子结点， 兄弟也存在的右子结点

				int parColor = parent->color;

				// 1.先左旋兄弟结点
				parent = leftRotate(sibling);

				//检查旋转点是否为根
				if (parent->par == NULL) {
					*root = parent;
				}

				// 更改颜色
				parent->color = parColor;
				parent->left->color = 0;
				parent->right->color = 0;

				// 2.删除结点
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

			// 兄弟为父亲的右子结点，兄弟孩子为左子结点 
			if (locateChild == 0) {

				int parColor = parent->color;   //记录父亲的颜色

				//  1。 右旋兄弟的左子结点
				sibling = rightRotate(sibling->left);


				// 2.左旋兄弟结点
				parent = leftRotate(sibling);

				// 检查旋转点是否为根结点
				if (parent->par == NULL) {
					*root = parent;
				}

				// 更改颜色
				parent->color = parColor;
				parent->left->color = 0;
				parent->right->color = 0;

				// 3.删除结点
				if (Delete) {
					if (toDelete->right != NULL) {
						toDelete->right->par = parent->left;
					}
					parent->left->left = toDelete->right;
					free(toDelete);
				}


			}
			else {   //兄弟为左子结点，兄弟的孩子也为左子结点

				int parColor = parent->color;

				// 右旋兄弟
				parent = rightRotate(sibling);

				// 检查旋转点是否为根
				if (parent->par == NULL) {
					*root = parent;
				}

				// 更改颜色 
				parent->color = parColor;
				parent->left->color = 0;
				parent->right->color = 0;

				//删除结点
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
	else if (sibling->color == 0) {						                //如果兄弟的颜色为黑色

		// 改变为红色
		sibling->color = 1;

		
		if (Delete) { 
			if (locateChild) {							//删除结点的位置在父结点的右边
				toDelete->par->right = toDelete->left;
				if (toDelete->left != NULL) {
					toDelete->left->par = toDelete->par;
				}
			}
			else {
				toDelete->par->left = toDelete->right;  			//删除结点的位置在父结点的左边
				if (toDelete->right != NULL) {
					toDelete->right->par = toDelete->par;
				}
			}
		}

		checkForCase2(parent, 0, locateChild, root);           
	}   
	else {   
		if (locateChild) {    //右旋

			toDelete->par->right = toDelete->left;
			if (toDelete->left != NULL) {
				toDelete->left->par = toDelete->par;
			}

			parent = rightRotate(sibling);

			//判断旋转点是否为根结点
			if (parent->par == NULL) {
				*root = parent;
			}

			parent->color = 0;
			parent->right->color = 1;
			checkForCase2(parent->right, 0, 1, root);
		}
		else {   // 左旋

			toDelete->par->left = toDelete->right;
			if (toDelete->right != NULL) {
				toDelete->right->par = toDelete->par;
			}
			parent = leftRotate(sibling);

			//判断旋转点是否为根结点
			if (parent->par == NULL) {
				*root = parent;
			}

			parent->color = 0;
			parent->left->color = 1;
			checkForCase2(parent->left, 0, 0, root);
		}
	}        //

}

//树的结点删除
void deleteNode(int val, Node** root) {
	Node* buffRoot = *root;

	//先找到要删除的结点
	while (1) {

		if (val == buffRoot->val) 
		{
			break;
		}

		if (val > buffRoot->val) {                //向右持续查找
			if (buffRoot->right != NULL) {
				buffRoot = buffRoot->right;
			}
			else {
				cout << "Not found" << endl;
				return;
			}
		}
		else {
			if (buffRoot->left != NULL) {        //向左持续查找
				buffRoot = buffRoot->left;
			}
			else {
				cout << "Not found" << endl;
				return;
			}
		}
	}

	Node* toDelete = buffRoot;

	// 查看最左边结点的右叶子结点，和最右边结点 的左叶子结点
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

	// 交换值
	buffRoot->val = toDelete->val;
	toDelete->val = val;

	// 检查是否为第一种情况
	if (toDelete->color == 1 || (toDelete->left != NULL && toDelete->left->color == 1) || (toDelete->right != NULL && toDelete->right->color == 1)) {

		// 如果是叶子结点
		if (toDelete->left == NULL && toDelete->right == NULL) {
			// 直接删除
			if (toDelete->par->left == toDelete) {
				toDelete->par->left = NULL;
			}
			else {
				toDelete->par->right = NULL;
			}
		}
		else {   //如果删除结点的孩子结点为红色

			//检查是否存在左孩子
			if (toDelete->left != NULL) {
				//把左孩子提升为删除后新的父结点
				toDelete->par->right = toDelete->left;
				toDelete->left->par = toDelete->par;
				toDelete->left->color = 1;
			}
			else {   //把右孩子提升为删除后的新的父结点
				toDelete->par->left = toDelete->right;
				toDelete->right->par = toDelete->par;
				toDelete->right->color = 1;
			}
		}

		
		free(toDelete);
	}
	else {   // 情况2 
		checkForCase2(toDelete, 1, ((toDelete->par->right == toDelete)), root);
	}



}


//中序打印树的结点值和颜色
void printInorder(Node* root) {
	if (root != NULL) {
		printInorder(root->left);
		printf("%d c-%d ", root->val, root->color);
		printInorder(root->right);
	}
}



//检查树中黑色的个数
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

