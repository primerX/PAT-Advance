#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

const int MAXN = 100010;

struct Node{	//���ľ�̬��ʾ
	int data;
	vector<int> child; 
}node[MAXN];

int n;
double p, r, ans = 0;	// ans ������¼���յĽ�� 

void BFS(int root, int depth)		//���������Ϊ 0 
{
	if(node[root].child.size() == 0){	//�˽ڵ���Ҷ�ӽ��
		ans += node[root].data * pow(1 + r, depth); 
		return;
	}
	//�����˽���ÿһ������ 
	for(int i = 0; i < node[root].child.size(); i++){
		BFS(node[root].child[i], depth + 1);
	}
}
int main()
{	
	int k, child;
	scanf("%d %lf %lf", &n, &p, &r);
	r /= 100;
	for(int i = 0; i < n; i++){
		scanf("%d", &k);
		if(k == 0){		//Ҷ�ӽ��ı�־
			scanf("%d", &child);
			node[i].data = child; 
		}else{
			for(int j = 0; j < k; j++){
				scanf("%d", &child);
				node[i].child.push_back(child);
			}
		}
	}
	BFS(0, 0);		//��ʼʱ��������ĵ�ַ�����
	printf("%.1lf", p * ans); 
	return 0;
}
