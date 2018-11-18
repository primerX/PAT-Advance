#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN = 100;
vector<int> G[MAXN];	//��������� 
int leaf[MAXN] = {0};		// �������ÿ���Ҷ�ӽ�����
int max_depth = 1;			//�������

void DFS(int index, int depth)
{
	max_depth = max(depth, max_depth);
	if(G[index].size() == 0){	//�ý��ΪҶ�ӽ��
		leaf[depth]++;		//�ò��Ҷ�ӽ������ 1
		return; 
	}
	for(int i = 0; i < G[index].size(); i++){
		DFS(G[index][i], depth + 1);
	}
}

int main()
{
	int n, m, parent, child, k;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &parent, &k);	//���ڵ��ţ��ӽ�����
		for(int j = 0; j < k; j++){
			scanf("%d", &child);
			G[parent].push_back(child);
		} 
	}
	DFS(1, 1);		//��ʼʱ�������Ϊ1 ���Ϊ 1
	printf("%d", leaf[1]);
	for(int i = 2; i <= max_depth; i++){
		printf(" %d", leaf[i]);
	} 
	return 0;
}
