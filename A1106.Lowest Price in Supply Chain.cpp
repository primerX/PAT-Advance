#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

const int MAXN = 100010;

//树的静态写法, node[i] 用来存放 i 的所有子结点的编号 
vector<int> node[MAXN];		

//n 为结点个数，num 为价格最低的叶子结点的个数
int n = 0, num = 0; 	 
double p = 0.0, r = 0.0, ans = 1e12;		//ans 为最低叶子价格

void DFS(int index, int depth)
{
	if(node[index].size() == 0){		//此节点是叶子节点
		double price = p * pow(1 + r, depth);	//当前价格
		if(price < ans){
			ans = price;		//更新最低价格
			num = 1;			//更新最低叶子结点的个数 
		}else if(price == ans){
			num++;
		}
		return;
	}
	for(int i = 0; i < node[index].size(); i++){
		DFS(node[index][i], depth + 1);		//递归访问 index 的子结点 
	}
}

int main()
{
	int k, child;
	scanf("%d %lf %lf", &n, &p, &r);
	r /= 100;
	for(int i = 0; i < n; i++){
		scanf("%d", &k);
		if(k != 0){
			for(int j = 0; j < k; j++){
				scanf("%d", &child);
				node[i].push_back(child);	//child 为 i 的子结点 
			}
		}
	}
	DFS(0, 0);	//根结点的地址 0，深度 0
	printf("%.4f %d", ans, num); 
	return 0;
 } 
