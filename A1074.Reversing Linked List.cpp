#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 100010;

struct Node{
	int address, data, next, order;		//����������ϵ�˳����Ч����Ϊ MAXN	
}node[MAXN];

bool cmp(Node a, Node b){return a.order < b.order;}

int main()
{
	for(int i = 0; i < MAXN; i++){
		node[i].order = MAXN;		//��ʼ�����н��ȫ����Ч 
	}
	int begin, n, k;
	scanf("%d %d %d", &begin, &n, &k);
	int address, data, next;
	for(int i = 0; i < n; i++){
		scanf("%d", &address);
		scanf("%d %d", &node[address].data, &node[address].next);
		node[address].address = address;
	}
	//count ��¼��Ч������, order ��¼�����˳��
	int p = begin, count = 0;		 
	while(p != -1){
		node[p].order = count++;
		p = node[p].next;
	}
	sort(node, node + MAXN, cmp);
	for(int i = 0; i < count / k; i++){		//�ֳɼ��� 
		for(int j = (i+1) * k - 1; j > i*k; j--){
			printf("%05d %d %05d\n", node[j].address, node[j].data, node[j-1].address);
		}
		//����ÿһ������һ�� 
		printf("%05d %d ", node[i*k].address, node[i*k].data);
		if(i < count/k - 1){		//����������һ�� 
			printf("%05d\n", node[(i+2)*k - 1].address);
		}else{		//�����һ�� 
			if(count % k == 0){		//�����һ�������һ��
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
