#include<iostream>
#include<vector>
using namespace std;

struct node{
	int data;	//数据域
	node *left, *right;	//指针域 
};

void insert(node* &root, int x)
{
	if(root == NULL){	//要插入的位置 
		root = new node;
		root->data = x;
		root->left = root->right = NULL;
		return;
	}
	if(x < root->data){
		insert(root->left, x);
	}else{
		insert(root->right, x);
	}
}

void preOrder(node *root, vector<int> &vi)	//先序遍历, 结果存在 vi 中 
{
	if(root == NULL) return;
	vi.push_back(root->data);
	preOrder(root->left, vi);
	preOrder(root->right, vi);
}

// 镜像数的先序遍历, 结果存在 vi 中 
void preOrderMirror(node *root, vector<int> &vi)
{
	if(root == NULL) return;
	vi.push_back(root->data);
	preOrderMirror(root->right, vi);
	preOrderMirror(root->left, vi);
}

// 后序遍历，结果存放在 vi 中
void postOrder(node *root, vector<int> &vi)
{
	if(root == NULL) return;
	postOrder(root->left, vi);
	postOrder(root->right, vi);
	vi.push_back(root->data);
}

// 镜像书的后序遍历，结果存放在 vi 中
void postOrderMirror(node* root, vector<int> &vi)
{
	if(root == NULL) return;
	postOrderMirror(root->right, vi);
	postOrderMirror(root->left, vi);
	vi.push_back(root->data);
}

// origin 为初始序列，pre, post 为先序，后序， preM, postM 为镜像树先序后序 
vector<int> origin, pre, post, preM, postM;
int main()
{
	int n, data;
	node* root = NULL;	// 定义根结点 
	scanf("%d", &n);	//结点个数
	for(int i = 0; i < n; i++){
		scanf("%d", &data);
		origin.push_back(data);
		insert(root, data);		// 构建二叉搜索树 
	}
	preOrder(root, pre);			//求先序序列
	preOrderMirror(root, preM);		//求镜像树的先序序列
	postOrder(root, post);			//求后序序列
	postOrderMirror(root, postM);	//求镜像树的后序序列
	if(origin == pre){		//初始序列等于先序序列 
		printf("YES\n");
		for(int i = 0; i < post.size(); i++){
			printf("%d", post[i]);
			if(i < post.size() - 1) printf(" ");
		}
	}else if(origin == preM){	//初始序列等于镜像树的先序序列 
		printf("YES\n");
		for(int i = 0; i < postM.size(); i++){
			printf("%d", postM[i]);
			if(i < postM.size() - 1) printf(" ");
		} 
	}else{
		printf("NO\n");
	}
	return 0;
}
