#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 100000;
// child[i] 用来存放 i 的孩子结点 
vector<int> child[MAXN];	

// 结点个数，最大深度，最大深度的结点个数 
int n, maxDepth = 0, num = 0;
void DFS(int index, int depth)
{
	if(child[index].size() == 0){	// 该结点为叶子节点
		if(depth > maxDepth){
			maxDepth = depth;
			num = 1;
		}else if(depth == maxDepth){
			num++;
		}
		return;
	}
	for(int i = 0; i < child[index].size(); i++){
		DFS(child[index][i], depth + 1);
	}
}

int main()
{
	double price, r;
	scanf("%d %lf %lf", &n, &price, &r);
	r /= 100;
	int father, root;
	for(int i = 0; i < n; i++){
		scanf("%d", &father);
		if(father != -1){	// 叶子结点 
			child[father].push_back(i);
		}else{
			root = i;
		}
	}
	DFS(root, 0);	//DFS 的入口
	printf("%.2lf %d", price * pow(1+r, maxDepth), num); 
	return 0;
}
