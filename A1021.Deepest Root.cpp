#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100000;	// 最大结点数
vector<int> G[MAXN];		// 邻接表
// 记录每个节点是否作为某个集合的根结点 
bool isRoot[MAXN]; 
int father[MAXN];

// 查找 x 所在集合的根结点 
int findFather(int x)
{
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

// 合并 a 和 b 的集合 
void Union(int a, int b)
{
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[faA] = faB;
	}
}

// 并查集初始化 
void init(int n)
{
	for(int i = 1; i <= n; i++){
		father[i] = i;
	}
}

// 计算连通块的个数 
int calBlock(int n)
{
	int block = 0;
	for(int i = 1; i <= n; i++)
	{ 
		isRoot[findFather(i)] = true;
	}
	for(int i = 1; i <= n; i++)
	{
		block += isRoot[i];	// 累加根结点个数 
	}
	return block;
}

int maxH = 0;	// 最大高度
// temp 存放临时 DFS 的最远结点结果，ans 保存答案 
vector<int> temp, ans;

// u 为当前访问结点编号，height 为当前树高，pre 为 u 的父亲结点
void DFS(int u, int height, int pre) 
{
	if(height > maxH){
		temp.clear();	// 清空 temp
		temp.push_back(u);	// 将当前结点 u 加入 temp 中
		maxH = height;		// 更新最大树高 
	}else if(height == maxH){
		temp.push_back(u);
	}
	// 遍历 u 的所有子结点 
	for(int i = 0; i < G[u].size(); i++)
	{
		// 由于邻接表中存放无向图，因此需要跳过回去的边
		if(G[u][i] == pre) continue;
		DFS(G[u][i], height + 1, u);	// 访问该子结点 
	}
}

int main()
{
	int a, b, n;
	scanf("%d", &n);
	init(n);		// 初始化并查集 
	for(int i = 1; i <= n; i++)
	{
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
		Union(a, b);		// 合并 a 和 b 所在的集合 
	}
	int block = calBlock(n);	// 计算集合数目
	if(block != 1){		// 不止一个连通块
		printf("Error: %d components\n", block); 
	} else{
		DFS(1, 1, -1);		// 从 1 号结点开始 DFS，初始高度为 1
		ans = temp;
		DFS(ans[0], 1, -1);	// 从任意一个根结点开始遍历
		for(int i = 0; i < temp.size(); i++){
			// 此时 temp 集合为 B，将其加入到 ans 中 
			ans.push_back(temp[i]);	 
		}
		sort(ans.begin(), ans.end());	//按编号从小到大排序
		printf("%d\n", ans[0]);
		for(int i = 1; i < ans.size(); i++)
		{
			// 重复编号不输出 
			if(ans[i] != ans[i-1]){
				printf("%d\n", ans[i]);
			}
		} 
	}
	return 0;
}
