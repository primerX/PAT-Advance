#include<iostream>
#include<vector>
using namespace std;

struct node{
	int data;	//������
	node *left, *right;	//ָ���� 
};

void insert(node* &root, int x)
{
	if(root == NULL){	//Ҫ�����λ�� 
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

void preOrder(node *root, vector<int> &vi)	//�������, ������� vi �� 
{
	if(root == NULL) return;
	vi.push_back(root->data);
	preOrder(root->left, vi);
	preOrder(root->right, vi);
}

// ���������������, ������� vi �� 
void preOrderMirror(node *root, vector<int> &vi)
{
	if(root == NULL) return;
	vi.push_back(root->data);
	preOrderMirror(root->right, vi);
	preOrderMirror(root->left, vi);
}

// ����������������� vi ��
void postOrder(node *root, vector<int> &vi)
{
	if(root == NULL) return;
	postOrder(root->left, vi);
	postOrder(root->right, vi);
	vi.push_back(root->data);
}

// ������ĺ���������������� vi ��
void postOrderMirror(node* root, vector<int> &vi)
{
	if(root == NULL) return;
	postOrderMirror(root->right, vi);
	postOrderMirror(root->left, vi);
	vi.push_back(root->data);
}

// origin Ϊ��ʼ���У�pre, post Ϊ���򣬺��� preM, postM Ϊ������������� 
vector<int> origin, pre, post, preM, postM;
int main()
{
	int n, data;
	node* root = NULL;	// �������� 
	scanf("%d", &n);	//������
	for(int i = 0; i < n; i++){
		scanf("%d", &data);
		origin.push_back(data);
		insert(root, data);		// �������������� 
	}
	preOrder(root, pre);			//����������
	preOrderMirror(root, preM);		//����������������
	postOrder(root, post);			//���������
	postOrderMirror(root, postM);	//�������ĺ�������
	if(origin == pre){		//��ʼ���е����������� 
		printf("YES\n");
		for(int i = 0; i < post.size(); i++){
			printf("%d", post[i]);
			if(i < post.size() - 1) printf(" ");
		}
	}else if(origin == preM){	//��ʼ���е��ھ��������������� 
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
