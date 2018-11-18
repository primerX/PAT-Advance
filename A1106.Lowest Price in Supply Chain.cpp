#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

const int MAXN = 100010;

//���ľ�̬д��, node[i] ������� i �������ӽ��ı�� 
vector<int> node[MAXN];		

//n Ϊ��������num Ϊ�۸���͵�Ҷ�ӽ��ĸ���
int n = 0, num = 0; 	 
double p = 0.0, r = 0.0, ans = 1e12;		//ans Ϊ���Ҷ�Ӽ۸�

void DFS(int index, int depth)
{
	if(node[index].size() == 0){		//�˽ڵ���Ҷ�ӽڵ�
		double price = p * pow(1 + r, depth);	//��ǰ�۸�
		if(price < ans){
			ans = price;		//������ͼ۸�
			num = 1;			//�������Ҷ�ӽ��ĸ��� 
		}else if(price == ans){
			num++;
		}
		return;
	}
	for(int i = 0; i < node[index].size(); i++){
		DFS(node[index][i], depth + 1);		//�ݹ���� index ���ӽ�� 
	}
}

int main()
{
	int k, child;
	scanf("%d %lf %lf", &n, &p, &r);
	r /= 100;
	for(int i = 0; i < n; i++){
		scanf("%d", &k);
		if(k != 0){
			for(int j = 0; j < k; j++){
				scanf("%d", &child);
				node[i].push_back(child);	//child Ϊ i ���ӽ�� 
			}
		}
	}
	DFS(0, 0);	//�����ĵ�ַ 0����� 0
	printf("%.4f %d", ans, num); 
	return 0;
 } 
