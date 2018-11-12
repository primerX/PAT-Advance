#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 100010;

struct Node{
	int address, data, next, order;		//结点在链表上的顺序，无效结点记为 MAXN	
}node[MAXN];

bool cmp(Node a, Node b){return a.order < b.order;}

int main()
{
	for(int i = 0; i < MAXN; i++){
		node[i].order = MAXN;		//初始化所有结点全部无效 
	}
	int begin, n, k;
	scanf("%d %d %d", &begin, &n, &k);
	int address, data, next;
	for(int i = 0; i < n; i++){
		scanf("%d", &address);
		scanf("%d %d", &node[address].data, &node[address].next);
		node[address].address = address;
	}
	//count 记录有效结点个数, order 记录链表的顺序
	int p = begin, count = 0;		 
	while(p != -1){
		node[p].order = count++;
		p = node[p].next;
	}
	sort(node, node + MAXN, cmp);
	for(int i = 0; i < count / k; i++){		//分成几块 
		for(int j = (i+1) * k - 1; j > i*k; j--){
			printf("%05d %d %05d\n", node[j].address, node[j].data, node[j-1].address);
		}
		//对于每一组的最后一块 
		printf("%05d %d ", node[i*k].address, node[i*k].data);
		if(i < count/k - 1){		//如果不是最后一块 
			printf("%05d\n", node[(i+2)*k - 1].address);
		}else{		//是最后一块 
			if(count % k == 0){		//是最后一块的最右一个
				printf("-1\n"); 
			}else{
				printf("%05d\n", node[(i+1)*k].address);
				for(int j = (i+1)*k; j < count; j++){
					printf("%05d %d ", node[j].address, node[j].data);
					if(j < count - 1){
						printf("%05d\n",node[j].next);
					}else{
						printf("-1\n");
					}
				}
			}
		}
	}
	return 0;
 } 
