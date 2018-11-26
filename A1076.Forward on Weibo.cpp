#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAXV = 1000;		// 最大结点数
struct Node{
	int id, layer;	// 结点编号，结点层号 
};

// 邻接表形式存储 
vector<Node> Adj[MAXV];
// 判断顶点 i 是否入过队列 
bool inq[MAXV] = {false};

// s 为起始结点，L 为层数上限 
int BFS(int s, int L)
{
	int numForward = 0;		// 转发数
	queue<Node> q;		// BFS 队列
	Node start;			// 定义起始结点
	start.id = s;		// 起始结点编号
	start.layer = 0;	// 起始结点层号为 0
	q.push(start);		// 将起始结点压入队列
	// 起始结点的编号设为已被加入过队列 
	inq[start.id] = true;
	while(!q.empty())
	{
		Node topNode = q.front();	// 取出队首元素
		q.pop();
		int u = topNode.id;		// 队首结点的编号
		// 枚举从 u 出发能到达的所有结点  
		for(int i = 0; i < Adj[u].size(); i++)
		{
			Node next = Adj[u][i];	// 从 u 出发能否到达的结点 next
			// next 的层号等于当前结点层号加 1 
			next.layer = topNode.layer + 1;
			// 如果 next 的编号未被加入过队列, 且 next 的层次不超过上限 L
			if(inq[next.id] == false && next.layer <= L)
			{
				q.push(next);		// 将 next 入队
				inq[next.id] = true;	// next 的编号设为已被加入过队列
				numForward++;		// 转发数加 1 
			}
		} 
	}
	return numForward;	// 返回转发数 
}

int main()
{
	Node user;
	int n, L, numFollow, idFollow;
	scanf("%d %d", &n, &L);		// 结点个数，层数上限
	for(int i = 1; i <= n; i++)
	{
		user.id = i;		// 用户编号为 1
		scanf("%d", &numFollow);	// i 号用户关注的人数
		for(int j = 0; j < numFollow; j++)
		{
			scanf("%d", &idFollow);	// i 号用户关注的用户编号 
			Adj[idFollow].push_back(user);	// 边 idFollow->i 
		} 
	}
	int numQuery, s;
	scanf("%d", &numQuery);	// 查询个数
	for(int i = 0; i < numQuery; i++)
	{
		// inq 数组初始化 
		memset(inq, false, sizeof(inq));
		scanf("%d", &s);	// 起始结点编号
		int numForward = BFS(s, L);	//BFS 返回转发数
		printf("%d\n", numForward);	// 输出转发数 
	 } 
	return 0;
}
