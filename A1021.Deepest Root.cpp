#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100000;	// �������
vector<int> G[MAXN];		// �ڽӱ�
// ��¼ÿ���ڵ��Ƿ���Ϊĳ�����ϵĸ���� 
bool isRoot[MAXN]; 
int father[MAXN];

// ���� x ���ڼ��ϵĸ���� 
int findFather(int x)
{
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

// �ϲ� a �� b �ļ��� 
void Union(int a, int b)
{
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[faA] = faB;
	}
}

// ���鼯��ʼ�� 
void init(int n)
{
	for(int i = 1; i <= n; i++){
		father[i] = i;
	}
}

// ������ͨ��ĸ��� 
int calBlock(int n)
{
	int block = 0;
	for(int i = 1; i <= n; i++)
	{ 
		isRoot[findFather(i)] = true;
	}
	for(int i = 1; i <= n; i++)
	{
		block += isRoot[i];	// �ۼӸ������� 
	}
	return block;
}

int maxH = 0;	// ���߶�
// temp �����ʱ DFS ����Զ�������ans ����� 
vector<int> temp, ans;

// u Ϊ��ǰ���ʽ���ţ�height Ϊ��ǰ���ߣ�pre Ϊ u �ĸ��׽��
void DFS(int u, int height, int pre) 
{
	if(height > maxH){
		temp.clear();	// ��� temp
		temp.push_back(u);	// ����ǰ��� u ���� temp ��
		maxH = height;		// ����������� 
	}else if(height == maxH){
		temp.push_back(u);
	}
	// ���� u �������ӽ�� 
	for(int i = 0; i < G[u].size(); i++)
	{
		// �����ڽӱ��д������ͼ�������Ҫ������ȥ�ı�
		if(G[u][i] == pre) continue;
		DFS(G[u][i], height + 1, u);	// ���ʸ��ӽ�� 
	}
}

int main()
{
	int a, b, n;
	scanf("%d", &n);
	init(n);		// ��ʼ�����鼯 
	for(int i = 1; i <= n; i++)
	{
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
		Union(a, b);		// �ϲ� a �� b ���ڵļ��� 
	}
	int block = calBlock(n);	// ���㼯����Ŀ
	if(block != 1){		// ��ֹһ����ͨ��
		printf("Error: %d components\n", block); 
	} else{
		DFS(1, 1, -1);		// �� 1 �Ž�㿪ʼ DFS����ʼ�߶�Ϊ 1
		ans = temp;
		DFS(ans[0], 1, -1);	// ������һ������㿪ʼ����
		for(int i = 0; i < temp.size(); i++){
			// ��ʱ temp ����Ϊ B��������뵽 ans �� 
			ans.push_back(temp[i]);	 
		}
		sort(ans.begin(), ans.end());	//����Ŵ�С��������
		printf("%d\n", ans[0]);
		for(int i = 1; i < ans.size(); i++)
		{
			// �ظ���Ų���� 
			if(ans[i] != ans[i-1]){
				printf("%d\n", ans[i]);
			}
		} 
	}
	return 0;
}
