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

int pre[MAXN], in[MAXN], post[MAXN];	//�������򣬺���
int n;		// ������ 
 
// ��ǰ����������������Ϊ[preL, preR], ������������Ϊ[inL, inR]
// ���ص��Ƕ������ĸ����ĵ�ַ
node* create(int preL, int preR, int inL, int inR)
{
	if(preL > preR){
		return NULL;	//�������г��� <= 0ʱ��ֱ�ӷ��� 
	}
	node* root = new node;		//�½�һ���µĽ��
	root->data = pre[preL];
	int k;
	for(k = inL; k <= inR; k++){
		//�������������ҵ�������λ�� 
		if(in[k] == pre[preL]) break;
	}
	int numLeft = k - inL;		//�������Ľ�����
	root->lchild = create(preL+1, preL+numLeft, inL, k-1);
	root->rchild = create(preL+numLeft+1, preR, k+1, inR);
	return root;	//���ظ����ĵ�ַ 
 } 
 
int num = 0;	//�Ѿ�����Ľ�����, �������������ʽ
void postorder(node* root)	//������� 
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
	int x, preIndex = 0, inIndex = 0;	//��ջԪ�أ���������λ�ú���������λ�� 
	for(int i = 0; i < 2*n; i++){	// ��ջ��ջ�� 2*n �� 
		cin >> str;
		if(str == "Push"){		//��ջ
			scanf("%d", &x);
			pre[preIndex++] = x;
			st.push(x); 
		}else{			//��ջ 
			in[inIndex++] = st.top();
			st.pop(); 
		}
	}
	node* root = create(0, n-1, 0, n-1);	//����
	postorder(root);		//������� 
	return 0;
}
