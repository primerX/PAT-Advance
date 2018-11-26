#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1111;	// 最大顶点数
vector<int> G[MAXN];	// 邻接表
int father[MAXN];		// 存放父亲结点
bool vis[MAXN];			// 记录结点是否已被访问

// 查找 x 所在集合的根结点， 并进行路径压缩 
int findFather(int x)
{
	int a = x;
	while(x != father[x])
	{
		x = father[x];
	}
	// 路径压缩
	while(a != father[a])
	{
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

// 合并 a 和 b 所在的集合 
void Union(int a, int b)
{
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB)
	{
		father[faA] = faB;
	}
}

// 初始化 father 数组和 vis数组 
void init()
{
	for(int i = 0; i < MAXN; i++)
	{
		father[i] = i;
		vis[i] = false;
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
		// 输入两个顶点 
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int currentPoint;	// 当前需要删除的顶点编号
	for(int query = 0; query < k; k++)
	{
		scanf("%d", &currentPoint);
		init();		// 初始化 father 数组与 vis 数组
		// 枚举每个顶点 
		for(int i = 1; i <= n; i++)
		{
			// 枚举每个顶点边 
			for(int j = 1; j < G[i].size(); j++)
			{
				// 边的两个端点 u, v 
				int u = i, v = G[i][j];
				if(u == currentPoint || v == currentPoint) continue;
				Union(u, v);	// 合并 u 和 v 所在的集合 
			}
		}
		int block = 0;		// 连通块个数
		// 遍历所有结点 
		for(int i = 1; i <= n; i++)
		{
			// 顶点 i 所在连通块的根结点为 fa_i 
			int fa_i = father[i];
			// 如果当前连通块的根结点未被访问 
			if(vis[fa_i] == false)
			{
				block++;	// 连通块个数加 1
				vis[fa_i] = true; 
			}
		}
		// 输出当前连通块个数减 1,即需要增加的边数 
		printf("%d\n", block - 1); 
	}
	return 0;
}
