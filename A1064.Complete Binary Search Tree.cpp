#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 1000;

// n 为结点数，number 用来存放结点的权值，CBT用来存放完全二叉树
// index 从小到大枚举 number 数组
int n, number[MAXN], CBT[MAXN], index = 0;
void inOrder(int root)		//中序遍历 
{
	if(root > n) return;	//空节点，直接返回
	inOrder(root * 2);		// 往左子树递归
	CBT[root] = number[index++];	//根结点处赋值 number[index]
	inOrder(root * 2 + 1); 	//往右子树递归 
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &number[i]);
	}
	sort(number, number + n);	//从小到大排序
	inOrder(1);		//根结点的地址为 1
	for(int i = 1; i <= n; i++){
		printf("%d", CBT[i]);	//CBT 数组本身就是层序
		if(i < n) printf(" "); 
	} 
	return 0;
}
