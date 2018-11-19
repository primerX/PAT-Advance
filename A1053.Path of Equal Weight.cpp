#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN = 110;

struct Node{	//���ľ�̬��ʾ
	int weight;
	vector<int> child;	//�������ӽ����±� 
}node[MAXN];

int path[MAXN] = {0};	//path[i] ��ʾ·���ϵ� i �����ı�� 
int n = 0, m = 0, s = 0;

bool cmp(int a, int b)
{
	return node[a].weight > node[a].weight;
}

// ��ǰ���Ϊ index, numNode Ϊ��ǰ·���ϵĽ�����
// sum Ϊ��ǰ·���ĵ�Ȩ֮�� 
void DFS(int index, int numNode, int sum)
{
	if(sum > s) return;
	if(sum == s){		 
		if(node[index].child.size() != 0){		//�˽ڵ㲻��Ҷ���
			return; 
		}
		// ����Ҷ�ӽ�㣬path[] �д����һ������·�� 
		for(int i = 0; i < numNode; i++){
			printf("%d", node[path[i]].weight);
			if(i < numNode - 1) printf(" ");
			else printf("\n");
		}
		return;
	}
	for(int i = 0; i < node[index].child.size(); i++){
		int child = node[index].child[i];
		path[numNode++] = child;
		DFS(child, numNode+1, sum+node[child].weight);
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &s);
	for(int i = 0; i < n; i++){
		scanf("%d", &node[i].weight);
	}
	int id, k, child;
	for(int i = 0; i < m; i++){
		scanf("%d %d", &id, &k);		//����ţ����ӽ��ĸ���
		for(int j = 0; j < k; j++){
			scanf("%d", &child);
			node[id].child.push_back(child);	// child Ϊ id �ĺ��ӽ�� 
		}
		// ��ÿ�������ӽ�㰴Ȩ�شӴ�С��Ϸ 
		sort(node[id].child.begin(), node[id].child.end(), cmp);
	}
	path[0] = 0;	//·���ĵ�һ�������Ϊ 0��Ϊ�����
	DFS(0, 1, node[0].weight);	// ��ʼ���	 
	return 0;
}
