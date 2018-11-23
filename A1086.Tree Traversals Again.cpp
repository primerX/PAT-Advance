#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

const int MAXN = 30;	//最大结点个数 

struct node{	// 定义二叉树的结点 
	int data;
	node *lchild, *rchild;
};

// 结点个数，先序序列，中序序列 
int n, preOrder[MAXN], inOrder[MAXN];

// 根据先序序列[preL, preR]，中序序列[inL, inR]
// 构造一颗二叉树，该函数返回根结点地址
node* create(int preL, int preR, int inL, int inR)
{
	if(preL > preR) return NULL;	// 递归边界
	// 新建一个根结点 
	node *root = new node; 
	root->data = preOrder[preL];
	root->lchild = root->rchild = NULL;
	int k;
	// 用 k 来存储根结点的下标 
	for(k = inL; k <= inR; k++){
		if(inOrder[k] == preOrder[preL]) break;
	}
	// 左子树的结点个数
	int numLeft = k - inL;
	// 递归创建左子树 
	root->lchild = create(preL+1, preL+numLeft, inL, k-1);
	// 递归创建右子树
	root->rchild = create(preL+numLeft+1, preR, k+1, inR);
	// 返回根结点地址
	return root; 
}

// 后序遍历
int num = 0;		// 用来控制输出格式 
void postOrder(node *root)
{
	if(root == NULL){ // 树为空 
		return;
	}
	// 访问左子树 
	postOrder(root->lchild);
	// 访问右子树
	postOrder(root->rchild);
	// 访问根结点
	printf("%d", root->data);
	num++;
	if(num < n) printf(" ");
}

int main()
{
	scanf("%d", &n);
	char str[5];
	stack<int> st;
	// 入栈元素，先序序列位置，后序序列位置 
	int x = 0, preIndex = 0, inIndex = 0;
	for(int i = 0; i < 2*n; i++){
		scanf("%s", &str);
		if(strcmp(str, "Push") == 0){	//入栈
			scanf("%d", &x);
			st.push(x);
			preOrder[preIndex++] = x; 
		}else{		// 出栈
			inOrder[inIndex++] = st.top();
			st.pop(); 
		}
	}
	node *root = create(0, n-1, 0, n-1); // 键树 
	postOrder(root);	// 后序遍历 
	return 0;
}
