#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int MAXN = 1010;

struct Mouse{
	int order, weight;		//����,���� 
}mouse[MAXN];

int main()
{
	int np, ng;
	cin >> np >> ng;
	for(int i = 0; i < np; i++){	//ÿֻ��������� 
		cin >> mouse[i].weight; 
	}
	int order;		//˳��
	queue<int> q;	//���� q �����������˳�� 
	for(int i = 0; i < np; i++){
		cin >> order;
		q.push(order); 
	}
	int temp = np;
	int group;		//ÿһ��ĸ���
	while(q.size() != 1)
	{
		if(temp % ng == 0) group = temp / ng;
		else group = temp / ng + 1;
		for(int i = 0; i < group; i++){		//ö��ÿһ�� 
			int k = q.front(); 				// k ������Ÿ����������������ı�� 
			for(int j = 0; j < ng; j++){	//ö��ÿһ��Ĳ����� 
				// �����һ������������ ng ʱ�����ã��˳�ѭ��
				if(i * ng + j >= temp) break; 
				int first = q.front();
				mouse[first].order = group + 1;
				q.pop();
				if(mouse[first].weight > mouse[k].weight){
					k = first;
				}
			}
			q.push(k);
		}
		temp = group;		//һ�ֱ��������󣬸����ܱ�������	
	}
	int first = q.front();
	mouse[first].order = 1;
	for(int i = 0; i < np; i++){
		printf("%d", mouse[i].order);
		if(i < np-1) printf(" ");
	}
	return 0;
}
