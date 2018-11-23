#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;	// 最大结点数量 
// child[i] 里面盛放 i 的孩子结点 
vector<int> child[MAXN];
// 用来记录每层的结点个数 
int hashTable[MAXN] = {0};


void DFS(int index, int depth)
{
	hashTable[depth]++;	// 改层的个数加 1 
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
		// 父亲结点编号, 孩子结点个数 
		scanf("%d %d", &parent, &k);
		for(int j = 0; j < k; j++){
			scanf("%d", &kid);
			child[parent].push_back(kid);
		}
	}
	DFS(1, 1);	// 初始入口
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
