#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 30;	// ������� 

struct node{	// ������������ 
	int data;	//������
	node *lchild, *rchild;	// ָ���� 
};

int n;
int postOrder[MAXN], inOrder[MAXN];

// ���ݺ�������[postL, postR], ��������[inL, inR]
// ����һ�Ŷ����������ظ����ĵ�ַ 
node* create(int postL, int postR, int inL, int inR)
{
	if(postL > postR){	// �ݹ�߽� 
		return NULL;
	}
	// �½�һ���½�㣬������ŵ�ǰ�������ĸ���� 
	node *root = new node;	 
	root->data = postOrder[postR];
	root->lchild = root->rchild = NULL;
	int k;
	for(k = inL; k < inR; k++){
		// �ҵ��������±� 
		if(postOrder[postR] == inOrder[k]) break;
	}
	// numleft Ϊ�������Ľ�����
	int numLeft = k - inL;
	// �ݹ鴴�������� 
	root->lchild = create(postL, postL+numLeft-1, inL, k-1); 
	// �ݹ鴴��������
	root->rchild = create(postL+numLeft, postR-1, k+1, inR); 
	// ���ظ����ĵ�ַ 
	return root;
}

// ��α���
int num = 0;	// �������������ʽ 
void layerOrder(node* root)
{
	queue<node*> q;		//�����������ǵ�ַ
	q.push(root);
	while(!q.empty())
	{
		node* now = q.front();	//ȡ���ж��׵�ַ
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
		// ���������� 
		scanf("%d", &postOrder[i]);
	}
	for(int i = 0; i < n; i++){
		// ����������� 
		scanf("%d", &inOrder[i]);
	}
	node *root = create(0, n-1, 0, n-1);
	layerOrder(root);
	return 0;
}
