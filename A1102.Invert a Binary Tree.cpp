#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int MAXN = 10;	//最大结点数

struct Node{		//二叉树的静态写法 
	int lchild, rchild; 
}node[MAXN]; 

bool notRoot[MAXN] = {false};	//记录当前结点是否不是根结点，初始时都为根结点
int n, num = 0;		//n 为结点个数，num 为当前输出的结点数

//print() 函数输出结点 id 的编号
void print(int id)
{
	printf("%d", id);
	num++;
	if(num < n) printf(" ");
	else printf("\n");
}

//中序遍历
void inOrder(int root)
{
	if(root == -1) return;
	inOrder(node[root].lchild);
	print(root);
	inOrder(node[root].rchild);
 }

// 层序遍历
void layerOrder(int root)
{
	queue<int> q;		//队列q 里面存的是地址
	q.push(root);
	while(!q.empty())
	{
		int now = q.front();	//取出队列首地址 
		q.pop();
		print(now);
		if(node[now].lchild != -1) q.push(node[now].lchild);	//左子树非空
		if(node[now].rchild != -1) q.push(node[now].rchild);	//右子树非空 
	 } 
 } 
 
 
 //后序遍历，用来反转二叉树
void postOrder(int root)
{
	if(root == -1){
		return;
	}
	postOrder(node[root].lchild);
	postOrder(node[root].rchild);
	swap(node[root].lchild, node[root].rchild);	//交换左右孩子结点 
}

// 寻找根结点的编号 
int findRoot()
{
	for(int i = 0; i < n; i++){
		if(notRoot[i] == false){
			return i;
		}
	}
}

// 将输入的字符转换为 -1 或结点编号 
int stoNum(char c)
{
	if(c == '-') return -1;
	else{
		notRoot[c-'0'] = true;	//此节点不是根结点
		return c - '0'; 
	}
}

int main()
{
	char lchild, rchild;
	scanf("%d", &n);	//结点个数
	for(int i = 0; i < n; i++){
		getchar();		//吸收换行符 
		scanf("%c %c", &lchild, &rchild);
		node[i].lchild = stoNum(lchild);
		node[i].rchild = stoNum(rchild);
	}
	int root = findRoot();	//获得根结点的编号
	postOrder(root);		//后序遍历，反转二叉树
	layerOrder(root);		//输出层序遍历序列
	num = 0;	//将输出的结点个数置为 ）
	inOrder(root);		//输出中序遍历的序列 
 } 
