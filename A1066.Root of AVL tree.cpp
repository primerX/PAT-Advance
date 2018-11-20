#include<iostream>
#include<algorithm>
using namespace std;

struct node{
	int v, height;	//v 为权值，height 为当前子树高度 
	node *lchild, *rchild;
};

// 生成一个新结点 
node* newNode(int v)
{
	node *root = new node;	// 申请一个 node 型变量的地址空间 
	root->v = v;
	root->height = 1;
	root->lchild = root->rchild = NULL;
	return root;
}

// 获取以 root 为根结点的子树的当前 height
int getHeight(node *root)
{
	if(root == NULL) return 0;
	else return root->height;
}

// 更新根结点的 height
void updateHeight(node *root)
{
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
} 

// 获取平衡因子 
int getBalanceFactor(node *root)
{
	return getHeight(root->lchild) - getHeight(root->rchild);
}

// 左旋
void LR(node* &root)
{
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

// 右旋
void RR(node* &root)
{
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

// 插入权值为 v 的结点
void insert(node* &root, int v)
{
	if(root == NULL){	//到达空节点，即要插入的地方 
		root = newNode(v);
		return;
	}
	if(v < root->v){	// v 比根结点权值小 
		insert(root->lchild, v);	//往左子树插入
		updateHeight(root);		//更新树高
		if(getBalanceFactor(root) == 2){	// 失衡 
			if(getBalanceFactor(root->lchild) == 1){ // LL 型 
				RR(root);		//右旋 
			}else if(getBalanceFactor(root->lchild) == -1){	// LR型 
				LR(root->lchild);
				RR(root);
			}
		}
	}else{		// v 比根结点权值大 
		insert(root->rchild, v);		//往右子树插入
		updateHeight(root);
		if(getBalanceFactor(root) == -2){	//失衡
			if(getBalanceFactor(root->rchild) == -1){	// RR型 
				LR(root);
			}else if(getBalanceFactor(root->rchild) == 1){ //RL 型 
				RR(root->rchild);
				LR(root);
			}
		}
	}
}

int main()
{
	int n, v;
	scanf("%d", &n);
	node* root = NULL;
	for(int i = 0; i < n; i++){
		scanf("%d", &v);
		insert(root, v);
	}
	printf("%d\n", root->v);	// 输出根结点的值 
	return 0;
}
