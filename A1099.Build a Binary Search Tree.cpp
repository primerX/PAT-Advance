#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int MAXN = 110;
struct Node{		//���������ľ�̬д�� 
	int data;
	int lchild, rchild; 
}node[MAXN];

// n Ϊ��������in Ϊ��������, num Ϊ�Ѿ�����Ľ�����
int n, in[MAXN], num = 0;

// ���������������ŵ�����������������������
void inOrder(int root)
{
	if(root == -1){		//�˽ڵ㲻���� 
		return;
	}
	inOrder(node[root].lchild);
	node[root].data = in[num++];	//���������е����� 
	inOrder(node[root].rchild);
}

// �������(BFS)
void BFS(int root)
{
	queue<int> q;
	q.push(root);
	num = 0;		// �������������ʽ 
	while(!q.empty()){	//���в�Ϊ��ʱ 
		int now = q.front();	//ȡ�����ж���Ԫ�� 
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
	scanf("%d", &n);	//������
	for(int i = 0; i < n; i++){
		scanf("%d %d", &lchild, &rchild);	//���Һ��ӽ����
		node[i].lchild = lchild;
		node[i].rchild = rchild; 
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &in[i]);		//��������ǰ������ 
	}
	sort(in, in + n);	//���������д�С��������
	inOrder(0);		//�������Ϊ 0
	BFS(0);			//���в������(BFS) 
	return 0;
}
