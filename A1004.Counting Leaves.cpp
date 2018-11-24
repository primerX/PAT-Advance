#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100;	// ����������� 
//node[i] ʢ�� i �� ���ӽ���� 
vector<int> node[MAXN];	// ��������� 
//hashTable �������ÿһ���Ҷ�ӽڵ���� 
int hashTable[MAXN] = {0};
int high = 1;		// ������¼��ĸ߶�	

void DFS(int index, int depth)
{
	high = max(high, depth);
	if(node[index].size() == 0){	// �ý����Ҷ�ӽ�� 
		hashTable[depth]++;
		return;
	}
	for(int i = 0; i < node[index].size(); i++){
		// �ݹ���� index �ĺ��ӽ�� 
		DFS(node[index][i], depth + 1);
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int father, k, child;
	for(int i = 0; i < m; i++){
		// ���븸�׽����, �ڵ���� 
		scanf("%d %d", &father, &k);
		for(int j = 0; j < k; j++){
			scanf("%d", &child);
			node[father].push_back(child);
		}
	}
	DFS(1, 1);	// ��ʼ���,�������Ϊ 0�����Ϊ 1
	printf("%d", hashTable[1]);	// ������Ŵ� 1 ��ʼ
	for(int i = 2; i <= high; i++){
		printf(" %d", hashTable[i]);
	} 
	return 0;
}
