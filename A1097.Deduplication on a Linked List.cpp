#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 100010;		//结点的最大个数 
const int TABLE = 100000;		//定义 key 的最大值 

struct Node{		//定义静态链表 
	int address, key, next;
	int order;		//结点的顺序 
}node[MAXN];

bool isExist[TABLE];		//判断 key 的绝对值是否出现 

bool cmp(Node a, Node b)
{
	return a.order < b.order;	//order 从大到小排序 
} 

int main()
{
	fill(isExist, isExist + TABLE, false);	//初始化所有数字都没有出现 
	for(int i = 0; i < MAXN; i++){
		node[i].order = 2 * MAXN;		//初始化所有结点全部无效 
	}
	int begin, n;
	cin >> begin >> n;
	int address, key, next;
	for(int i = 0; i < n; i++){
		cin >> address;
		cin >> node[address].key >> node[address].next;
		node[address].address = address;
	}
	//有效结点个数，移除的结点个数 
	int p = begin, validCnt = 0, removeCnt = 0;
	while(p != -1)
	{
		if(!isExist[abs(node[p].key)]){		//key 的绝对值不存在 
			isExist[abs(node[p].key)] = true;	//标记存在
			node[p].order = validCnt++;		//编号从 0 开始 
		}else{			//key 的绝对值已经出现过 
			node[p].order = MAXN + removeCnt++;	//将该结点存储到数组下标为 MAXN后 
		}
		p = node[p].next;
	}
	sort(node, node + MAXN, cmp);	//按order 从小到大排序
	int count = validCnt + removeCnt;	//要输出的个数 
	for(int i = 0; i < count; i++){
		if(i != validCnt-1 && i != count-1){	//不是最后一个结点 
			printf("%05d %d %05d\n", node[i].address, node[i].key, node[i+1].address);
		}else{
			printf("%05d %d -1\n", node[i].address, node[i].key);
		}
	} 
	return 0;
}
