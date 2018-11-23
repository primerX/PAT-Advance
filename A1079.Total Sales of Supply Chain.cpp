#include <iostream>
#include <vector> 
#include <cmath>
using namespace std;

const int MAXN = 100000;	//最多结点个数 

struct Node{
	int data;		// 数据域 
	vector<int> child;	//指针域 
}node[MAXN];

int n;
double price, r, ans = 0;	// ans 为叶子结点货物的价格之和 

void DFS(int index, int depth)
{
	if(node[index].child.size() == 0){	// 该结点为叶子结点 
		ans += node[index].data * pow(r+1, depth);
	}
	for(int i = 0; i < node[index].child.size(); i++){
		// 递归访问孩子结点 
		DFS(node[index].child[i], depth + 1);
	}
}

int main()
{
	int k, child;
	scanf("%d %lf %lf", &n, &price, &r);
	r /= 100;
	for(int i = 0; i <n ; i++){
		scanf("%d", &k);
		if(k == 0){		// 该结点是叶子结点 
			// 叶节点货物量 
			scanf("%d", &node[i].data);
		}else{
			for(int j = 0; j < k; j++){
				scanf("%d", &child);
				node[i].child.push_back(child);
			}	
		}
	}
	DFS(0, 0);	// 入口
	printf("%.1f", ans * price);	// 输出结果 
	return 0;
} 
