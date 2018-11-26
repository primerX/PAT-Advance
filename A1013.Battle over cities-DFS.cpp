#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 1111;	//�������
vector<int> G[MAXN];	// �ڽӱ�
// ��Ƕ��� i �Ƿ��ѱ����� 
bool vis[MAXN] = {false};

int currentPoint;	// ��ǰ��Ҫɾ���Ķ�����
// dfs(v) �������� v ���ڵ���ͨ��
void dfs(int v)
{
	// ����������ɾ������ v ʱ������ 
	if(v == currentPoint) return;
	// ��Ƕ����ѱ����� 
	vis[v] = true;               
	// ���� v �������ڽӵ� 
	for(int i = 0; i < G[v].size(); i++)
	{
		// ������� G[v][i] δ������ 
		if(vis[G[v][i]] == false)
		{
			dfs(G[v][i]);	// ���ʶ��� G[v][i] 
		}
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
		// ����ߵ��������� 
		scanf("%d %d", &a, &b);
		G[a].push_back(b);		// �� a->b
		G[b].push_back(a);		// �� b->a 
	}
	// k �β�ѯ 
	for(int query = 0; query < k; query++)
	{
		// ������ɾ���Ķ����� 
		scanf("%d", &currentPoint);
		// ��ʼ������ vis Ϊ false
		fill(vis, vis + MAXN, false); 
		int block = 0;		// ��ͨ��ĸ���
		// ö�����ж��� 
		for(int i = 1; i <= n; i++)
		{
			// �������δ��ɾ����δ������ 
			if(i != currentPoint && vis[i] == false)
			{
				dfs(i);		// �������� i ���ڵ���ͨ��
				block++;	// ��ͨ��ĸ����� 1 
			}
		}
		// �����ͨ�������һ����ʾ��Ҫ���ӵı� 
		printf("%d\n", block - 1); 
	}
	return 0;
}
