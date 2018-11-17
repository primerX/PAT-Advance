#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;
//树的静态写法，node[i] 存放结点 i 的孩子结点编号 
vector<int> node[MAXN];	 
int hashTable[MAXN] = {0};		//用来记录每层的结点个数

void DFS(int index, int level){
	hashTable[level]++;		//第 level 层的结点个数加 1
	for(int i = 0; i < node[index].size(); i++){
		DFS(node[index][i], level + 1);		//递归访问 index 的孩子结点 
	} 
} 
int main()
{
	int n, m, parent, k, child;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &parent, &k);	//父亲结点编号，孩子个数
		for(int j = 0; j < k; j++){
			scanf("%d", &child);
			node[parent].push_back(child);
		}
	}
	DFS(1, 1);		//根结点编号为 1，层次为 1
	int maxlevel = 0, maxCnt = 0;
	for(int i = 0; i < MAXN; i++){		// 计算hashTable 数组的最大值
		if(hashTable[i] > maxCnt){
			maxCnt = hashTable[i];
			maxlevel = i;
		}
	} 
	printf("%d %d", maxCnt, maxlevel);
	return 0;
}
