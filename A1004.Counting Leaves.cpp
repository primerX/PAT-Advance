#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN = 100;
vector<int> G[MAXN];	//用来存放树 
int leaf[MAXN] = {0};		// 用来存放每层的叶子结点个数
int max_depth = 1;			//树的深度

void DFS(int index, int depth)
{
	max_depth = max(depth, max_depth);
	if(G[index].size() == 0){	//该结点为叶子结点
		leaf[depth]++;		//该层的叶子结点数加 1
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
		scanf("%d %d", &parent, &k);	//父节点编号，子结点个数
		for(int j = 0; j < k; j++){
			scanf("%d", &child);
			G[parent].push_back(child);
		} 
	}
	DFS(1, 1);		//初始时根结点编号为1 深度为 1
	printf("%d", leaf[1]);
	for(int i = 2; i <= max_depth; i++){
		printf(" %d", leaf[i]);
	} 
	return 0;
}
