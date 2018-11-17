#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;
//���ľ�̬д����node[i] ��Ž�� i �ĺ��ӽ���� 
vector<int> node[MAXN];	 
int hashTable[MAXN] = {0};		//������¼ÿ��Ľ�����

void DFS(int index, int level){
	hashTable[level]++;		//�� level ��Ľ������� 1
	for(int i = 0; i < node[index].size(); i++){
		DFS(node[index][i], level + 1);		//�ݹ���� index �ĺ��ӽ�� 
	} 
} 
int main()
{
	int n, m, parent, k, child;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &parent, &k);	//���׽���ţ����Ӹ���
		for(int j = 0; j < k; j++){
			scanf("%d", &child);
			node[parent].push_back(child);
		}
	}
	DFS(1, 1);		//�������Ϊ 1�����Ϊ 1
	int maxlevel = 0, maxCnt = 0;
	for(int i = 0; i < MAXN; i++){		// ����hashTable ��������ֵ
		if(hashTable[i] > maxCnt){
			maxCnt = hashTable[i];
			maxlevel = i;
		}
	} 
	printf("%d %d", maxCnt, maxlevel);
	return 0;
}
