// tire.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//字典树

//Tire树的基本性质可以归纳为：
//
//（1）根结点不包含字符，其他的每一个节点只包含一个字符；
//
//（2）从根结点到某一节点，路径上经过的字符连接起来，为该节点对应的字符串；
//
//（3）每个节点的所有子节点包含的字符都不相同。


#include <iostream>

using namespace std;

#define ALPHABET_SIZE 26

struct TrieNode
{
	struct TrieNode* childern[ALPHABET_SIZE];    //记录26根指针的指针数组
	char character;								 //记录结点的字符值
	bool isEndOfWord;							 //检查是否为字符串的最后有一个字符
};


//树结点的创建
TrieNode* trieNodeInit()
{
	
	auto node = new TrieNode;
	node->isEndOfWord = false;
	int i = 0;
	while (i<ALPHABET_SIZE)
	{
		node->childern[i] = NULL;
		i++;
	}
	return node;
}



//字符插入操作
void insert(TrieNode* root, char* word)
{
	 
	if (strlen(word) - 1 != 0)             //检查字符串是否为空字符
	{
		char character = *word;
		if (root->childern[character - 97] == NULL)
		{
			
			TrieNode* node = trieNodeInit();
			node->character = character;
			root->childern[character - 97] = node;
		}
		word++;
		insert(root->childern[character - 97], word);   //递归插入字符
	}
	else
	{
		root->isEndOfWord = true;
	}
	return;
}



//字符查找
TrieNode* search(TrieNode* root, char* word)
{
	
	while (*word != '\0')
	{
		char character = *word;
		if (root->childern[character - 97] != NULL)
		{
			auto temp = root->childern[character - 97];
			word++;
			root = temp;
		}
		else
		{
			cout << "NOT FOUND" << endl;
			return NULL;
		}
	}
	return root;
}



//打印字符串
void printArray(char chars[], int len)
{
	int i = 0;
	for (i; i < len; i++)
	{
		cout << chars[i];
	}
	cout << endl;

}


//字符串清空操作
void deleteTire(TrieNode* root)
{
	int i = 0;
	for (i; i < ALPHABET_SIZE; i++)
	{
		free(root->childern[i]);
	}

}

//打印查找的路径
void printPathsRecur(TrieNode* node, char prefix[], int filledLen)
{
	if (node == NULL)
		return;
	prefix[filledLen] = node->character;
	filledLen++;

	if (node->isEndOfWord)
		printArray(prefix, filledLen);
	
	for (int i = 0; i < ALPHABET_SIZE; i++)          //递归查找到最后
	{
		printPathsRecur(node->childern[i], prefix, filledLen);
	}

}


//反转字典树
void traverse(char prefix[], TrieNode* root)
{
	TrieNode* temp = search(root, prefix);
	int j = 0;
	while (prefix[j] != '\0')
	{
		j++;
	}
	printPathsRecur(temp, prefix, j - 1);
}