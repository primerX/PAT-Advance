#include<iostream>
#include<queue> 
using namespace std;

struct node{
	int data;
	node *lchild, *rchild;
};

int n;
const int MAXN = 30;		//最大结点数 
int post[MAXN], in[MAXN];	//后序序列，中序序列 

// 后序序列的区间为[posL, posR], 中序序列的区间为[inL, inR]
// 返回的是根结点的地址
node* create(int posL, int posR, int inL, int inR)
{
	if(posL > posR){
		return NULL;		//后序序列长度小于 0 时，返回 
	} 
	node* root = new node;		//创建一个新结点
	root->data = post[posR];
	int k;
	for(k = inL; k <= inR; k++){
		//在中序序列中找到根结点的位置 
		if(in[k] == post[posR]) break;
	} 
	int numLeft = k - inL;	//左子树的结点个数
	// 返回左子树的根结点的地址 
	root->lchild = create(posL, posL+numLeft-1, inL, k-1);
	// 返回右子树的根结点的地址 
	root->rchild = create(posL+numLeft, posR-1, k+1, inR); 
	// 返回根结点的地址
	return root;
} 

// 层序遍历 
int num = 0;		//用来记录已经输出的结点个数 
void layerOrder(node* root)
{
	queue<node*> q;		//队列里面存的是地址
	q.push(root);
	while(!q.empty())	//队列不为空时
	{
		node* now = q.front();		//将队首元素出列
		q.pop();
		printf("%d", now->data);	// 访问队首元素
		num++; 
		if(num < n) printf(" ");
		if(now->lchild != NULL){		//左子树不为空 
			q.push(now->lchild);
		} 
		if(now->rchild != NULL){		//右子树不为空 
			q.push(now->rchild);
		}
	}
}

int main()
{
	cin >> n;	
	for(int i = 0; i < n; i++){
		cin >> post[i]; 
	}
	for(int i = 0; i < n; i++){
		cin >> in[i];
	}
	node* root = create(0, n-1, 0, n-1);	//建立一棵二叉树
	layerOrder(root);		//进行层序遍历 
	return 0;
 } 
