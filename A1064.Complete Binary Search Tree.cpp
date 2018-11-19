#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 1000;

// n Ϊ�������number ������Ž���Ȩֵ��CBT���������ȫ������
// index ��С����ö�� number ����
int n, number[MAXN], CBT[MAXN], index = 0;
void inOrder(int root)		//������� 
{
	if(root > n) return;	//�սڵ㣬ֱ�ӷ���
	inOrder(root * 2);		// ���������ݹ�
	CBT[root] = number[index++];	//����㴦��ֵ number[index]
	inOrder(root * 2 + 1); 	//���������ݹ� 
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &number[i]);
	}
	sort(number, number + n);	//��С��������
	inOrder(1);		//�����ĵ�ַΪ 1
	for(int i = 1; i <= n; i++){
		printf("%d", CBT[i]);	//CBT ���鱾����ǲ���
		if(i < n) printf(" "); 
	} 
	return 0;
}
