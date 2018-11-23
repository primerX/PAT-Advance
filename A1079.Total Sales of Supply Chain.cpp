#include <iostream>
#include <vector> 
#include <cmath>
using namespace std;

const int MAXN = 100000;	//�������� 

struct Node{
	int data;		// ������ 
	vector<int> child;	//ָ���� 
}node[MAXN];

int n;
double price, r, ans = 0;	// ans ΪҶ�ӽ�����ļ۸�֮�� 

void DFS(int index, int depth)
{
	if(node[index].child.size() == 0){	// �ý��ΪҶ�ӽ�� 
		ans += node[index].data * pow(r+1, depth);
	}
	for(int i = 0; i < node[index].child.size(); i++){
		// �ݹ���ʺ��ӽ�� 
		DFS(node[index].child[i], depth + 1);
	}
}

int main()
{
	int k, child;
	scanf("%d %lf %lf", &n, &price, &r);
	r /= 100;
	for(int i = 0; i <n ; i++){
		scanf("%d", &k);
		if(k == 0){		// �ý����Ҷ�ӽ�� 
			// Ҷ�ڵ������ 
			scanf("%d", &node[i].data);
		}else{
			for(int j = 0; j < k; j++){
				scanf("%d", &child);
				node[i].child.push_back(child);
			}	
		}
	}
	DFS(0, 0);	// ���
	printf("%.1f", ans * price);	// ������ 
	return 0;
} 
