#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAXV = 1000;		// �������
struct Node{
	int id, layer;	// ����ţ������ 
};

// �ڽӱ���ʽ�洢 
vector<Node> Adj[MAXV];
// �ж϶��� i �Ƿ�������� 
bool inq[MAXV] = {false};

// s Ϊ��ʼ��㣬L Ϊ�������� 
int BFS(int s, int L)
{
	int numForward = 0;		// ת����
	queue<Node> q;		// BFS ����
	Node start;			// ������ʼ���
	start.id = s;		// ��ʼ�����
	start.layer = 0;	// ��ʼ�����Ϊ 0
	q.push(start);		// ����ʼ���ѹ�����
	// ��ʼ���ı����Ϊ�ѱ���������� 
	inq[start.id] = true;
	while(!q.empty())
	{
		Node topNode = q.front();	// ȡ������Ԫ��
		q.pop();
		int u = topNode.id;		// ���׽��ı��
		// ö�ٴ� u �����ܵ�������н��  
		for(int i = 0; i < Adj[u].size(); i++)
		{
			Node next = Adj[u][i];	// �� u �����ܷ񵽴�Ľ�� next
			// next �Ĳ�ŵ��ڵ�ǰ����ż� 1 
			next.layer = topNode.layer + 1;
			// ��� next �ı��δ�����������, �� next �Ĳ�β��������� L
			if(inq[next.id] == false && next.layer <= L)
			{
				q.push(next);		// �� next ���
				inq[next.id] = true;	// next �ı����Ϊ�ѱ����������
				numForward++;		// ת������ 1 
			}
		} 
	}
	return numForward;	// ����ת���� 
}

int main()
{
	Node user;
	int n, L, numFollow, idFollow;
	scanf("%d %d", &n, &L);		// ����������������
	for(int i = 1; i <= n; i++)
	{
		user.id = i;		// �û����Ϊ 1
		scanf("%d", &numFollow);	// i ���û���ע������
		for(int j = 0; j < numFollow; j++)
		{
			scanf("%d", &idFollow);	// i ���û���ע���û���� 
			Adj[idFollow].push_back(user);	// �� idFollow->i 
		} 
	}
	int numQuery, s;
	scanf("%d", &numQuery);	// ��ѯ����
	for(int i = 0; i < numQuery; i++)
	{
		// inq �����ʼ�� 
		memset(inq, false, sizeof(inq));
		scanf("%d", &s);	// ��ʼ�����
		int numForward = BFS(s, L);	//BFS ����ת����
		printf("%d\n", numForward);	// ���ת���� 
	 } 
	return 0;
}
