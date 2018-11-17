#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 100010;
vector<int> tree[MAXN];		//�������Ľṹ 
 
// �������������ȣ������ȵĽ����� 
int n, maxdepth = 0, num = 0;
double p, r;

void DFS(int index, int depth){		//���ĸ�������Ϊ 0
	if(tree[index].size() == 0){	//�ý����Ҷ�ӽڵ�
		if(depth > maxdepth){
			maxdepth = depth;	//���������� 
			num = 1;			//�����ȵĽ�������Ϊ 1 
		}else if(depth == maxdepth){
			num++;
		}
		return;
	}
	for(int i = 0; i < tree[index].size(); i++){
		DFS(tree[index][i], depth + 1);		//�ݹ���� index �ĺ��ӽ�� 
	}
}

int main()
{
	int father, root;
	scanf("%d %lf %lf", &n, &p, &r);
	r /= 100;
	for(int i = 0; i < n; i++){
		scanf("%d", &father);
		if(father != -1){
			tree[father].push_back(i);	
		}else{
			root = i;
		}
	}
	DFS(root, 0);
	double ans = pow(1 + r, maxdepth) * p;
	printf("%.2lf %d", ans, num);
	return 0;
}
