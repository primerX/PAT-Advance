#include<iostream>
#include<algorithm>
using namespace std;

struct node{
	int v, height;	//v ΪȨֵ��height Ϊ��ǰ�����߶� 
	node *lchild, *rchild;
};

// ����һ���½�� 
node* newNode(int v)
{
	node *root = new node;	// ����һ�� node �ͱ����ĵ�ַ�ռ� 
	root->v = v;
	root->height = 1;
	root->lchild = root->rchild = NULL;
	return root;
}

// ��ȡ�� root Ϊ�����������ĵ�ǰ height
int getHeight(node *root)
{
	if(root == NULL) return 0;
	else return root->height;
}

// ���¸����� height
void updateHeight(node *root)
{
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
} 

// ��ȡƽ������ 
int getBalanceFactor(node *root)
{
	return getHeight(root->lchild) - getHeight(root->rchild);
}

// ����
void LR(node* &root)
{
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

// ����
void RR(node* &root)
{
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

// ����ȨֵΪ v �Ľ��
void insert(node* &root, int v)
{
	if(root == NULL){	//����սڵ㣬��Ҫ����ĵط� 
		root = newNode(v);
		return;
	}
	if(v < root->v){	// v �ȸ����ȨֵС 
		insert(root->lchild, v);	//������������
		updateHeight(root);		//��������
		if(getBalanceFactor(root) == 2){	// ʧ�� 
			if(getBalanceFactor(root->lchild) == 1){ // LL �� 
				RR(root);		//���� 
			}else if(getBalanceFactor(root->lchild) == -1){	// LR�� 
				LR(root->lchild);
				RR(root);
			}
		}
	}else{		// v �ȸ����Ȩֵ�� 
		insert(root->rchild, v);		//������������
		updateHeight(root);
		if(getBalanceFactor(root) == -2){	//ʧ��
			if(getBalanceFactor(root->rchild) == -1){	// RR�� 
				LR(root);
			}else if(getBalanceFactor(root->rchild) == 1){ //RL �� 
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
	printf("%d\n", root->v);	// ���������ֵ 
	return 0;
}
