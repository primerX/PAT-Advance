#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 100010;

struct Node{		//���徲̬���� 
	int address, key, next;
	bool flag;		// flag �����жϽ���Ƿ���Ч 
}node[MAXN];

bool cmp(Node a, Node b)
{
	if(a.flag == false || b.flag == false){
		return a.flag > b.flag;		//ֻҪ����Ч��㣬�ͷŵ��������ȥ 
	}else{
		return a.key < b.key;		//ֵ��С�������� 
	}
}

int main()
{
	for(int i = 0; i < MAXN; i++){
		node[i].flag = false;	//��ʼ�������н��ȫ����Ч 
	}
	int n, begin;
	cin >> n >> begin;
	int address, key, next; 
	for(int i = 0; i < n; i++){
		cin >> address;
		cin >> node[address].key >> node[address].next;
		node[address].address = address; 
	}
	int p = begin, count = 0;	//count ������¼��Ч���ĸ���
	while(p != -1){
		node[p].flag = true;	//���ý������Ϊ��Ч 
		p = node[p].next;
		count++;
	}
	sort(node, node + MAXN, cmp);
	if(count == 0){		//������Ϊ0 ʱ������ 
		printf("0 -1\n");
	}else{
		printf("%d %05d\n", count, node[0].address);
		for(int i = 0; i < count; i++){
			if(i < count-1){
				printf("%05d %d %05d\n", node[i].address, node[i].key, node[i+1].address);
			}else{			//���һ����� 
				printf("%05d %d -1\n", node[i].address, node[i].key);
			}
		}
	}
	return 0;
 } 
