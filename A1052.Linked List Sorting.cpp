#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 100010;

struct Node{		//定义静态链表 
	int address, key, next;
	bool flag;		// flag 用来判断结点是否有效 
}node[MAXN];

bool cmp(Node a, Node b)
{
	if(a.flag == false || b.flag == false){
		return a.flag > b.flag;		//只要是无效结点，就放到数组后面去 
	}else{
		return a.key < b.key;		//值从小到大排序 
	}
}

int main()
{
	for(int i = 0; i < MAXN; i++){
		node[i].flag = false;	//初始化，所有结点全部无效 
	}
	int n, begin;
	cin >> n >> begin;
	int address, key, next; 
	for(int i = 0; i < n; i++){
		cin >> address;
		cin >> node[address].key >> node[address].next;
		node[address].address = address; 
	}
	int p = begin, count = 0;	//count 用来记录有效结点的个数
	while(p != -1){
		node[p].flag = true;	//将该结点设置为有效 
		p = node[p].next;
		count++;
	}
	sort(node, node + MAXN, cmp);
	if(count == 0){		//结点个数为0 时，特判 
		printf("0 -1\n");
	}else{
		printf("%d %05d\n", count, node[0].address);
		for(int i = 0; i < count; i++){
			if(i < count-1){
				printf("%05d %d %05d\n", node[i].address, node[i].key, node[i+1].address);
			}else{			//最后一个结点 
				printf("%05d %d -1\n", node[i].address, node[i].key);
			}
		}
	}
	return 0;
 } 
