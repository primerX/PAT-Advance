#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 100010;		//���������� 
const int TABLE = 100000;		//���� key �����ֵ 

struct Node{		//���徲̬���� 
	int address, key, next;
	int order;		//����˳�� 
}node[MAXN];

bool isExist[TABLE];		//�ж� key �ľ���ֵ�Ƿ���� 

bool cmp(Node a, Node b)
{
	return a.order < b.order;	//order �Ӵ�С���� 
} 

int main()
{
	fill(isExist, isExist + TABLE, false);	//��ʼ���������ֶ�û�г��� 
	for(int i = 0; i < MAXN; i++){
		node[i].order = 2 * MAXN;		//��ʼ�����н��ȫ����Ч 
	}
	int begin, n;
	cin >> begin >> n;
	int address, key, next;
	for(int i = 0; i < n; i++){
		cin >> address;
		cin >> node[address].key >> node[address].next;
		node[address].address = address;
	}
	//��Ч���������Ƴ��Ľ����� 
	int p = begin, validCnt = 0, removeCnt = 0;
	while(p != -1)
	{
		if(!isExist[abs(node[p].key)]){		//key �ľ���ֵ������ 
			isExist[abs(node[p].key)] = true;	//��Ǵ���
			node[p].order = validCnt++;		//��Ŵ� 0 ��ʼ 
		}else{			//key �ľ���ֵ�Ѿ����ֹ� 
			node[p].order = MAXN + removeCnt++;	//���ý��洢�������±�Ϊ MAXN�� 
		}
		p = node[p].next;
	}
	sort(node, node + MAXN, cmp);	//��order ��С��������
	int count = validCnt + removeCnt;	//Ҫ����ĸ��� 
	for(int i = 0; i < count; i++){
		if(i != validCnt-1 && i != count-1){	//�������һ����� 
			printf("%05d %d %05d\n", node[i].address, node[i].key, node[i+1].address);
		}else{
			printf("%05d %d -1\n", node[i].address, node[i].key);
		}
	} 
	return 0;
}
