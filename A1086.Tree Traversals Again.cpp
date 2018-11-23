#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

const int MAXN = 30;	//�������� 

struct node{	// ����������Ľ�� 
	int data;
	node *lchild, *rchild;
};

// ���������������У��������� 
int n, preOrder[MAXN], inOrder[MAXN];

// ������������[preL, preR]����������[inL, inR]
// ����һ�Ŷ��������ú������ظ�����ַ
node* create(int preL, int preR, int inL, int inR)
{
	if(preL > preR) return NULL;	// �ݹ�߽�
	// �½�һ������� 
	node *root = new node; 
	root->data = preOrder[preL];
	root->lchild = root->rchild = NULL;
	int k;
	// �� k ���洢�������±� 
	for(k = inL; k <= inR; k++){
		if(inOrder[k] == preOrder[preL]) break;
	}
	// �������Ľ�����
	int numLeft = k - inL;
	// �ݹ鴴�������� 
	root->lchild = create(preL+1, preL+numLeft, inL, k-1);
	// �ݹ鴴��������
	root->rchild = create(preL+numLeft+1, preR, k+1, inR);
	// ���ظ�����ַ
	return root; 
}

// �������
int num = 0;		// �������������ʽ 
void postOrder(node *root)
{
	if(root == NULL){ // ��Ϊ�� 
		return;
	}
	// ���������� 
	postOrder(root->lchild);
	// ����������
	postOrder(root->rchild);
	// ���ʸ����
	printf("%d", root->data);
	num++;
	if(num < n) printf(" ");
}

int main()
{
	scanf("%d", &n);
	char str[5];
	stack<int> st;
	// ��ջԪ�أ���������λ�ã���������λ�� 
	int x = 0, preIndex = 0, inIndex = 0;
	for(int i = 0; i < 2*n; i++){
		scanf("%s", &str);
		if(strcmp(str, "Push") == 0){	//��ջ
			scanf("%d", &x);
			st.push(x);
			preOrder[preIndex++] = x; 
		}else{		// ��ջ
			inOrder[inIndex++] = st.top();
			st.pop(); 
		}
	}
	node *root = create(0, n-1, 0, n-1); // ���� 
	postOrder(root);	// ������� 
	return 0;
}
