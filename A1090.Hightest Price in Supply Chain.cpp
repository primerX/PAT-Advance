#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 100010;
vector<int> tree[MAXN];		//定义树的结构 
 
// 结点个数，最大深度，最大深度的结点个数 
int n, maxdepth = 0, num = 0;
double p, r;

void DFS(int index, int depth){		//树的根结点深度为 0
	if(tree[index].size() == 0){	//该结点是叶子节点
		if(depth > maxdepth){
			maxdepth = depth;	//更新最大深度 
			num = 1;			//最大深度的结点个数置为 1 
		}else if(depth == maxdepth){
			num++;
		}
		return;
	}
	for(int i = 0; i < tree[index].size(); i++){
		DFS(tree[index][i], depth + 1);		//递归访问 index 的孩子结点 
	}
}

int main()
{
	int father, root;
	scanf("%d %lf %lf", &n, &p, &r);
	r /= 100;
	for(int i = 0; i < n; i++){
		scanf("%d", &father);
		if(father != -1){
			tree[father].push_back(i);	
		}else{
			root = i;
		}
	}
	DFS(root, 0);
	double ans = pow(1 + r, maxdepth) * p;
	printf("%.2lf %d", ans, num);
	return 0;
}
