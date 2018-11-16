#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int MAXN = 10;	//�������

struct Node{		//�������ľ�̬д�� 
	int lchild, rchild; 
}node[MAXN]; 

bool notRoot[MAXN] = {false};	//��¼��ǰ����Ƿ��Ǹ���㣬��ʼʱ��Ϊ�����
int n, num = 0;		//n Ϊ��������num Ϊ��ǰ����Ľ����

//print() ���������� id �ı��
void print(int id)
{
	printf("%d", id);
	num++;
	if(num < n) printf(" ");
	else printf("\n");
}

//�������
void inOrder(int root)
{
	if(root == -1) return;
	inOrder(node[root].lchild);
	print(root);
	inOrder(node[root].rchild);
 }

// �������
void layerOrder(int root)
{
	queue<int> q;		//����q �������ǵ�ַ
	q.push(root);
	while(!q.empty())
	{
		int now = q.front();	//ȡ�������׵�ַ 
		q.pop();
		print(now);
		if(node[now].lchild != -1) q.push(node[now].lchild);	//�������ǿ�
		if(node[now].rchild != -1) q.push(node[now].rchild);	//�������ǿ� 
	 } 
 } 
 
 
 //���������������ת������
void postOrder(int root)
{
	if(root == -1){
		return;
	}
	postOrder(node[root].lchild);
	postOrder(node[root].rchild);
	swap(node[root].lchild, node[root].rchild);	//�������Һ��ӽ�� 
}

// Ѱ�Ҹ����ı�� 
int findRoot()
{
	for(int i = 0; i < n; i++){
		if(notRoot[i] == false){
			return i;
		}
	}
}

// ��������ַ�ת��Ϊ -1 ������ 
int stoNum(char c)
{
	if(c == '-') return -1;
	else{
		notRoot[c-'0'] = true;	//�˽ڵ㲻�Ǹ����
		return c - '0'; 
	}
}

int main()
{
	char lchild, rchild;
	scanf("%d", &n);	//������
	for(int i = 0; i < n; i++){
		getchar();		//���ջ��з� 
		scanf("%c %c", &lchild, &rchild);
		node[i].lchild = stoNum(lchild);
		node[i].rchild = stoNum(rchild);
	}
	int root = findRoot();	//��ø����ı��
	postOrder(root);		//�����������ת������
	layerOrder(root);		//��������������
	num = 0;	//������Ľ�������Ϊ ��
	inOrder(root);		//���������������� 
 } 
