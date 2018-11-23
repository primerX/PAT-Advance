#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 10;	// 最大结点数 

// 定义二叉树的静态结构 
struct Node{
	int data, lchild, rchild;
}node[MAXN];

// 记录是否不是根结点，初始时均是根结点 
bool notRoot[MAXN] = {false}; 
int n, num = 0;

// 函数 print 输出结点 id 的编号 
void print(int id)
{
	printf("%d", id);
	num++;
	if(num < n) printf(" ");
	else printf("\n");
}

// 利用后序遍历反转一颗二叉树 
void postOrder(int root)
{
	if(root == -1) return;	// 空节点
	// 访问左子树 
	postOrder(node[root].lchild);
	// 访问右子树 
	postOrder(node[root].rchild);
	// 交换左右结点 
	swap(node[root].lchild, node[root].rchild);
}

// 层序遍历 
void layerOrder(int root)
{
	queue<int> q;	// 队列里面存的是地址(在这里代表下标)
	q.push(root);
	while(!q.empty())
	{
		int now = q.front();	//取出队列首元素
		q.pop();
		print(now);
		if(node[now].lchild != -1) q.push(node[now].lchild);
		if(node[now].rchild != -1) q.push(node[now].rchild);
	}
}

// 中序遍历
void inOrder(int root)
{
	if(root == -1){
		return;
	}
	// 递归访问左子树 
	inOrder(node[root].lchild);
	// 访问根结点 
	print(root);
	// 访问右子树
	inOrder(node[root].rchild); 
}

int strToNum(char c)
{
	if(c == '-') return -1;
	else{
		notRoot[c-'0'] = true;	// 标记c不是根结点
		return c - '0'; 
	}
}

int findRoot()
{
	for(int i = 0; i < n; i++){
		// i 是根结点 
		if(notRoot[i] == false){
			return i;
		}
	}
}

int main()
{
	char c;
	scanf("%d", &n);
	int lchild, rchild;
	for(int i = 0; i < n; i++){
		getchar();	//吸收换行符 
		scanf("%c %c", &lchild, &rchild);
		node[i].lchild = strToNum(lchild);
		node[i].rchild = strToNum(rchild);
	}
	int root = findRoot();	//获取根结点编号 
	// 反转二叉树 
	postOrder(root);	// 根结点的下标为 0 
	layerOrder(root);	// 层序遍历 
	num = 0;
	inOrder(root);		// 中序遍历 
	return 0;
}
