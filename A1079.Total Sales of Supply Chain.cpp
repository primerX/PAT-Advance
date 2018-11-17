#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

const int MAXN = 100010;

struct Node{	//数的静态表示
	int data;
	vector<int> child; 
}node[MAXN];

int n;
double p, r, ans = 0;	// ans 用来记录最终的结果 

void BFS(int root, int depth)		//根结点的深度为 0 
{
	if(node[root].child.size() == 0){	//此节点是叶子结点
		ans += node[root].data * pow(1 + r, depth); 
		return;
	}
	//遍历此结点的每一个孩子 
	for(int i = 0; i < node[root].child.size(); i++){
		BFS(node[root].child[i], depth + 1);
	}
}
int main()
{	
	int k, child;
	scanf("%d %lf %lf", &n, &p, &r);
	r /= 100;
	for(int i = 0; i < n; i++){
		scanf("%d", &k);
		if(k == 0){		//叶子结点的标志
			scanf("%d", &child);
			node[i].data = child; 
		}else{
			for(int j = 0; j < k; j++){
				scanf("%d", &child);
				node[i].child.push_back(child);
			}
		}
	}
	BFS(0, 0);		//初始时放入根结点的地址和深度
	printf("%.1lf", p * ans); 
	return 0;
}
