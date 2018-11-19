#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN = 110;

struct Node{	//树的静态表示
	int weight;
	vector<int> child;	//用来孩子结点的下标 
}node[MAXN];

int path[MAXN] = {0};	//path[i] 表示路径上第 i 个结点的编号 
int n = 0, m = 0, s = 0;

bool cmp(int a, int b)
{
	return node[a].weight > node[a].weight;
}

// 当前结点为 index, numNode 为当前路径上的结点个数
// sum 为当前路径的点权之和 
void DFS(int index, int numNode, int sum)
{
	if(sum > s) return;
	if(sum == s){		 
		if(node[index].child.size() != 0){		//此节点不是叶结点
			return; 
		}
		// 到达叶子结点，path[] 中存放了一条完整路径 
		for(int i = 0; i < numNode; i++){
			printf("%d", node[path[i]].weight);
			if(i < numNode - 1) printf(" ");
			else printf("\n");
		}
		return;
	}
	for(int i = 0; i < node[index].child.size(); i++){
		int child = node[index].child[i];
		path[numNode++] = child;
		DFS(child, numNode+1, sum+node[child].weight);
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &s);
	for(int i = 0; i < n; i++){
		scanf("%d", &node[i].weight);
	}
	int id, k, child;
	for(int i = 0; i < m; i++){
		scanf("%d %d", &id, &k);		//结点编号，孩子结点的个数
		for(int j = 0; j < k; j++){
			scanf("%d", &child);
			node[id].child.push_back(child);	// child 为 id 的孩子结点 
		}
		// 对每个结点的子结点按权重从大到小拍戏 
		sort(node[id].child.begin(), node[id].child.end(), cmp);
	}
	path[0] = 0;	//路径的第一个结点编号为 0，为根结点
	DFS(0, 1, node[0].weight);	// 初始入口	 
	return 0;
}
