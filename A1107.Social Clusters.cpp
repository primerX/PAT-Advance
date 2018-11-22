#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int father[N];		//存放父亲结点
int isRoot[N] = {0};	// 记录每个结点是否作为某个集合的根结点
int course[N] = {0};	// course[h] 用来记录任意一个喜欢活动 h 的人的编号

// 查找 x 所在集合的根结点 
// 并且进行路径压缩 
int findFather(int x)
{
	int a = x;
	// 找到 x 的根结点 
	while(x != father[x]){
		x = father[x];
	}
	// 路径压缩 
	while(a != father[a]){
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
	if(faA != faB){
		faA[father] = faB;
	}
}

// 初始化 father[i] 为 i，且 isRoot[i] 为 false 
void init(int n)
{
	for(int i = 1; i <= n; i++){
		father[i] = i;
		isRoot[i] = 0;
	}
}

// 将 isRoot 数组从大到小排序 
bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int n, k, h;
	scanf("%d", &n);		// 人数
	init(n);		// 初始化 
	for(int i = 1; i <= n; i++){
		scanf("%d:", &k);	// 活动个数
		for(int j = 0; j < k; j++){		//对于每个活动 
			scanf("%d", &h);
			if(course[h] == 0){		// 如果此活动 h 第一次有人喜欢 
				course[h] = i;		// 令 i 喜欢该活动 h
			}
			Union(i, findFather(course[h]));	// 合并 
		} 
	}
	for(int i = 1; i <= n; i++){
		isRoot[findFather(i)]++;		// i 的根结点是 findFather(i) 人数加1  
	}
	int ans = 0;		// 记录集合的数目
	for(int i = 1; i <= n; i++){
		if(isRoot[i] != 0){
			ans++;
		}
	} 
	printf("%d\n", ans);	//输出集合数目
	sort(isRoot+1, isRoot+n+1, cmp);	//从大到小排序
	for(int i = 1; i <= ans; i++){
		printf("%d", isRoot[i]);
		if(i < ans) printf(" ");
	} 
}
