#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int MAXN = 110;
struct Node{		//二叉树结点的静态写法 
	int data;
	int lchild, rchild; 
}node[MAXN];

// n 为结点个数，in 为中序序列, num 为已经填入的结点个数
int n, in[MAXN], num = 0;

// 中序遍历，将排序号的序列依次填入二叉树结点中
void inOrder(int root)
{
	if(root == -1){		//此节点不存在 
		return;
	}
	inOrder(node[root].lchild);
	node[root].data = in[num++];	//填入序列中的整数 
	inOrder(node[root].rchild);
}

// 层序遍历(BFS)
void BFS(int root)
{
	queue<int> q;
	q.push(root);
	num = 0;		// 用来控制输出格式 
	while(!q.empty()){	//队列不为空时 
		int now = q.front();	//取出队列队首元素 
		q.pop();
		printf("%d", node[now].data);
		num++;
		if(num < n) printf(" ");
		if(node[now].lchild != -1) q.push(node[now].lchild);
		if(node[now].rchild != -1) q.push(node[now].rchild); 
	}
}

int main()
{
	int lchild, rchild;
	scanf("%d", &n);	//结点个数
	for(int i = 0; i < n; i++){
		scanf("%d %d", &lchild, &rchild);	//左右孩子结点编号
		node[i].lchild = lchild;
		node[i].rchild = rchild; 
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &in[i]);		//输入排序前的序列 
	}
	sort(in, in + n);	//将中序序列从小到大排序
	inOrder(0);		//根结点编号为 0
	BFS(0);			//进行层序遍历(BFS) 
	return 0;
}
