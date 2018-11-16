#include<iostream>
#include<queue> 
using namespace std;

struct node{
	int data;
	node *lchild, *rchild;
};

int n;
const int MAXN = 30;		//������� 
int post[MAXN], in[MAXN];	//�������У��������� 

// �������е�����Ϊ[posL, posR], �������е�����Ϊ[inL, inR]
// ���ص��Ǹ����ĵ�ַ
node* create(int posL, int posR, int inL, int inR)
{
	if(posL > posR){
		return NULL;		//�������г���С�� 0 ʱ������ 
	} 
	node* root = new node;		//����һ���½��
	root->data = post[posR];
	int k;
	for(k = inL; k <= inR; k++){
		//�������������ҵ�������λ�� 
		if(in[k] == post[posR]) break;
	} 
	int numLeft = k - inL;	//�������Ľ�����
	// �����������ĸ����ĵ�ַ 
	root->lchild = create(posL, posL+numLeft-1, inL, k-1);
	// �����������ĸ����ĵ�ַ 
	root->rchild = create(posL+numLeft, posR-1, k+1, inR); 
	// ���ظ����ĵ�ַ
	return root;
} 

// ������� 
int num = 0;		//������¼�Ѿ�����Ľ����� 
void layerOrder(node* root)
{
	queue<node*> q;		//�����������ǵ�ַ
	q.push(root);
	while(!q.empty())	//���в�Ϊ��ʱ
	{
		node* now = q.front();		//������Ԫ�س���
		q.pop();
		printf("%d", now->data);	// ���ʶ���Ԫ��
		num++; 
		if(num < n) printf(" ");
		if(now->lchild != NULL){		//��������Ϊ�� 
			q.push(now->lchild);
		} 
		if(now->rchild != NULL){		//��������Ϊ�� 
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
	node* root = create(0, n-1, 0, n-1);	//����һ�ö�����
	layerOrder(root);		//���в������ 
	return 0;
 } 
