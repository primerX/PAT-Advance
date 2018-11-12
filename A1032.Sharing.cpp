#include<iostream>
using namespace std;

const int MAXN = 100010;

struct Node{
	int address, next;
	char data;
	bool flag;		//判断此节点是否在一条链表中出现 
}node[MAXN];

int main()
{
	for(int i = 0; i < MAXN; i++){
		node[i].flag = false;		//初始时，所有链表都没有在第一条中出现 
	} 
	int begin1, begin2, n;	//第一条和第二条链表的首结点地址 
	cin >> begin1 >> begin2 >> n;
	int address, next;
	char data;
	for(int i = 0; i < n; i++){
		cin >> address;
		cin >> node[address].data >> node[address].next;
		node[address].address = address;
	}
	int p1 = begin1;
	while(p1 != -1){		//遍历第一条链表，将出现的结点全部标记为 true 
		node[p1].flag = true;
		p1 = node[p1].next;
	}
	int p2 = begin2;
	while(p2 != -1){		//遍历第二条链表
		if(node[p2].flag == true) break;	//如果第二条链表中出现第一条链表中的结点 
		p2 = node[p2].next;
	}
	if(p2 != -1){
		printf("%05d", node[p2].address);
	}else{
		printf("-1");
	}
	return 0;
}
