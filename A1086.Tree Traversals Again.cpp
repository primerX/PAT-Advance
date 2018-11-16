#include<iostream>
#include<algorithm>
#include<stack>
#include<cstring>
using namespace std;

const int MAXN = 30;

struct node{
	int data;
	node *lchild, *rchild;
};

int pre[MAXN], in[MAXN], post[MAXN];	//先序，中序，后序
int n;		// 结点个数 
 
// 当前二叉树的先序序列为[preL, preR], 中序序列区间为[inL, inR]
// 返回的是二叉树的根结点的地址
node* create(int preL, int preR, int inL, int inR)
{
	if(preL > preR){
		return NULL;	//先序序列长度 <= 0时，直接返回 
	}
	node* root = new node;		//新建一个新的结点
	root->data = pre[preL];
	int k;
	for(k = inL; k <= inR; k++){
		//在中序序列中找到根结点的位置 
		if(in[k] == pre[preL]) break;
	}
	int numLeft = k - inL;		//左子树的结点个数
	root->lchild = create(preL+1, preL+numLeft, inL, k-1);
	root->rchild = create(preL+numLeft+1, preR, k+1, inR);
	return root;	//返回根结点的地址 
 } 
 
int num = 0;	//已经输出的结点个数, 用来控制输出格式
void postorder(node* root)	//后序遍历 
{
	if(root == NULL){
		return;
	}
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d", root->data);
	num++;
	if(num < n){
		printf(" ");
	}
}


int main()
{
	scanf("%d", &n);
	string str;
	stack<int> st;
	int x, preIndex = 0, inIndex = 0;	//入栈元素，先序序列位置和中序序列位置 
	for(int i = 0; i < 2*n; i++){	// 出栈入栈共 2*n 次 
		cin >> str;
		if(str == "Push"){		//入栈
			scanf("%d", &x);
			pre[preIndex++] = x;
			st.push(x); 
		}else{			//出栈 
			in[inIndex++] = st.top();
			st.pop(); 
		}
	}
	node* root = create(0, n-1, 0, n-1);	//建树
	postorder(root);		//后序遍历 
	return 0;
}
