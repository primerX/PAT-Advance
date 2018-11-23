#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;	// ��������� 
// child[i] ����ʢ�� i �ĺ��ӽ�� 
vector<int> child[MAXN];
// ������¼ÿ��Ľ����� 
int hashTable[MAXN] = {0};


void DFS(int index, int depth)
{
	hashTable[depth]++;	// �Ĳ�ĸ����� 1 
	for(int i = 0; i < child[index].size(); i++){
		DFS(child[index][i], depth + 1);
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int parent, k, kid;
	for(int i = 0; i < m; i++){
		// ���׽����, ���ӽ����� 
		scanf("%d %d", &parent, &k);
		for(int j = 0; j < k; j++){
			scanf("%d", &kid);
			child[parent].push_back(kid);
		}
	}
	DFS(1, 1);	// ��ʼ���
	int maxLevel = -1, maxNum = 0;
	for(int i = 0; i < MAXN; i++){
		if(hashTable[i] > maxNum){
			maxNum = hashTable[i];
			maxLevel = i;
		}
	} 
	printf("%d %d", maxNum, maxLevel);
	return 0;
}
