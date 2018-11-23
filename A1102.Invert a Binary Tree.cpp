#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 10;	// ������� 

// ����������ľ�̬�ṹ 
struct Node{
	int data, lchild, rchild;
}node[MAXN];

// ��¼�Ƿ��Ǹ���㣬��ʼʱ���Ǹ���� 
bool notRoot[MAXN] = {false}; 
int n, num = 0;

// ���� print ������ id �ı�� 
void print(int id)
{
	printf("%d", id);
	num++;
	if(num < n) printf(" ");
	else printf("\n");
}

// ���ú��������תһ�Ŷ����� 
void postOrder(int root)
{
	if(root == -1) return;	// �սڵ�
	// ���������� 
	postOrder(node[root].lchild);
	// ���������� 
	postOrder(node[root].rchild);
	// �������ҽ�� 
	swap(node[root].lchild, node[root].rchild);
}

// ������� 
void layerOrder(int root)
{
	queue<int> q;	// �����������ǵ�ַ(����������±�)
	q.push(root);
	while(!q.empty())
	{
		int now = q.front();	//ȡ��������Ԫ��
		q.pop();
		print(now);
		if(node[now].lchild != -1) q.push(node[now].lchild);
		if(node[now].rchild != -1) q.push(node[now].rchild);
	}
}

// �������
void inOrder(int root)
{
	if(root == -1){
		return;
	}
	// �ݹ���������� 
	inOrder(node[root].lchild);
	// ���ʸ���� 
	print(root);
	// ����������
	inOrder(node[root].rchild); 
}

int strToNum(char c)
{
	if(c == '-') return -1;
	else{
		notRoot[c-'0'] = true;	// ���c���Ǹ����
		return c - '0'; 
	}
}

int findRoot()
{
	for(int i = 0; i < n; i++){
		// i �Ǹ���� 
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
		getchar();	//���ջ��з� 
		scanf("%c %c", &lchild, &rchild);
		node[i].lchild = strToNum(lchild);
		node[i].rchild = strToNum(rchild);
	}
	int root = findRoot();	//��ȡ������� 
	// ��ת������ 
	postOrder(root);	// �������±�Ϊ 0 
	layerOrder(root);	// ������� 
	num = 0;
	inOrder(root);		// ������� 
	return 0;
}
