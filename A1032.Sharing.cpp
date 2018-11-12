#include<iostream>
using namespace std;

const int MAXN = 100010;

struct Node{
	int address, next;
	char data;
	bool flag;		//�жϴ˽ڵ��Ƿ���һ�������г��� 
}node[MAXN];

int main()
{
	for(int i = 0; i < MAXN; i++){
		node[i].flag = false;		//��ʼʱ����������û���ڵ�һ���г��� 
	} 
	int begin1, begin2, n;	//��һ���͵ڶ���������׽���ַ 
	cin >> begin1 >> begin2 >> n;
	int address, next;
	char data;
	for(int i = 0; i < n; i++){
		cin >> address;
		cin >> node[address].data >> node[address].next;
		node[address].address = address;
	}
	int p1 = begin1;
	while(p1 != -1){		//������һ�����������ֵĽ��ȫ�����Ϊ true 
		node[p1].flag = true;
		p1 = node[p1].next;
	}
	int p2 = begin2;
	while(p2 != -1){		//�����ڶ�������
		if(node[p2].flag == true) break;	//����ڶ��������г��ֵ�һ�������еĽ�� 
		p2 = node[p2].next;
	}
	if(p2 != -1){
		printf("%05d", node[p2].address);
	}else{
		printf("-1");
	}
	return 0;
}
