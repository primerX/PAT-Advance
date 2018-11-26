#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1111;	// ��󶥵���
vector<int> G[MAXN];	// �ڽӱ�
int father[MAXN];		// ��Ÿ��׽��
bool vis[MAXN];			// ��¼����Ƿ��ѱ�����

// ���� x ���ڼ��ϵĸ���㣬 ������·��ѹ�� 
int findFather(int x)
{
	int a = x;
	while(x != father[x])
	{
		x = father[x];
	}
	// ·��ѹ��
	while(a != father[a])
	{
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
	if(faA != faB)
	{
		father[faA] = faB;
	}
}

// ��ʼ�� father ����� vis���� 
void init()
{
	for(int i = 0; i < MAXN; i++)
	{
		father[i] = i;
		vis[i] = false;
	}
}

int main()
{
	int n, m, k;
	// ���붥��������������ѯ�� 
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < m; i++)
	{
		int a, b;
		// ������������ 
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int currentPoint;	// ��ǰ��Ҫɾ���Ķ�����
	for(int query = 0; query < k; k++)
	{
		scanf("%d", &currentPoint);
		init();		// ��ʼ�� father ������ vis ����
		// ö��ÿ������ 
		for(int i = 1; i <= n; i++)
		{
			// ö��ÿ������� 
			for(int j = 1; j < G[i].size(); j++)
			{
				// �ߵ������˵� u, v 
				int u = i, v = G[i][j];
				if(u == currentPoint || v == currentPoint) continue;
				Union(u, v);	// �ϲ� u �� v ���ڵļ��� 
			}
		}
		int block = 0;		// ��ͨ�����
		// �������н�� 
		for(int i = 1; i <= n; i++)
		{
			// ���� i ������ͨ��ĸ����Ϊ fa_i 
			int fa_i = father[i];
			// �����ǰ��ͨ��ĸ����δ������ 
			if(vis[fa_i] == false)
			{
				block++;	// ��ͨ������� 1
				vis[fa_i] = true; 
			}
		}
		// �����ǰ��ͨ������� 1,����Ҫ���ӵı��� 
		printf("%d\n", block - 1); 
	}
	return 0;
}
