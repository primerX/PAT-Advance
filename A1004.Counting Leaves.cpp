#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100;	// 结点的最大数量 
//node[i] 盛放 i 的 孩子结点编号 
vector<int> node[MAXN];	// 用来存放树 
//hashTable 用来存放每一层的叶子节点个数 
int hashTable[MAXN] = {0};
int high = 1;		// 用来记录输的高度	

void DFS(int index, int depth)
{
	high = max(high, depth);
	if(node[index].size() == 0){	// 该结点是叶子结点 
		hashTable[depth]++;
		return;
	}
	for(int i = 0; i < node[index].size(); i++){
		// 递归访问 index 的孩子结点 
		DFS(node[index][i], depth + 1);
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int father, k, child;
	for(int i = 0; i < m; i++){
		// 输入父亲结点编号, 节点个数 
		scanf("%d %d", &father, &k);
		for(int j = 0; j < k; j++){
			scanf("%d", &child);
			node[father].push_back(child);
		}
	}
	DFS(1, 1);	// 初始入口,根结点编号为 0，深度为 1
	printf("%d", hashTable[1]);	// 根结点编号从 1 开始
	for(int i = 2; i <= high; i++){
		printf(" %d", hashTable[i]);
	} 
	return 0;
}
