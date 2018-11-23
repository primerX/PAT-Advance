#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 30;	// 最大结点数 

struct node{	// 定义二叉树结点 
	int data;	//数据域
	node *lchild, *rchild;	// 指针域 
};

int n;
int postOrder[MAXN], inOrder[MAXN];

// 根据后序序列[postL, postR], 中序序列[inL, inR]
// 构造一颗二叉树，返回根结点的地址 
node* create(int postL, int postR, int inL, int inR)
{
	if(postL > postR){	// 递归边界 
		return NULL;
	}
	// 新建一个新结点，用来存放当前二叉树的根结点 
	node *root = new node;	 
	root->data = postOrder[postR];
	root->lchild = root->rchild = NULL;
	int k;
	for(k = inL; k < inR; k++){
		// 找到根结点的下标 
		if(postOrder[postR] == inOrder[k]) break;
	}
	// numleft 为左子树的结点个数
	int numLeft = k - inL;
	// 递归创建左子树 
	root->lchild = create(postL, postL+numLeft-1, inL, k-1); 
	// 递归创建右子树
	root->rchild = create(postL+numLeft, postR-1, k+1, inR); 
	// 返回根结点的地址 
	return root;
}

// 层次遍历
int num = 0;	// 用来控制输出格式 
void layerOrder(node* root)
{
	queue<node*> q;		//队列里面存的是地址
	q.push(root);
	while(!q.empty())
	{
		node* now = q.front();	//取出列队首地址
		q.pop();
		printf("%d", now->data); 
		num++;
		if(num < n) printf(" ");
		if(now->lchild != NULL) q.push(now->lchild);
		if(now->rchild != NULL) q.push(now->rchild);
	}
} 

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		// 输入后序遍历 
		scanf("%d", &postOrder[i]);
	}
	for(int i = 0; i < n; i++){
		// 输入中序遍历 
		scanf("%d", &inOrder[i]);
	}
	node *root = create(0, n-1, 0, n-1);
	layerOrder(root);
	return 0;
}
