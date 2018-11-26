#include <iostream>
#include <string>
#include <map>
using namespace std;

const int MAXN = 2000;		// ������
const long long INF = 1e10;		// ��ʾΪ�����

map<int, string> intToString;	// ���->����
map<string, int> stringToInt;	// ����->���
map<string, int> Gang;			// head->����
// �ڽӾ��� G, ��Ȩ weight 
int G[MAXN][MAXN] = {0}, weight[MAXN] = {0}; 
// ���������� k�������� numPerson 
int n, k, numPerson = 0;
// ����Ƿ񱻷��� 
bool vis[MAXN] = {false};

// DFS �������ʵ�����ͨ��, nowVisit Ϊ��ǰ���ʵı��
// head ΪͷĿ��numMember Ϊ��Ա��ţ�totalValue Ϊ��ͨ����ܱ�Ȩ
void DFS(int nowVisit, int &head, int &numMember, int &totalValue)
{
	numMember++;	//��Ա������ 1
	vis[nowVisit] = true;	// ��� nowVisit �ѱ�����
	// �����ǰ���ʽ��ĵ�Ȩ����ͷĿ�ĵ�Ȩ�������ͷĿ 
	if(weight[nowVisit] > weight[head]) 
	{
		head = nowVisit;
	}
	// ö�������� 
	for(int i = 0; i < numPerson; i++)
	{
		// ����� visit �ܵ��� i 
		if(G[nowVisit][i] > 0)
		{
			// ��ͨ����ܱ�Ȩ���Ӹñ�Ȩ 
			totalValue += G[nowVisit][i];
			// ɾ�������ߣ���ֹ��ͷ 
			G[nowVisit][i] = G[i][nowVisit] = 0;
			// ��� i δ�����ʣ���ݹ���� i 
			if(vis[i] == false)
			{
				DFS(i, head, numMember, totalValue);
			}
		}
	}
}

// DFSTrave ��������ͼ, ��ȡÿ����ͨ�����Ϣ
void DFSTrave()
{
	// ö�������� 
	for(int i = 0; i < numPerson; i++)
	{
		// ��� i δ������ 
		if(vis[i] == false)
		{
			// ͷĿ����Ա�����ܱ�Ȩ 
			int head = i, numMember = 0, totalValue = 0;
			// ���� i ���ڵ���ͨ�� 
			DFS(i, head, numMember, totalValue);
			// �����Ա������ 2���ұ�Ȩ���ڸ���ֵ k 
			if(numMember > 2 && totalValue > k)
			{
				// head ����Ϊ numMember
				Gang[intToString[head]] = numMember;
			}
		}
	}
}

// change ������������ str ��Ӧ�ı��
int change(string str)
{
	// ��� str �Ѿ����ֹ� 
	if(stringToInt.find(str) != stringToInt.end())
	{
		// ���ر�� 
		return stringToInt[str];
	}else{
		// str �ı��Ϊ numPerson 
		stringToInt[str] = numPerson;
		// numPerson ��Ӧ str 
		intToString[numPerson] = str;
		return numPerson++;		// �������� 1 
	}
}

int main()
{
	int w;
	string str1, str2;
	cin >> n >> k;		// n Ϊ������ 
	for(int i = 0; i < n; i++)
	{
		cin >> str1 >> str2 >> w;	// ����ߵ������˵�͵�Ȩ
		int id1 = change(str1);		// �� str1 ת��Ϊ��� id1
		int id2 = change(str2);		// �� str2 ת��Ϊ��� id2
		weight[id1] += w;			// id1 �ĵ�Ȩ���� w
		weight[id2] += w;			// id2 �ĵ�Ȩ���� w
		G[id1][id2] += w;			// �� id1->id2 �ı�Ȩ���� w
		G[id2][id1] += w;			// �� id2->id1 �ı�Ȩ���� w 
	}
	DFSTrave();		// ��������ͼ����ͨ��, ��ȡ Gang ����Ϣ
	cout << Gang.size() << endl;	// Gang �ĸ��� 
	map<string, int>::iterator it;
	// ���� Gang 
	for(it = Gang.begin(); it != Gang.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	} 
	return 0;
}
