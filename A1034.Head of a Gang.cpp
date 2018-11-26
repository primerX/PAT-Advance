#include <iostream>
#include <string>
#include <map>
using namespace std;

const int MAXN = 2000;		// 总人数
const long long INF = 1e10;		// 表示为无穷大

map<int, string> intToString;	// 编号->姓名
map<string, int> stringToInt;	// 姓名->编号
map<string, int> Gang;			// head->人数
// 邻接矩阵 G, 点权 weight 
int G[MAXN][MAXN] = {0}, weight[MAXN] = {0}; 
// 边数，下限 k，总人数 numPerson 
int n, k, numPerson = 0;
// 标记是否被访问 
bool vis[MAXN] = {false};

// DFS 函数访问单个连通块, nowVisit 为当前访问的编号
// head 为头目，numMember 为成员编号，totalValue 为连通块的总边权
void DFS(int nowVisit, int &head, int &numMember, int &totalValue)
{
	numMember++;	//成员人数加 1
	vis[nowVisit] = true;	// 标记 nowVisit 已被访问
	// 如果当前访问结点的点权大于头目的点权，则更新头目 
	if(weight[nowVisit] > weight[head]) 
	{
		head = nowVisit;
	}
	// 枚举所有人 
	for(int i = 0; i < numPerson; i++)
	{
		// 如果从 visit 能到达 i 
		if(G[nowVisit][i] > 0)
		{
			// 连通块的总边权增加该边权 
			totalValue += G[nowVisit][i];
			// 删除这条边，防止回头 
			G[nowVisit][i] = G[i][nowVisit] = 0;
			// 如果 i 未被访问，则递归访问 i 
			if(vis[i] == false)
			{
				DFS(i, head, numMember, totalValue);
			}
		}
	}
}

// DFSTrave 遍历整个图, 获取每个连通块的信息
void DFSTrave()
{
	// 枚举所有人 
	for(int i = 0; i < numPerson; i++)
	{
		// 如果 i 未被访问 
		if(vis[i] == false)
		{
			// 头目，成员数，总边权 
			int head = i, numMember = 0, totalValue = 0;
			// 遍历 i 所在的连通块 
			DFS(i, head, numMember, totalValue);
			// 如果成员数大于 2，且边权大于给定值 k 
			if(numMember > 2 && totalValue > k)
			{
				// head 人数为 numMember
				Gang[intToString[head]] = numMember;
			}
		}
	}
}

// change 函数返回姓名 str 对应的编号
int change(string str)
{
	// 如果 str 已经出现过 
	if(stringToInt.find(str) != stringToInt.end())
	{
		// 返回编号 
		return stringToInt[str];
	}else{
		// str 的编号为 numPerson 
		stringToInt[str] = numPerson;
		// numPerson 对应 str 
		intToString[numPerson] = str;
		return numPerson++;		// 总人数加 1 
	}
}

int main()
{
	int w;
	string str1, str2;
	cin >> n >> k;		// n 为顶点数 
	for(int i = 0; i < n; i++)
	{
		cin >> str1 >> str2 >> w;	// 输出边的两个端点和点权
		int id1 = change(str1);		// 将 str1 转换为编号 id1
		int id2 = change(str2);		// 将 str2 转换为编号 id2
		weight[id1] += w;			// id1 的点权增加 w
		weight[id2] += w;			// id2 的点权增加 w
		G[id1][id2] += w;			// 边 id1->id2 的边权增加 w
		G[id2][id1] += w;			// 边 id2->id1 的边权增加 w 
	}
	DFSTrave();		// 遍历整个图的连通块, 获取 Gang 的信息
	cout << Gang.size() << endl;	// Gang 的个数 
	map<string, int>::iterator it;
	// 遍历 Gang 
	for(it = Gang.begin(); it != Gang.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	} 
	return 0;
}
