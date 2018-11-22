#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int father[N];		//��Ÿ��׽��
int isRoot[N] = {0};	// ��¼ÿ������Ƿ���Ϊĳ�����ϵĸ����
int course[N] = {0};	// course[h] ������¼����һ��ϲ��� h ���˵ı��

// ���� x ���ڼ��ϵĸ���� 
// ���ҽ���·��ѹ�� 
int findFather(int x)
{
	int a = x;
	// �ҵ� x �ĸ���� 
	while(x != father[x]){
		x = father[x];
	}
	// ·��ѹ�� 
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

// �ϲ� a �� b ���ڵļ��� 
void Union(int a, int b)
{
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		faA[father] = faB;
	}
}

// ��ʼ�� father[i] Ϊ i���� isRoot[i] Ϊ false 
void init(int n)
{
	for(int i = 1; i <= n; i++){
		father[i] = i;
		isRoot[i] = 0;
	}
}

// �� isRoot ����Ӵ�С���� 
bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int n, k, h;
	scanf("%d", &n);		// ����
	init(n);		// ��ʼ�� 
	for(int i = 1; i <= n; i++){
		scanf("%d:", &k);	// �����
		for(int j = 0; j < k; j++){		//����ÿ��� 
			scanf("%d", &h);
			if(course[h] == 0){		// ����˻ h ��һ������ϲ�� 
				course[h] = i;		// �� i ϲ���û h
			}
			Union(i, findFather(course[h]));	// �ϲ� 
		} 
	}
	for(int i = 1; i <= n; i++){
		isRoot[findFather(i)]++;		// i �ĸ������ findFather(i) ������1  
	}
	int ans = 0;		// ��¼���ϵ���Ŀ
	for(int i = 1; i <= n; i++){
		if(isRoot[i] != 0){
			ans++;
		}
	} 
	printf("%d\n", ans);	//���������Ŀ
	sort(isRoot+1, isRoot+n+1, cmp);	//�Ӵ�С����
	for(int i = 1; i <= ans; i++){
		printf("%d", isRoot[i]);
		if(i < ans) printf(" ");
	} 
}
