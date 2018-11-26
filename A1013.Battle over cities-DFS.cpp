#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 1111;	//最大结点数
vector<int> G[MAXN];	// 邻接表
// 标记顶点 i 是否已被访问 
bool vis[MAXN] = {false};

int currentPoint;	// 当前需要删除的顶点编号
// dfs(v) 遍历顶点 v 所在的连通块
void dfs(int v)
{
	// 当遍历到已删除顶点 v 时，返回 
	if(v == currentPoint) return;
	// 标记顶点已被访问 
	vis[v] = true;               
	// 遍历 v 的所有邻接点 
	for(int i = 0; i < G[v].size(); i++)
	{
		// 如果顶点 G[v][i] 未被访问 
		if(vis[G[v][i]] == false)
		{
			dfs(G[v][i]);	// 访问顶点 G[v][i] 
		}
	}
}

int main()
{
	int n, m, k;
	// 输入顶点数，边数，查询数 
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < m; i++)
	{
		int a, b;
		// 输入边的两个顶点 
		scanf("%d %d", &a, &b);
		G[a].push_back(b);		// 边 a->b
		G[b].push_back(a);		// 边 b->a 
	}
	// k 次查询 
	for(int query = 0; query < k; query++)
	{
		// 输入欲删除的顶点编号 
		scanf("%d", &currentPoint);
		// 初始化数组 vis 为 false
		fill(vis, vis + MAXN, false); 
		int block = 0;		// 连通块的个数
		// 枚举所有顶点 
		for(int i = 1; i <= n; i++)
		{
			// 如果顶点未被删除且未被访问 
			if(i != currentPoint && vis[i] == false)
			{
				dfs(i);		// 遍历顶点 i 所在的连通块
				block++;	// 连通块的个数加 1 
			}
		}
		// 输出连通块个数减一，表示需要增加的边 
		printf("%d\n", block - 1); 
	}
	return 0;
}
